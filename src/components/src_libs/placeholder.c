//Placeholder C file.
#define HIGH 1


#include "placeholder.h"
#include "driver/gpio.h"
//  #include "nvs_flash.h"
//  #include "/home/alex/esp/esp-idf/components/nvs_flash/include/nvs_flash.h"
#include "nvs_flash.h"
//  #include "../nvs_flash/include/nvs_flash.h"

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_system.h"
#include "esp_sleep.h"

uint32_t test_counter=0; // Used to Test NVS storage.
uint32_t ssid;
uint32_t pwd;


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

/**
 * @brief Initialises non volatile storage
 * 
 */
void nvs_setup()
{
    esp_err_t err = nvs_flash_init(); //attempt to initial storage, handle any error.
        if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) 
        {
            // NVS partition was truncated and needs to be erased
            // Retry nvs_flash_init
            ESP_ERROR_CHECK(nvs_flash_erase());
            err = nvs_flash_init();
        }
    ESP_ERROR_CHECK( err );
    printf("nvs Setup Complete\n");
    printf("error code %d\n",(int)err);

    fflush(stdout);
}

/**
 * @brief Basic test for NVS Read / Write.
 * 
 */
void nvs_test()
{
    printf("Starting of NVS Test\n");
    nvs_handle_t nvs_handler; //Handler used to ...

    esp_err_t err = nvs_open("test_storage\n",NVS_READWRITE,&nvs_handler); //reads error code if operation fails.
    if(err != ESP_OK)//ESP_OK is Macro 0
    {
        printf("Error reading NVS, Problem was %s\n",esp_err_to_name(err));
    }
    else
    {
        printf("Handler Created Successfully\n");
    }

    
    err = nvs_get_u32(nvs_handler,"test counter\n",&test_counter);
    printf("test_counter value is %d\n",test_counter);
    test_counter++;
    err = nvs_set_u32(nvs_handler,"test counter",test_counter);
    printf("updating values\n");
    err = nvs_commit(nvs_handler);
    nvs_close(nvs_handler);
    printf("exiting NVS Test\n");

}

void nvs_setter( const char * description ,uint32_t value) //parameters to change
{
    nvs_handle_t nvs_handler;     

    esp_err_t err = nvs_open(description,NVS_READWRITE,&nvs_handler); //reads error code if operation fails.
    if(err != ESP_OK)//ESP_OK is Macro 0
    {
        printf("Error reading NVS, Problem was %s\n",esp_err_to_name(err));
    }
    else
    {
        printf("Handler Created Successfully\n");
    }
    
    err = nvs_set_u32(nvs_handler,description,value);
    err = nvs_commit(nvs_handler);
    nvs_close(nvs_handler);


}
