// Written by Patrick Nelson (2021)
// This will allow reading from a 2-16-channel multiplexer.
// This library can only read data from a multiplexer. For writing functionality,
// see the sister library: Demultiplexer.

#ifndef Multiplexer_h
#define Multiplexer_h

class Multiplexer {
    public:
        // Constructors. These values will correspond to the arduino pins connected to the
        // multiplexer's selector pins.

        // 2-channel multiplexer
        Multiplexer(uint8_t muxOutput, uint8_t selectorA);

        // 4-channel multiplexer
        Multiplexer(uint8_t muxOutput, uint8_t selectorA, uint8_t selectorB);

        // 8-channel multiplexer
        Multiplexer(uint8_t muxOutput, uint8_t selectorA, uint8_t selectorB, uint8_t selectorC);

        // 16-channel multiplexer
        Multiplexer(uint8_t muxOutput, uint8_t selectorA, uint8_t selectorB, uint8_t selectorC, uint8_t selectorD);

        // Read a digital value from one of the multiplexer's input pins.
        // This takes in a numeric value corresponding to one of the multiplexer's
        // input lines.
        //
        // Return values:
        // False - the line is LOW
        // True - the line is HIGH
        bool readDigitalValue(uint8_t inputPinToReadFrom);

        // Set the delay between setting selector pins and reading the output value.
        // This is to account for the propagation delay of the multiplexer.
        void setDelayMicroseconds(unsigned int delayMicroseconds);

    private:
        // The pin on the arduino that is responsible for reading the multiplexer's output.
        uint8_t muxOutput;

        // How many selectors the multiplexer has. (ex: 3 for 8-channel, 4 for 16-channel)
        uint8_t selectorCount;

        // Selector pins corresponding to the three selectors on a multiplexer.
        uint8_t selectorA;
        uint8_t selectorB;
        uint8_t selectorC;
        uint8_t selectorD;

        // The delay (in microseconds) that occurs between setting all selector values,
        // and reading the multiplexer output value.
        unsigned int delayMicros;
};

#endif