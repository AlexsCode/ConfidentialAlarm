//Placeholder C file.
#define HIGH 1
#include "placeholder.h"
#include "driver/gpio.h"

int status_LED_ON(gpio_num_t gpio)
{   
    gpio_set_level(gpio,HIGH);
    
    return gpio_get_level(gpio);
}