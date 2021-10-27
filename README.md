## Arduino Multiplexer/Demultiplexer Libraries

### Description
Multiplexers are useful if you have a variety of devices you would like to collect binary data from, but you are out of pins to use to collect that data.
This library allows easy use of multiplexers with an Arduino to accomplish this. This can also be used if you want to set more devices' values than what
your Arduino will support.

### Multiplexer and Demultiplexer
To use this library, all you need to do is pass through whatever Arduino pins correspond to your multiplexer's common input/output pin, selector pins, and then set the
propagation delay.

Once setup has commenced, you can call `readDigitalValue` and pass in an 8-bit unsigned value corresponding to one of the input pins on your arduino.
For example, calling `readDigitalValue(5)` will read from the multiplexer's input pin labeled `5`.

For using the demultiplexer, writing `writeDigitalValue(5, HIGH)` will set the demultiplexer's output pin labeled `5` to `HIGH`

Warning: Propagation delay is _very_ important when implementing this. If there is no delay set, values could be unpredictable and be very difficult to debug.
I recommend the higher end of 6-10 microseconds.

### Installation
1. Clone this repository
2. Move the `Multiplexer` and `Demultiplexer` directories into your user's `Arduino/libraries` directory.
- For more specific directory references, refer to [this link](https://learn.adafruit.com/adafruit-all-about-arduino-libraries-install-use/how-to-install-a-library).
3. Lastly, include the library by writing `#include <Multiplexer.h>` and/or `#include <Demultiplexer.h>` at the top of the file you would like to use it.