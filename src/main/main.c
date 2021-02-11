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
//Main Application

#include <stdio.h>
#include "esp_system.h"
#include "esp_sleep.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "placeholder.h"
#include "sdkconfig.h"


#define HIGH 1  
#define LOW 0
#define LED_PIN GPIO_NUM_2 //Macro LED pin to onboard LED

#define ADC_PIN ADC2_CH1 //Configured ADC to GPIO 0
#define WAKE_PIN ((gpio_num_t)GPIO_NUM_4) // configuring Interupt pin, Accessible via RTC 

//Creating Flag accessible from RTC memory.
RTC_DATA_ATTR bool SleepFlag=false;

void sleepTask(void *pvParameter)
{
    //Configure / Offline what is required to sleep.
    esp_sleep_enable_ext0_wakeup(WAKE_PIN,HIGH);
    esp_deep_sleep_start();
}

void app_main(void)
{
    if(SleepFlag){
        printf("Creating Sleep Task\n");
        fflush(stdout);

        xTaskCreate(&sleepTask,"Sending to Sleep",2048,NULL,5,NULL);
    }

    else{
        //Staying Awake Code.
        
        printf("debugging loop");
        fflush(stdout);
    }
}