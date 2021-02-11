
//This is for testing component code.

#include <limits.h>
#include "unity.h"
#include "placeholder.h"

TEST_CASE("led_on_after_creation","status_led")
{
    int ledreturn = int Status_LED_ON(LED_PIN);
    vTaskDelay(200);

    TEST_ASSERT_EQUAL(1,ledreturn);
    // TEST_ASSERT_EQUAL(1,(int Status_LED_ON(LED_PIN));
    
}


