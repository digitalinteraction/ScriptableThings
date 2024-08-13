# captive-portal

This is a ScriptableThings example showing how to run a captive portal on the device.
The example uses PlatformIO to manage project dependencies.
Start with [src/main.cpp](./src/main.cpp).

The device boots up, creates a `CaptivePortal` and hooks it up to the `AsyncWebServer` to serve the `www` directory inside the SPIFFS partition over HTTP.

AsyncWebServer comes from [me-no-dev/ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)

The `data` directory can be flashsed to the SPIFFS partition using PlatformIO's `Build Filesystem Image` and `Upload Filesystem Image` commands.
