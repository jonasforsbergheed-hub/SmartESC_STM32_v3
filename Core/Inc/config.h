/*
 * config.h
 *
 * SmartESC STM32 V3 / M365
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include "stdint.h"

//------------------------------------------------------------
// Display
//------------------------------------------------------------

#define DISPLAY_TYPE_M365DASHBOARD (1<<1)
#define DISPLAY_TYPE_DEBUG (1<<0)
#define DISPLAY_TYPE DISPLAY_TYPE_M365DASHBOARD

//------------------------------------------------------------
// Throttle / brake
//------------------------------------------------------------

#define TRIGGER_OFFSET_ADC 50
#define TRIGGER_DEFAULT 2020
#define _T 2028
#define SPEEDFILTER 3

#define THROTTLEOFFSET 45
#define THROTTLEMAX 175

#define BRAKEOFFSET 50
#define BRAKEMAX 100

//------------------------------------------------------------
// Calibration
//------------------------------------------------------------

#define CAL_BAT_V 14
#define CAL_V 25
#define CAL_I 38

//------------------------------------------------------------
// Motor parameters
//------------------------------------------------------------

#define INDUCTANCE 6LL
#define RESISTANCE 40LL
#define FLUX_LINKAGE 1200LL
#define GAMMA 9LL

//------------------------------------------------------------
// Speed calculation
//------------------------------------------------------------

#define WHEEL_CIRCUMFERENCE 2302
#define GEAR_RATIO 45

//------------------------------------------------------------
// Speed limits
//------------------------------------------------------------

#define SPEEDLIMIT_ECO 20
#define SPEEDLIMIT_NORMAL 35
#define SPEEDLIMIT_SPORT 55

//------------------------------------------------------------
// Phase current limits (mA)
//------------------------------------------------------------

#define PH_CURRENT_MAX_ECO 15000
#define PH_CURRENT_MAX_NORMAL 25000
#define PH_CURRENT_MAX_SPORT 35000

//------------------------------------------------------------
// Regen
//------------------------------------------------------------

#define REGEN_CURRENT 1000
#define REGEN_MAX_CURRENT 10000
#define REGEN_CURRENT_MAX 10000

//------------------------------------------------------------
// Field weakening
//------------------------------------------------------------

#define FW_CURRENT_MAX 0
#define FIELD_WEAKNING_CURRENT_MAX 0

//------------------------------------------------------------
// Battery current
//------------------------------------------------------------

#define BATTERYCURRENT_MAX 35000
#define BATTERISTRÖM_MAX 35000

//------------------------------------------------------------
// Battery voltage limits
//------------------------------------------------------------

#define BATTERYVOLTAGE_MIN 33000
#define BATTERYVOLTAGE_MAX 54600

//------------------------------------------------------------
// Battery level thresholds
//------------------------------------------------------------

#define BATTERINIVÅ_1 323000
#define BATTERINIVÅ_2 329000
#define BATTERINIVÅ_3 334400
#define BATTERINIVÅ_4 436000
#define BATTERINIVÅ_5 546000

//------------------------------------------------------------
// ADC channels
//------------------------------------------------------------

#define ADC_VOLTAGE 0
#define ADC_THROTTLE 1
#define ADC_TEMP 2

//------------------------------------------------------------
// Motor direction
//------------------------------------------------------------

#define REVERSE 1

//------------------------------------------------------------
// Speed PLL
//------------------------------------------------------------

#define SPEED_PLL 0
#define HASTIGHET_PLL

#define P_FACTOR_PLL 9
#define I_FACTOR_PLL 10

#endif /* CONFIG_H_ */
