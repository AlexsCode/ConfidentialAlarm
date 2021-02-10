//Placeholder C file.

#include "placeholder.h"

void status_LED_ON(*pvParameter)
{
    gpio_set_level(LED_PIN,HIGH);
    
    return gpio_get_level(LED_PIN);
}