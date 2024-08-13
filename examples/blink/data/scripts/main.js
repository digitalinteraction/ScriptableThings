let value = false;

function loop() {
  Thing.setLed(value);
  value = !value;
}

setInterval(loop, 1_000);
