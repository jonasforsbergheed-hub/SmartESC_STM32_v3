/*
 * motor.h
 *
 * SmartESC STM32 V3 / M365
 *
 * Motor state definitions and motor interface.
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <stdint.h>
#include <stdbool.h>

#include "main.h"
#include "config.h"
#include <arm_math.h>


//------------------------------------------------------------
// Motor / speed parameters
//------------------------------------------------------------

#ifndef WHEEL_CIRCUMFERENCE
#define WHEEL_CIRCUMFERENCE 2302
#endif

#ifndef GEAR_RATIO
#define GEAR_RATIO 45
#endif


//------------------------------------------------------------
// ADC
//------------------------------------------------------------

#ifndef ADC_VOLTAGE
#define ADC_VOLTAGE 0
#endif

/*
 * ADC positions used by motor.c.
 *
 * motor.c stores the three phase-current measurements in
 * adcData[] and uses these indexes when calibrating them.
 */
#ifndef ADC_CHANA
#define ADC_CHANA 3
#endif

#ifndef ADC_CHANB
#define ADC_CHANB 4
#endif

#ifndef ADC_CHANC
#define ADC_CHANC 5
#endif


//------------------------------------------------------------
// Motor current / control parameters
//------------------------------------------------------------

#ifndef BATTERYCURRENT_MAX
#define BATTERYCURRENT_MAX 45000
#endif

#ifndef REGEN_CURRENT_MAX
#define REGEN_CURRENT_MAX 5000
#endif

#ifndef MAX_D_FACTOR
#define MAX_D_FACTOR 1
#endif


//------------------------------------------------------------
// Six-step threshold
//------------------------------------------------------------

#ifndef SIXSTEPTHRESHOLD
#define SIXSTEPTHRESHOLD 9000
#endif


//------------------------------------------------------------
// Rotor angle estimation
//------------------------------------------------------------

enum angle_estimation
{
    EXTRAPOLATION = 0,
    SPEED_PLL
};


//------------------------------------------------------------
// Motor system state
//------------------------------------------------------------

enum
{
    Stop = 0,
    SixStep,
    Interpolation,
    PLL
};


//------------------------------------------------------------
// Motor error states
//------------------------------------------------------------

enum errors
{
    none = 0,
    hall = 18,
    lowbattery = 24,
    overcurrent = 4,
    brake = 15
};


//------------------------------------------------------------
// Internal motor state
//------------------------------------------------------------

typedef struct
{
    /*
     * Measured d/q currents
     */
    q31_t i_d;
    q31_t i_q;

    /*
     * Requested d/q currents
     */
    q31_t i_q_setpoint;
    q31_t i_d_setpoint;

    /*
     * Absolute current-vector magnitude
     */
    q31_t i_setpoint_abs;

    /*
     * Temporary current setpoints
     */
    int32_t i_q_setpoint_temp;
    int32_t i_d_setpoint_temp;

    /*
     * d/q voltage output
     */
    q31_t u_d;
    q31_t u_q;
    q31_t u_abs;

    /*
     * Calculated battery current
     */
    q31_t Battery_Current;

    /*
     * Dynamic ADC sampling state
     *
     * 1 = phase C high
     * 2 = phase A high
     * 3 = phase B high
     */
    uint8_t char_dyn_adc_state;

    /*
     * Previous/system motor state
     */
    int8_t system_state;

    /*
     * Motor error state
     */
    int8_t error_state;

    /*
     * Motor-specific Hall angle
     */
    int16_t spec_angle;

    /*
     * Assist / regen levels
     */
    uint8_t assist_level;
    uint8_t regen_level;

    /*
     * Current and speed limits used internally
     */
    int16_t phase_current_limit;
    int8_t speed_limit;

    /*
     * Motor operating mode
     */
    int8_t mode;

    /*
     * Angle estimation method
     */
    enum angle_estimation angle_estimation;

    /*
     * Hall angle detection / autodetect state
     *
     * 1 = normal Hall operation
     * 0 = autodetection/open-loop
     */
    uint8_t hall_angle_detect_flag;

} MotorState_t;


//------------------------------------------------------------
// Global motor state
//------------------------------------------------------------

extern MotorState_t MS;


//------------------------------------------------------------
// Motor functions
//------------------------------------------------------------

void motor_init(volatile MotorStatePublic_t* motorStatePublic);

void motor_autodetect(void);

void motor_slow_loop(
    volatile MotorStatePublic_t* p_MotorStatePublic,
    M365State_t* p_M365State
);

void motor_disable_pwm(void);


//------------------------------------------------------------
// Speed / rotor functions
//------------------------------------------------------------

int32_t speed_to_tics(uint8_t speed);

int8_t tics_to_speed(uint32_t tics);

void calculate_tic_limits(int8_t speed_limit);

q31_t speed_PLL(q31_t actual, q31_t target);

void get_standstill_position(void);


//------------------------------------------------------------
// Motor control
//------------------------------------------------------------

void runPIcontrol(void);


//------------------------------------------------------------
// C++ compatibility
//------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif /* MOTOR_H_ */
