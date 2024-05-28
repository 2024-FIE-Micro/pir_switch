#ifndef __PIR_SWITCH_H_
#define __PIR_SWITCH_H_
#include <Arduino.h>

typedef struct
{
    int ledPin;
    int pirPin;
} PirConfig;

typedef struct
{
    int state = LOW;
} PirState;

void startPir(PirConfig);

#endif
