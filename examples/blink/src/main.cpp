#include <Arduino.h>
#include <ScriptableThings.h>
#include <SPIFFS.h>

#include "JavaScript.h"

auto engine = ProgramEngine(&SPIFFS, "/scripts/", ESP.getFreeHeap() >> 1, JavaScript::setup);

void setup()
{
  // Setup serial for log messages and mount the spiffs drive
  Serial.begin(115200);
  SPIFFS.begin();

  // Configure the blink pin mode
  pinMode(BLINK_PIN, OUTPUT);

  // Start up the JavaScript engine
  engine.begin();
  
  // Run the main script
  engine.runScript("main.js");
}

void loop()
{
  // Tick the engine to process timers and etc
  engine.loop();
}
