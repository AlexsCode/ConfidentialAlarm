/**
 * @file placeholder.h
 * @author alex Tuddenham alex@tuddenham.info
 * @brief Header of Sub Component - extra Libraries.
 * @version 0.1
 * @date 2021-02-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

//insert ifnDef LED_PIN.
#include "driver/gpio.h"
#include "nvs_flash.h"

#define LED_PIN GPIO_NUM_2

/**
 * @brief Method to turn default LED Pin constantly on.
 * 
 * @param gpio 
 * @return int 
 */
int Status_LED_On(gpio_num_t gpio);

void rtos_Test(void *pvParameters);

/**
 * @brief Initialise the NVS flash storage for writing to.
 * 
 */
void nvs_setup();

/**
 * @brief testing function of NVS read and write, call multiple times in main to see iterations or after sleep.
 * 
 */
void nvs_test();

/**
 * @brief Used to save values to Non-Volatile Storage.
 * Params likely to change.
 * 
 * @param description 
 * @param value 
 */
void nvs_setter( const char * description ,uint32_t value);
