// Written by Patrick Nelson (2021)
// This will allow writing to a 2-16-channel demultiplexer.
// This library can only write data to a demultiplexer. For reading functionality,
// see the sister library: Multiplexer.

#include "arduino.h"
#include "Demultiplexer.h"

Demultiplexer::Demultiplexer(uint8_t demuxInput, uint8_t selectorA) {
    this->demuxInput = demuxInput;

    this->selectorCount = 1;

    this->delayMicros = 0;

    this->selectorA = selectorA;

    pinMode(this->demuxInput, OUTPUT);

    pinMode(this->selectorA, OUTPUT);

    digitalWrite(this->selectorA, LOW);
}

Demultiplexer::Demultiplexer(uint8_t demuxInput, uint8_t selectorA, uint8_t selectorB) {
    this->demuxInput = demuxInput;

    this->selectorCount = 2;

    this->delayMicros = 0;

    this->selectorA = selectorA;
    this->selectorB = selectorB;

    pinMode(this->demuxInput, OUTPUT);

    pinMode(this->selectorA, OUTPUT);
    pinMode(this->selectorB, OUTPUT);

    digitalWrite(this->selectorA, LOW);
    digitalWrite(this->selectorB, LOW);
}

Demultiplexer::Demultiplexer(uint8_t demuxInput, uint8_t selectorA, uint8_t selectorB, uint8_t selectorC) {
    this->demuxInput = demuxInput;
    
    this->selectorCount = 3;

    this->delayMicros = 0;

    this->selectorA = selectorA;
    this->selectorB = selectorB;
    this->selectorC = selectorC;

    pinMode(this->demuxInput, OUTPUT);

    pinMode(this->selectorA, OUTPUT);
    pinMode(this->selectorB, OUTPUT);
    pinMode(this->selectorC, OUTPUT);

    digitalWrite(this->selectorA, LOW);
    digitalWrite(this->selectorB, LOW);
    digitalWrite(this->selectorC, LOW);
}

Demultiplexer::Demultiplexer(uint8_t demuxInput, uint8_t selectorA, uint8_t selectorB, uint8_t selectorC, uint8_t selectorD) {
    this->demuxInput = demuxInput;
    
    this->selectorCount = 4;

    this->delayMicros = 0;

    this->selectorA = selectorA;
    this->selectorB = selectorB;
    this->selectorC = selectorC;
    this->selectorD = selectorD;

    pinMode(this->demuxInput, OUTPUT);

    pinMode(this->selectorA, OUTPUT);
    pinMode(this->selectorB, OUTPUT);
    pinMode(this->selectorC, OUTPUT);
    pinMode(this->selectorD, OUTPUT);

    digitalWrite(this->selectorA, LOW);
    digitalWrite(this->selectorB, LOW);
    digitalWrite(this->selectorC, LOW);
    digitalWrite(this->selectorD, LOW);
}

void Demultiplexer::writeDigitalValue(uint8_t outputPinToWriteTo, uint8_t value) {

    // Retrieve value of LSB (position 0)
    digitalWrite(selectorA, outputPinToWriteTo & 0x1);

    if(selectorCount > 1) {
        // Retrieve bit in position 1
        digitalWrite(selectorB, (outputPinToWriteTo >> 1) & 0x1);

        if(selectorCount > 2) {
            // Retrieve bit in position 2
            digitalWrite(selectorC, (outputPinToWriteTo >> 2) & 0x1);

            if(selectorCount > 3) {
                // Retrieve bit in position 3
                digitalWrite(selectorD, (outputPinToWriteTo >> 3) & 0x1);
            }
        }
    }

    delayMicroseconds(this->delayMicros);

    return digitalWrite(demuxInput, value);
}

void Demultiplexer::setDelayMicroseconds(unsigned int delayMicroseconds) {
    this->delayMicros = delayMicroseconds;
}