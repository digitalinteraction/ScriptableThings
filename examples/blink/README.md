# blink

This is a ScriptableThings example showing how to blink a pin from the JavaScript world.
It is based on the [Arduino Turorial](https://docs.arduino.cc/built-in-examples/basics/Blink/)
and uses PlatformIO to manage project dependencies.
Start with [src/main.cpp](./src/main.cpp).

The device boots up, creates a `ProgramEngine` that looks inside the SPIFFS directory for JavaScript files
and configures it with the `JavaScript` setup method. When it boots up it runs [data/scripts/main.js](./data/scripts/main.js) .

The `data` directory can be flashed to the SPIFFS partition using PlatformIO's `Build Filesystem Image` and `Upload Filesystem Image` commands.
