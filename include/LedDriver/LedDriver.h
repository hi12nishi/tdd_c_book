#pragma once
#include <stdint.h>

void LedDriver_Create(uint16_t*);
void LedDriver_Destroy();

void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
