/* ANVÄNDARKOD BÖRJAR Privat definierar */

#define TRYCK PÅ ASSISTENT_NUVARANDE 30
#define SEXSTEGSTRÖSKEL9000

/* Inga gamla hastighets- eller strömdefinitioner här */

typedef struct{
    q31_t Spänning;
    int16_t fastströmsgräns;
    q31_t Batteriström;
    uint8_t hall_angle_detekt_flag;
    uint8_t char_dyn_adc_state;
    uint8_t assist_nivå;
    uint8_t regen_level;
    int8_t Temperatur;
    int8_t läge;
    bool ljus;
    bool pip;
    uint8_t stängning;
    q31_t i_q_börvärde;
    int32_t i_q_börvärde_mål;
    uint32_t hastighet;
    int8_t hastighetsgräns;
} M365State_t;

/* ANVÄNDARKOD SLUT Privat definierar */
