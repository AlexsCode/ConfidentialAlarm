/**
 * @file main.c
 * @author Alex Tuddenham
 * @brief Confidentially alert src main. To trigger an alert when woken from sleep via external stimulus.
 * @version 0.1
 * @date 2021-02-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include "esp_system.h"
#include "esp_sleep.h"
#include "esp_wifi.h"
#include "esp_event.h"

#include "driver/gpio.h"
#include "nvs_flash.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

//Custom headers
#include "placeholder.h"
#include "sdkconfig.h"


#define HIGH 1  
#define LOW 0
#define LED_PIN GPIO_NUM_2 //Macro LED pin to onboard LED
#define ADC_PIN ADC2_CH1 //Configured ADC to GPIO 0
#define WAKE_PIN GPIO_NUM_4 // Interupt Pin.

//Setting SSID, PW Memory Locations.
//To be stored in NVS after creation.
const char ssid_c = "tempssid";
uint32 pwd = 0x20;

//RTC fast memory storaged variables, accessible from Deep Sleep.
RTC_DATA_ATTR bool SleepFlag=false;
RTC_DATA_ATTR int bootNumber=0;

/**
 * @brief initialising RTC wake pin and setup.
 * 
 * @param pvParameter 
 */
void wakePin_Checker(void *pvParameter)
{
    uint32_t rtc_gpio_get_level(WAKE_PIN);
    
};



/**
 * @brief Diagnosing last reason for waking.
 * 
 */
// void print_wakeup()
// {
//     esp_deep_sleep_wakeup_cause_t wakeup_cause;
//     wakeup_cause = esp_deep_sleep_get_wakeup_cause();
    
//     switch(wakeup_cause)
//     {
//         case 1 : printf("Woken by RTC IO - Door Trigger\n");break;
//         case 2 : printf("Woken by Timer Ending\n");break;
//         default :
//             printf("Wakeup Not Caused By Known Deep Sleep: %d\n",wakeup_cause);
//     }
//     fflush(stdout); //clears the IO buffer.
// }

/**
 * @brief Deep sleep setter, to be called via freeRTOS task.
 * 
 * @param pvParameter 
 */
void sleepTask(void *pvParameter)
{
    //Configure / Offline what is required to sleep.
    esp_sleep_enable_ext0_wakeup(WAKE_PIN,HIGH);
    esp_deep_sleep_start();
}

/**
 * @brief deep sleep wake stub, customising the wakeup sequence.
 * 
 */
void RTC_IRAM_ATTR  esp_wake_deep_sleep(void)
{
    esp_default_wake_deep_sleep();
    static RTC_RODATA_ATTR const char bootstr[] = "wake boot %d\n";
    printf(bootstr,bootNumber); //retrieves and prints from RTC memory Locations.
    fflush(stdout);
}


/**
 * @brief Main Process Runner.
 * 
 */
void app_main(void)
{   
    nvs_setup(); //initalises nvs
    nvs_test(); //testing r & w 
    nvs_test();


    //boot loop and Testing/debugging routines.
    // print_wakeup();//prints last reason for waking from deepsleep.
    // printf("Boot Count: %d/n",bootNumber++);
    //xTaskCreate(&rtos_Test,"checks if Pin High",2048,NULL,10,NULL);
    //xTaskCreate(&wakePin_Checker,"checks if Pin High",2048,NULL,10,NULL);


    if(SleepFlag){
        printf("Creating Sleep Task\n");
        fflush(stdout);

        xTaskCreate(&sleepTask,"Sending to Sleep",2048,NULL,5,NULL);
    }

    else{

        printf("debugging loop");
        fflush(stdout);
    }
}