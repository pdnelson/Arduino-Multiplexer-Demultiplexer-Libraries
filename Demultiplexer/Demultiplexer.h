// Written by Patrick Nelson (2021)
// This will allow writing to a 2-16-channel demultiplexer.
// This library can only write data to a demultiplexer. For reading functionality,
// see the sister library: Multiplexer.

#ifndef Demultiplexer_h
#define Demultiplexer_h

class Demultiplexer {
    public:
        // Constructors. These values will correspond to the arduino pins connected to the
        // demultiplexer's selector pins.

        // 2-channel demultiplexer
        Demultiplexer(uint8_t demuxInput, uint8_t selectorA);

        // 4-channel demultiplexer
        Demultiplexer(uint8_t demuxInput, uint8_t selectorA, uint8_t selectorB);

        // 8-channel demultiplexer
        Demultiplexer(uint8_t demuxInput, uint8_t selectorA, uint8_t selectorB, uint8_t selectorC);

        // 16-channel demultiplexer
        Demultiplexer(uint8_t demuxInput, uint8_t selectorA, uint8_t selectorB, uint8_t selectorC, uint8_t selectorD);

        // Write a digital value to one of the demultiplexer's output pins.
        // This takes a numeric value corresponding to one of the (de)multiplexer's
        // output lines.
        void writeDigitalValue(uint8_t outputPinToWRiteTo, uint8_t value);

        // Set the delay between setting selector pins and reading the output value.
        // This is to account for the propagation delay of the demultiplexer.
        void setDelayMicroseconds(unsigned int delayMicroseconds);

    private:
        // The pin on the arduino that is responsible for reading the demultiplexer's output.
        uint8_t demuxInput;

        // How many selectors the demultiplexer has. (ex: 3 for 8-channel, 4 for 16-channel)
        uint8_t selectorCount;

        // Selector pins corresponding to the three selectors on a demultiplexer.
        uint8_t selectorA;
        uint8_t selectorB;
        uint8_t selectorC;
        uint8_t selectorD;

        // The delay (in microseconds) that occurs between setting all selector values,
        // and reading the demultiplexer output value.
        unsigned int delayMicros;
};

#endif