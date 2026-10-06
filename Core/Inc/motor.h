#!/usr/bin/python3
from binascii import hexlify
import struct
import keystone
from xiaotea import XiaoTea

# https://web.eecs.umich.edu/~prabal/teaching/eecs373-f10/readings/ARMv7-M_ARM.pdf
MOVW_T3_IMM = [*[None]*5, 11, *[None]*6, 15, 14, 13, 12, None, 10, 9, 8, *[None]*4, 7, 6, 5, 4, 3, 2, 1, 0]
MOVS_T1_IMM = [*[None]*8, 7, 6, 5, 4, 3, 2, 1, 0]


def PatchImm(data, ofs, size, imm, signature):
    assert size % 2 == 0, 'size must be power of 2!'
    assert len(signature) == size * 8, 'signature must be exactly size * 8 long!'

    imm = int.from_bytes(imm, 'little')
    sfmt = '<' + 'H' * (size // 2)

    sigs = [signature[i:i + 16][::-1] for i in range(0, len(signature), 16)]
    orig = data[ofs:ofs+size]
    words = struct.unpack(sfmt, orig)

    patched = []

    for i, word in enumerate(words):
        for j in range(16):
            imm_bitofs = sigs[i][j]

            if imm_bitofs is None:
                continue

            imm_mask = 1 << imm_bitofs
            word_mask = 1 << j

            if imm & imm_mask:
                word |= word_mask
            else:
                word &= ~word_mask

        patched.append(word)

    packed = struct.pack(sfmt, *patched)
    data[ofs:ofs+size] = packed

    return (orig, packed)


class SignatureException(Exception):
    pass


def FindPattern(data, signature, mask=None, start=None, maxit=None):
    sig_len = len(signature)

    if start is None:
        start = 0

    stop = len(data) - len(signature)

    if maxit is not None:
        stop = start + maxit

    if mask:
        assert sig_len == len(mask), 'mask must be as long as the signature!'

        for i in range(sig_len):
            signature[i] &= mask[i]

    for i in range(start, stop):
        matches = 0

        while signature[matches] is None or signature[matches] == (
            data[i + matches] & (mask[matches] if mask else 0xFF)
        ):
            matches += 1

            if matches == sig_len:
                return i

    raise SignatureException('Pattern not found!')


class FirmwarePatcher():

    def __init__(self, data):
        self.data = bytearray(data)
        self.ks = keystone.Ks(
            keystone.KS_ARCH_ARM,
            keystone.KS_MODE_THUMB
        )

    def encrypt(self):
        cry = XiaoTea()
        self.data = cry.encrypt(self.data)

    def kers_min_speed(self, kmh):
        val = struct.pack('<H', int(kmh * 345))

        sig = [
            0x25, 0x68,
            0x40, 0xF6,
            0x16, 0x07,
            0xBD, 0x42
        ]

        ofs = FindPattern(self.data, sig) + 2

        pre, post = PatchImm(
            self.data,
            ofs,
            4,
            val,
            MOVW_T3_IMM
        )

        return [(ofs, pre, post)]

    def speed_params(
        self,
        normal_kmh,
        normal_phase,
        normal_battery,
        eco_kmh,
        eco_phase,
        eco_battery
    ):
        ret = []

        sig = [
            0x80, 0x28,
            0x00, 0xDD,
            0x80, 0x20,
            *[None]*2,
            0x68, 0x43,
            0x00, 0x0C
        ]

        ofs = FindPattern(self.data, sig) + 8

        pre = self.data[ofs:ofs+4]

        post = bytes(
            self.ks.asm(
                'MOVW R2, #{:n}'.format(normal_battery)
            )[0]
        )

        self.data[ofs:ofs+4] = post
        ret.append([ofs, pre, post])

        ofs += 4

        pre = self.data[ofs:ofs+2]

        post = bytes
