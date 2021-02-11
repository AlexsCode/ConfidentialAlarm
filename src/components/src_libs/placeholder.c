//Placeholder C file.
#define HIGH 1
#include "placeholder.h"
#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_sleep.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * @brief sets the state of a gpio pin, then returns level set to.
 * 
 * @param gpio 
 * @return int 
 */
int status_LED_ON(gpio_num_t gpio)
{   
    gpio_set_level(gpio,HIGH);
    // vTaskDelay(100);
    
    return gpio_get_level(gpio);
}

void rtos_Test(void *pvParameters)
{
    
}