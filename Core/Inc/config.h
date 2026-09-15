/*
 * config.h
 *
 *  Automatically created by Lishui Parameter Configurator
 *  Author: stancecoke
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#include "stdint.h"

//Dangerzone, do not touch!!
#define DISPLAY_TYPE_M365DASHBOARD (1<<1)
#define DISPLAY_TYPE_DEBUG (1<<0)

#define TRIGGER_OFFSET_ADC 50
#define TRIGGER_DEFAULT 2020
#define _T 2028

#define SPEEDFILTER 3

//#define ADCTHROTTLE
//#define FAST_LOOP_LOG
//#define DISABLE_DYNAMIC_ADC

// choose your display here
#define DISPLAY_TYPE DISPLAY_TYPE_M365DASHBOARD

// calibration factors for voltage and current
#define CAL_BAT_V 14
#define CAL_I 38

// gains for PI controls
#define P_FACTOR_I_Q 100
#define I_FACTOR_I_Q 2
#define P_FACTOR_I_D 100
#define I_FACTOR_I_D 10

// min and max values of throttle and brake signals in ADC counts
#define THROTTLEOFFSET 45
#define THROTTLEMAX 175
#define BRAKEOFFSET 50
#define BRAKEMAX 190

// parameters for speed calculation
#define WHEEL_CIRCUMFERENCE 690
#define GEAR_RATIO 15

// speed limits for individual modes in kph
#define SPEEDLIMIT_ECO 21
#define SPEEDLIMIT_NORMAL 31
#define SPEEDLIMIT_SPORT 51

// motor current limits in mA
#define PH_CURRENT_MAX_ECO 16000
#define PH_CURRENT_MAX_NORMAL 28000
#define PH_CURRENT_MAX_SPORT 40000

// motor current limit for regen in mA
#define REGEN_CURRENT 3000

// maximum current for flux weakening in mA
#define FW_CURRENT_MAX 8000

// maximum battery currents in mA
#define BATTERYCURRENT_MAX 15000
#define REGEN_CURRENT_MAX 3000

// battery voltage limits in mV
#define BATTERYVOLTAGE_MIN 42000
#define BATTERYVOLTAGE_MAX 54600

// motor spinning direction
#define REVERSE 1

// settings for speed PLL
#define SPEED_PLL 1
#define P_FACTOR_PLL 10
#define I_FACTOR_PLL 10

#endif /* CONFIG_H_ */
