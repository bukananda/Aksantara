const int pinPWM = 9; // Pin output

void setup() {
    pinMode(pinPWM, OUTPUT); 
}

void loop() {
// duty cycle = ((ON time) / periode)* 100 %
    digitalWrite(pinPWM, HIGH); // pin PWM HIGH
    delayMicroseconds(500);     // sleep selama 500 ms
    digitalWrite(pinPWM, LOW);  // pin PWM LOW
    delayMicroseconds(500);     // sleep selama 500 ms
}