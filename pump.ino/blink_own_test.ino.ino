
int pumpTime = 6000;
int waitTime = 5000; // 1000*3600*24 - pumpTime
int outPin = 2;  
int led = LED_BUILTIN;

void setup() {
    // put your setup code here, to run once:
    
    pinMode(outPin, OUTPUT);
    pinMode(led, OUTPUT);

}

void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(outPin, HIGH);  // send current to start pump
    digitalWrite(led, HIGH);  // Light led light
    delay(pumpTime);  // Wiat for the pump to work
    digitalWrite(outPin, LOW);  // stop the pump
    digitalWrite(led, LOW); // turn off the led light
    delay(waitTime);  // wait untill the pump should work again

    
}
