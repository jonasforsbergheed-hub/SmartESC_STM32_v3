#ifndef MOTOR_H_
#define MOTOR_H_

#include <stdint.h>
#include <stdbool.h>

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif


//------------------------------------------------------------
// Motor system states
//------------------------------------------------------------

enum
{
    Stop = 0,
    SixStep,
    Interpolation,
    PLL
};


//------------------------------------------------------------
// Angle estimation
//------------------------------------------------------------

enum angle_estimation
{
    EXTRAPOLATION = 0,
    SPEED_PLL
};


//------------------------------------------------------------
// Error states
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
// Operating modes
//------------------------------------------------------------

#ifndef eco
#define eco 0
#endif

#ifndef normal
#define normal 1
#endif

#ifndef sport
#define sport 2
#endif


//------------------------------------------------------------
// ADC channels
//------------------------------------------------------------

#ifndef ADC_VOLTAGE
#define ADC_VOLTAGE 0
#endif

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
// Motor public state
//------------------------------------------------------------

typedef struct
{
    q31_t i_q_setpoint_target;

    int16_t phase_current_limit;

    q31_t battery_voltage;

    q31_t battery_voltage_min;

    uint16_t field_weakening_current_max;

    int8_t system_state;

    int8_t mode;

    int8_t error_state;

    int8_t speed_limit;

    uint32_t speed;

    bool brake_active;

    bool field_weakening_enable;

    uint16_t adcData[16];

    uint32_t debug[10];

} MotorStatePublic_t;


//------------------------------------------------------------
// Motor internal state
//------------------------------------------------------------

typedef struct
{
    q31_t i_d;

    q31_t i_q;

    q31_t i_q_setpoint;

    q31_t i_d_setpoint;

    q31_t i_setpoint_abs;

    int32_t i_q_setpoint_temp;

    int32_t i_d_setpoint_temp;

    q31_t u_d;

    q31_t u_q;

    q31_t u_abs;

    q31_t Battery_Current;

    uint8_t char_dyn_adc_state;

    int8_t system_state;

    int8_t error_state;

    int16_t spec_angle;

    uint8_t assist_level;

    uint8_t regen_level;

    int16_t phase_current_limit;

    int8_t speed_limit;

    int8_t mode;

    enum angle_estimation angle_estimation;

    bool hall_angle_detect_flag;

} MotorState_t;


//------------------------------------------------------------
// Global motor state
//------------------------------------------------------------

extern MotorState_t MS;


//------------------------------------------------------------
// Motor functions
//------------------------------------------------------------

void motor_init(
    volatile MotorStatePublic_t* motorStatePublic
);

void motor_autodetect(void);

void motor_slow_loop(
    volatile MotorStatePublic_t* p_MotorStatePublic,
    M365State_t* p_M365State
);

int32_t speed_to_tics(uint8_t speed);

int8_t tics_to_speed(uint32_t tics);

void calculate_tic_limits(int8_t speed_limit);

q31_t speed_PLL(q31_t actual, q31_t target);

void get_standstill_position(void);

void runPIcontrol(void);


#ifdef __cplusplus
}
#endif

#endif /* MOTOR_H_ */
