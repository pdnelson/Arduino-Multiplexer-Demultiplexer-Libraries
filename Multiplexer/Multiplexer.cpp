// Written by Patrick Nelson (2021)
// This will allow reading from a 4-16-channel multiplexer.
// This library can only read data from a multiplexer. For writing functionality,
// see the sister library: Demultiplexer.

#include "arduino.h"
#include "Multiplexer.h"

Multiplexer::Multiplexer(uint8_t muxOutput, uint8_t selectorA) {
    this->muxOutput = muxOutput;

    this->selectorCount = 1;

    this->delayMicros = 0;

    this->selectorA = selectorA;

    pinMode(this->muxOutput, INPUT);

    pinMode(this->selectorA, OUTPUT);

    digitalWrite(this->selectorA, LOW);
}

Multiplexer::Multiplexer(uint8_t muxOutput, uint8_t selectorA, uint8_t selectorB) {
    this->muxOutput = muxOutput;

    this->selectorCount = 2;

    this->delayMicros = 0;

    this->selectorA = selectorA;
    this->selectorB = selectorB;

    pinMode(this->muxOutput, INPUT);

    pinMode(this->selectorA, OUTPUT);
    pinMode(this->selectorB, OUTPUT);

    digitalWrite(this->selectorA, LOW);
    digitalWrite(this->selectorB, LOW);
}

Multiplexer::Multiplexer(uint8_t muxOutput, uint8_t selectorA, uint8_t selectorB, uint8_t selectorC) {
    this->muxOutput = muxOutput;
    
    this->selectorCount = 3;

    this->delayMicros = 0;

    this->selectorA = selectorA;
    this->selectorB = selectorB;
    this->selectorC = selectorC;

    pinMode(this->muxOutput, INPUT);

    pinMode(this->selectorA, OUTPUT);
    pinMode(this->selectorB, OUTPUT);
    pinMode(this->selectorC, OUTPUT);

    digitalWrite(this->selectorA, LOW);
    digitalWrite(this->selectorB, LOW);
    digitalWrite(this->selectorC, LOW);
}

Multiplexer::Multiplexer(uint8_t muxOutput, uint8_t selectorA, uint8_t selectorB, uint8_t selectorC, uint8_t selectorD) {
    this->muxOutput = muxOutput;
    
    this->selectorCount = 4;

    this->delayMicros = 0;

    this->selectorA = selectorA;
    this->selectorB = selectorB;
    this->selectorC = selectorC;
    this->selectorD = selectorD;

    pinMode(this->muxOutput, INPUT);

    pinMode(this->selectorA, OUTPUT);
    pinMode(this->selectorB, OUTPUT);
    pinMode(this->selectorC, OUTPUT);
    pinMode(this->selectorD, OUTPUT);

    digitalWrite(this->selectorA, LOW);
    digitalWrite(this->selectorB, LOW);
    digitalWrite(this->selectorC, LOW);
    digitalWrite(this->selectorD, LOW);
}

bool Multiplexer::readDigitalValue(uint8_t inputPinToReadFrom) {

    // Retrieve value of LSB (position 0)
    digitalWrite(selectorA, inputPinToReadFrom & 0x1);

    if(selectorCount > 1) {
        // Retrieve bit in position 1
        digitalWrite(selectorB, (inputPinToReadFrom >> 1) & 0x1);

        if(selectorCount > 2) {
            // Retrieve bit in position 2
            digitalWrite(selectorC, (inputPinToReadFrom >> 2) & 0x1);

            if(selectorCount > 3) {
                // Retrieve bit in position 3
                digitalWrite(selectorD, (inputPinToReadFrom >> 3) & 0x1);
            }
        }
    }

    delayMicroseconds(this->delayMicros);

    return digitalRead(muxOutput);
}

void Multiplexer::setDelayMicroseconds(unsigned int delayMicroseconds) {
    this->delayMicros = delayMicroseconds;
}