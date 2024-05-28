#include <Arduino.h>
#include "pir_switch.h"

PirConfig pirConfig;
PirState pirState;

void toggleState()
{
    pirState.state = pirState.state == HIGH ? LOW : HIGH;
    digitalWrite(LED_BUILTIN, pirState.state);
    digitalWrite(pirConfig.ledPin, pirState.state);
    noInterrupts();
    delay(2000);
    interrupts();
}

void startPir(PirConfig config)
{
    pinMode(config.ledPin, OUTPUT);
    pinMode(config.pirPin, INPUT_PULLUP);
    pirConfig = config;
    pirState.state = LOW;
    attachInterrupt(1, toggleState, RISING);
}
