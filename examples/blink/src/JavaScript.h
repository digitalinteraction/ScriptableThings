#include <ScriptableThings.h>

#define BLINK_PIN GPIO_NUM_25

class JavaScript
{
public:
  // 
  // This is called to customise the JavaScript runtime before script execution
  // 
  static void setup(JSRuntime *rt, JSContext *ctx, JSValue global)
  {
    auto thing = JS_NewObject(ctx);
    JS_SetPropertyStr(ctx, global, "Thing", thing);
    JS_SetPropertyStr(ctx, thing, "setLed", JS_NewCFunction(ctx, JavaScript::setLed, "setLed", 1));
  }

  // 
  // This is the API for scripts to talk to the firmware
  // 
  // ```ts
  // setLed(value: boolean): void
  // ```
  // 
  static JSValue setLed(JSContext *ctx, JSValueConst jsThis, int argc, JSValueConst *argv)
  {
    // Check the required variable is passed and throw a JS error if it was not
    int value;
    if (!JS_IsBool(argv[0]))
    {
      return JS_ThrowTypeError(ctx, "ERR_INVALID_ARG_TYPE");
    }

    // Get the argument from the JS world
    value = JS_ToBool(ctx, argv[0]);

    // Set the LED based on the value called from JS
    // Note - the pin number is controlled at the firmware level
    digitalWrite(BLINK_PIN, value);

    return JS_UNDEFINED;
  }
};
