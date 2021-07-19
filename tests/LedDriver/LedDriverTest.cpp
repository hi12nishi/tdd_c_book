#include "CppUTest/TestHarness.h"

extern "C"
{
    #include "LedDriver.h"
}

TEST_GROUP(LedDriver)
{
    void setup()
    {
    }
    
    void teardown()
    {
    }



};

TEST(LedDriver, LedsOffAfterCreate)
{
    uint16_t virtualLeds = 0xffff;  // 16 Leds, 0xf == 4bit
    LedDriver_Create(&virtualLeds);
    LONGS_EQUAL(0, virtualLeds);
}
