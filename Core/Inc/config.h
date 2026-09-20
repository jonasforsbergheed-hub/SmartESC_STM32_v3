/*
 * config.h
 *
 *  Automatically SmartESC_STM32_v3 som ZIP här. by Lishui Parameter Configurator
 *  Author: stancecoke
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#include "stdint.h"

//Dangerzone, do not touch!!
#define DISPLAY_TYPE_M365DASHBOARD (1<<1)
#define DISPLAY_TYPE_DEBUG (1<<0)

// Throttle / input
#define TRIGGER_OFFSET_ADC 50
#define TRIGGER_DEFAULT 2020
#define _T 2028
#define SPEEDFILTER 3

//#define ADCTHROTTLE
//#define FAST_LOOP_LOG
//#define DISABLE_DYNAMIC_ADC

// Display
#define DISPLAY_TYPE DISPLAY_TYPE_M365DASHBOARD

// Calibration factors for voltage and current
#define CAL_BAT_V 14
#define CAL_I 38

// PI controls
#define P_FACTOR_I_Q 100
#define I_FACTOR_I_Q 2
#define P_FACTOR_I_D 100
#define I_FACTOR_I_D 10

// Throttle and brake
#define THROTTLEOFFSET 45
#define THROTTLEMAX 175
#define BRAKEOFFSET 50
#define BRAKEMAX 190

// Speed calculation
#define WHEEL_CIRCUMFERENCE 2302
#define GEAR_RATIO 45

// Speed limits
#define SPEEDLIMIT_ECO 20
#define SPEEDLIMIT_NORMAL 35
#define SPEEDLIMIT_SPORT 55

// Motor current limits
#define PH_CURRENT_MAX_ECO 15000
#define PH_CURRENT_MAX_NORMAL 25000
#define PH_CURRENT_MAX_SPORT 35000

// Regen
#define REGEN_CURRENT 1000
#define REGEN_CURRENT_MAX 10000

// Field weakening
#define FW_CURRENT_MAX 0

// Maximum battery current
#define BATTERYCURRENT_MAX 35000

// Battery voltage limits
#define BATTERYVOLTAGE_MIN 33000
#define BATTERYVOLTAGE_MAX 54600

// Motor spinning direction
#define REVERSE -1

// Speed PLL
#define SPEED_PLL 0
#define P_FACTOR_PLL 10
#define I_FACTOR_PLL 10

#endif /* CONFIG_H_ */
