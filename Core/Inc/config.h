#define THROTTLEOFFSET 45
#define THROTTLEMAX 175
#define BRAKEOFFSET 50
#define BRAKEMAX 100

// speed limits
#define SPEEDLIMIT_ECO 20
#define SPEEDLIMIT_NORMAL 35
#define SPEEDLIMIT_SPORT 55

// motor current limits
#define PH_CURRENT_MAX_ECO 15000
#define PH_CURRENT_MAX_NORMAL 25000
#define PH_CURRENT_MAX_SPORT 35000

// regen
#define REGEN_MAX_CURRENT 10000

// field weakening
#define FIELD_WEAKNING_CURRENT_MAX 0 //max-id

// ADC channels
#define ADC_VOLTAGE 0
#define ADC_THROTTLE 1
#define ADC_TEMP 2

#define LED_Pin GPIO_PIN_1
#define LED_GPIO_Port GPIOC
#define UART1_Tx_Pin GPIO_PIN_6
#define UART1_Tx_GPIO_Port GPIOB
#define BrakeLight_Pin GPIO_PIN_15
#define BrakeLight_GPIO_Port GPIOA
#define Temp_Pin GPIO_PIN_0
#define Temp_GPIO_Port GPIOA
#define Throttle_Pin GPIO_PIN_1
#define Throttle_GPIO_Port GPIOA
#define Batt_Voltage_Pin GPIO_PIN_2
#define Batt_Voltage_GPIO_Port GPIOA
#define PWR_BTN_Pin GPIO_PIN_14
#define PWR_BTN_GPIO_Port GPIOC
#define TPS_ENA_Pin GPIO_PIN_15
#define TPS_ENA_GPIO_Port GPIOC

#define BATTERINIVÅ_1 323000
#define BATTERINIVÅ_2 329000
#define BATTERINIVÅ_3 334400
#define BATTERINIVÅ_4 436000
#define BATTERINIVÅ_5 546000

#define BATTERISTRÖM_MAX 35000

#define REGEN_CURRENT 1000
#define REGEN_CURRENT_MAX 10000

#define HASTIGHET_PLL
#define P_FACTOR_PLL 9
#define I_FACTOR_PLL 10
