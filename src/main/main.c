/**
 * @file main.c
 * @author Alex Tuddenham
 * @brief Confidentially alert src main. To trigger an alert when woken from sleep via external stimulus.
 * @version 0.1
 * @date 2021-02-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
//Main Application

#include <stdio.h>
#include "esp_system.h"
#include "placeholder.h"

#define HIGH 1  
#define LOW 0
#define LED_PIN GPIO_NUM_2 //Macro LED pin to onboard LED
#define WAKE_PIN RTC_GPIO10 //Configured to RTC setout of GPIO 04 Pin, unsure if matters for accessing ULP.
#define ADC_PIN ADC2_CH1 //Configured ADC to GPIO 0

void app_main(void)
{
    
}


