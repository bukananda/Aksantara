// Implementasi I2C pada sensor GY-80

#include <Wire.h> // library wire

int ADXLAddress = 0x53; // Address dari slave yang akan dipilih

#define X_Axis_Register_DATAX0 0x32 // Address dari internal register slave yang dipilih
#define X_Axis_Register_DATAX1 0x33 // Address dari internal register slave yang dipilih
#define Power_Register 0x2D // Address dari internal register slave yang dipilih

int X0,X1,X_out;

void setup() {
  Wire.begin(); // inisiasi wire
  Serial.begin(9600);
  delay(100);

  Wire.beginTransmission(ADXLAddress); // Mengirimkan slave address
  Wire.write(Power_Register);

  Wire.write(8);  // enable measuring data
  Wire.endTransmission();
}

void loop() {
  Wire.beginTransmission(ADXLAddress); // memulai transmisi ke sensor
  // mengirim address dari register
  Wire.write(X_Axis_Register_DATAX0);
  Wire.write(X_Axis_Register_DATAX1);
  
  Wire.endTransmission(); // menyelesaikan transmisi
  
  Wire.requestFrom(ADXLAddress,2); // mengambil 2 byte data dari dua register
  
  if(Wire.available()<=2) {  // 
    X0 = Wire.read(); // Membaca data register
    X1 = Wire.read();   
  }
  
  Serial.print("X0= ");
  Serial.print(X0);
  Serial.print("   X1= ");
  Serial.println(X1);
}