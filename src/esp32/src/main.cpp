#include <Arduino.h>

#define ATTENTE 1000

const uint8_t brocheLedRouge = 17;
const uint8_t brocheLedVerte = 16;

void setup()
{
    Serial.begin(115200);
    pinMode(brocheLedRouge, OUTPUT);
    pinMode(brocheLedVerte, OUTPUT);
}

void loop()
{
    digitalWrite(brocheLedRouge, HIGH);
    delay(ATTENTE);
    digitalWrite(brocheLedRouge, LOW);
    delay(ATTENTE);
    digitalWrite(brocheLedVerte, HIGH);
    delay(ATTENTE);
    digitalWrite(brocheLedVerte, LOW);
    delay(ATTENTE);
}