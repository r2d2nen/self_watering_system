int pin_sensor_read = 7;
int pin_sensor_activate = 3;

void setup() {
  pinMode(pin_sensor_activate, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(pin_sensor_activate, HIGH);
  delay(50);
  int val = analogRead(pin_sensor_read);
  Serial.println(val);
  digitalWrite(pin_sensor_activate, LOW);
  delay(5000);
  
}

