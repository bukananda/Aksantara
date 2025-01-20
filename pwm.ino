const int pinPWM = 9; // Pin digital yang digunakan untuk output PWM

void setup() {
  pinMode(pinPWM, OUTPUT); 
}

void loop() {
  digitalWrite(pinPWM, HIGH); // Set pin PWM menjadi HIGH
  delayMicroseconds(500);     // Tunggu selama 500 mikrodetik (50% duty cycle)
  digitalWrite(pinPWM, LOW);  // Set pin PWM menjadi LOW
  delayMicroseconds(500);     // Tunggu selama 500 mikrodetik (50% duty cycle)
}