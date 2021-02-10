
//This is for testing component code.

#include <limits.h>
#include "unity.h"
#include "placeholder.h"

TEST_CASE("led_on_after_creation","status_led")
{
    TEST_ASSERT_EQUAL(1,(void Status_LED_ON(LED_PIN));
    
}
