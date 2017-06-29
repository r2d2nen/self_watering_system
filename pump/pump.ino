
int pulseHighTime = 150; // Set motor pin high for this amount of time.
int pulseLowTime = 100; // Time between each pulse.
int roundTimeDelay = 2000; // Time between each round.
int wateringDelay = 5000; // Time between each moisture value check.

int pin_pump = 2; // Turns the pump on.
int pin_led = LED_BUILTIN; // Signals when the pump is running.
int pin_sensor_activate = 3; // Turns the moisture on. It is only powered when needed to slowen oxidation.
int pin_sensor_read = 7; // Reads the moisture value from the sensor.

int moisture_tolerance = 500; // Water the plant when the moisture sensor value i higher than this value (higher value = drier soil).
int waterRounds = 5; // Each watering contains this many rounds, with roundTimeDelay between them.
int waterPulsesPerRound = 5; // Water pulses per round.

void setup() {
    pinMode(pin_pump, OUTPUT);
    pinMode(pin_led, OUTPUT);
    pinMode(pin_sensor_activate, OUTPUT);
}

void loop() {
  int moisture = measure_moisture(pin_sensor_activate, pin_sensor_read);
  
  if (moisture > moisture_tolerance) {
    digitalWrite(pin_led, HIGH);
    water(waterRounds, waterPulsesPerRound, roundTimeDelay, pin_pump, pulseHighTime, pulseLowTime);
  }
  else {
    digitalWrite(pin_led, LOW);
  }
  delay(wateringDelay);
}

void waterPulse(int Ipin_pump, int IpulseHighTime, int IpulseLowTime) { // I = ''Input''
  digitalWrite(Ipin_pump, HIGH);  // Send current to start pump.
  delay(IpulseHighTime);  // Wait for the pump to work.
  digitalWrite(Ipin_pump, LOW);  // Stop the pump.
  delay(IpulseLowTime);  // Wait untill the pump should work again
}

void water(int IwaterRounds, int IwaterPulsesPerRound, int IroundTimeDelay, int Ipin_pump, int IpulseHighTime, int IpulseLowTime) {
  for (int i = 0; i < IwaterRounds; i++) {
    for (int j = 0; j < IwaterPulsesPerRound; j++) {
        waterPulse(Ipin_pump, IpulseHighTime, IpulseLowTime);
    }
    delay(IroundTimeDelay);
  }
}

int measure_moisture(int Ipin_sensor_activate, int Ipin_sensor_read) {
  digitalWrite(Ipin_sensor_activate, HIGH);
  delay(100);
  int val = analogRead(Ipin_sensor_read);
  digitalWrite(Ipin_sensor_activate, LOW);
  return val;
}

