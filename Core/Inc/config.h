#define GASSPJÄLLFÖRSKJUTNING 45
#define GASMAX 175
#define BROMSFÖRSKJUTELSE 50
#define BRAKEMAX 100

// hastighetsbegränsningar
#define SPEEDLIMIT_ECO 20
#define HASTIGHETSLIMIT_NORMAL 35
#define HASTIGHETSLIMIT_SPORT 55

// motorströmsgränser
#define PH_CURRENT_MAX_ECO 15000
#define PH_CURRENT_MAX_NORMAL 25000
#define PH_CURRENT_MAX_SPORT 35000

// regenerera
#define REGEN_MAX_CURRENT 10000

// fältförsvagning
#define FÄLT_FÖRSVAGNING_STRÖM_MAX 0 //max-id

// ADC-kanaler
#define ADC_SPÄNNING 0
#define ADC_THROTTLE 1
#define ADC_TEMP 2

#define LED-stift GPIO_PIN_1
#define LED_GPIO_Port GPIOC
#define UART1_Tx_Pin GPIO_PIN_6
#define UART1_Tx_GPIO_Port GPIOB
#define Bromsljusstift GPIO_PIN_15
#define Bromsljus_GPIO_Port GPIOA
#define Temp_Pin GPIO_PIN_0
#define Temp_GPIO_Port GPIOA
#define Gasspjällspinne GPIO_PIN_1
#define Gasspjäll_GPIO_Port GPIOA
#define Batterispänningsstift GPIO_PIN_2
#define Batterispänning_GPIO_Port GPIOA
#define PWR_BTN_PIN GPIO_PIN_14
#define PWR_BTN_GPIO_Port GPIOC
#define TPS_ENA_PIN GPIO_PIN_15
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
#define CAL_BAT_V 14
