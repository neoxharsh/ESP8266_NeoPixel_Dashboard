//This is for Serial Debug, Uncomment this for debug
#define BLYNK_PRINT Serial

//Defines the Total number of Leds, Matrix Height and Width, Led Pin and Extra Button Pins, but the buttons are not yet implemented..
#define LED_COUNT             64
#define MATRIX_HEIGHT         8
#define MATRIX_WIDTH          8
#define LED_PIN               D3
#define BUZZER_PIN            D5



//Defines the total number of state that are present in the program
#define TOTAL_STATE           6

#define START_STATE           0
#define MSG_STATE             1
#define FX_STATE              2
#define OTA_STATE             3
#define WIFI_STATE            4
#define TIME_STATE            5



//Defines total number of timers that are implemented in the sketch
#define TOTAL_TIMER           5

#define MSG_TIMER             0
#define FX_TIMER              1
#define OTA_TIMER             2
#define TIME_TIMER            3
#define ALARM_TIMER           4



//Defines all the Blynk Widgets placed in the app, and assign the Virtual pins that they are connected to
#define BRIGHTNESS_WIDGET                 V0
#define COLOR_PICKER_WIDGET               V1
#define TEXT_SENDER_WIDGET                V2
#define TEXT_SCROLL_BUTTON_WIDGET         V3
#define FX_BUTTON_WIDGET                  V4
#define EFFECTS_WIDGET                    V5
#define MSG_SPEED_WIDGET                  V6
#define FX_SPEED_WIDGET                   V7
#define OTA_BUTTON_WIDGET                 V8
#define SYNC_TIME_BUTTON_WIDGET           V9
#define SHOW_TIME_BUTTON_WIDGET           V10
#define WIFI_CONFIG_BUTTON_WIDGET         V11
#define ALARM_INPUT_WIDGET                V12
#define ALARM_BUTTON_WIDGET               V13


//String Values for the Time as well as the MSG to be displayed
String msg = " ", timeIs = "";


//BOOL check to make sure that OTA is initilized or not
bool otaInitilized = false,
     blynkConnected = false,
     alarmOn = false,
     alarmIsRunning = false;


//Constant for the time server
const char* host = "time.nist.gov";

//Int for the all the varibales necessary to store important data
uint8_t State = START_STATE,
        fxMode = 0,
        brightness = 40,
        fxSpeed = 150,
        textSpeed = 80,
        red = 255,
        green = 255,
        blue = 255;

int x = 1,
    alarmHours = 0,
    alarmMinutes = 0;


//Array describing total number of timers.
uint8_t Timer[TOTAL_TIMER];

//The Auth token for Blynk. Add your own token here.
char auth[] = "";

