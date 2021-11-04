/***
 * Excerpted from "Test-Driven Development for Embedded C",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/jgade for more book information.
***/
/*- ------------------------------------------------------------------ -*/
/*-    Copyright (c) James W. Grenning -- All Rights Reserved          -*/
/*-    For use by owners of Test-Driven Development for Embedded C,    -*/
/*-    and attendees of Renaissance Software Consulting, Co. training  -*/
/*-    classes.                                                        -*/
/*-                                                                    -*/
/*-    Available at http://pragprog.com/titles/jgade/                  -*/
/*-        ISBN 1-934356-62-X, ISBN13 978-1-934356-62-3                -*/
/*-                                                                    -*/
/*-    Authorized users may use this source code in your own           -*/
/*-    projects, however the source code may not be used to            -*/
/*-    create training material, courses, books, articles, and         -*/
/*-    the like. We make no guarantees that this source code is        -*/
/*-    fit for any purpose.                                            -*/
/*-                                                                    -*/
/*-    www.renaissancesoftware.net james@renaissancesoftware.net       -*/
/*- ------------------------------------------------------------------ -*/

extern "C"
{
    #include "LedDriver.h"
    #include "RuntimeError.h"
}

enum
{
    ALL_LEDS_ON  = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

enum
{
    FIRST_LED = 1,
    LAST_LED  = 16
};

static uint16_t* ledsAddress;
static uint16_t ledsImage;

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

static bool IsLedOutOfBounds(int ledNumber)
{
    return (ledNumber < FIRST_LED || ledNumber > LAST_LED);
}

static void updateHardware()
{
    *ledsAddress = ledsImage;
}

static void setLedImageBit(int ledNumber)
{
    ledsImage |= convertLedNumberToBit(ledNumber);
}

static void clearLedImageBit(int ledNumber)
{
    ledsImage &= ~(convertLedNumberToBit(ledNumber));
}

void LedDriver_Create(uint16_t* address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

void LedDriver_Destroy()
{
}

void LedDriver_TurnOn(int ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
    {
        RUNTIME_ERROR("Led Driver: out-of-bounds LED", ledNumber);
        return;
    }

    setLedImageBit(ledNumber);
    updateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
    if (IsLedOutOfBounds(ledNumber))
    {
        RUNTIME_ERROR("Led Driver: out-of-bounds LED", ledNumber);
        return;
    }

    clearLedImageBit(ledNumber);
    updateHardware();
}

void LedDriver_TurnAllOn()
{
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}
