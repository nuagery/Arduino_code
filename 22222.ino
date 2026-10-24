#include <Wire.h>

#define TEN_METER (11129)   // 234.256*10/(0.067*3.1415926)
long unsigned int encoder1Value = 0;
long unsigned int encoder2Value = 0;
long unsigned int encoder3Value = 0;
long unsigned int encoder4Value = 0;

long unsigned int target1 = 0;
int i;
int j;
void setup() {
  unsigned char i=0;
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);  // Configure the reset pin as an output and hold the robot in reset
  digitalWrite(13,LOW);
  
  //Setup the serial ports
  Serial.begin(57600);    // This is the hardware port connected to the PC through the USB connection
  Wire.begin();
  target1 = 0x80000000 + TEN_METER;

  // wait 5 seconds
  delay(5000);
  
  Serial.println("software serial simple test!");  // Send some text to the PC
  
  digitalWrite(13,HIGH);  // Release the robot from reset
  delay(100);  // A short delay to allow the robot to start-up
  Wire.beginTransmission(42);
  Wire.write("sa");   //Go straight at first
  Wire.write(40);
  Wire.write(0);
  Wire.write(42);
  Wire.write(0);
  Wire.write(40);
  Wire.write(0);
  Wire.write(40);
  Wire.write(0);
  Wire.endTransmission();   
}
void loop() {
  delay(2138);
  for(i = 0; i <= 2; i++){
    Wire.beginTransmission(42);
    Wire.write("baffrr");
    for(j = 0; j <= 3; j++){
      Wire.write(40);
      Wire.write(0);
    }
    Wire.endTransmission();
    delay(970);
    Wire.beginTransmission(42);
    Wire.write("baffff");
    Wire.write(40);
    Wire.write(0);
    Wire.write(40);
    Wire.write(0);
    Wire.write(40);
    Wire.write(0);
    Wire.write(42);
    Wire.write(0);
    Wire.endTransmission();
    delay(2135);
  }
  Wire.beginTransmission(42);
 /*Wire.write("sa");
  for (i = 0; i <= 3; i++) {
    Wire.write(0);
    Wire.write(0);
  }
  delay(1000);*/
  Wire.write("ha");
  Wire.endTransmission();
  digitalWrite(13, HIGH);


}
void atime()
{
  delay(4280);
  Wire.beginTransmission(42);
  Wire.write("baffrr");
  for(i = 0; i <= 3; i++){
    Wire.write(40);
    Wire.write(0);
  }
  Wire.endTransmission();
  delay(712);
}
void readEncoder()
{
  long unsigned int encoder1 = 0;
  long unsigned int encoder2 = 0;
  long unsigned int encoder3 = 0;
  long unsigned int encoder4 = 0;
  Wire.beginTransmission(42);
  Wire.write("i");
  Wire.endTransmission();
  delay(1);
  Wire.requestFrom(42,8);
  delay(10);
  //if(Wire.available()==8)
  {
    encoder1 = (long unsigned int) Wire.read();
    encoder1 += ((long unsigned int) Wire.read() <<8);
    encoder1 += ((long unsigned int) Wire.read() <<16);
    encoder1 += ((long unsigned int) Wire.read() <<24);
    encoder2 = (long unsigned int) Wire.read();
    encoder2 += ((long unsigned int) Wire.read() <<8);
    encoder2 += ((long unsigned int) Wire.read() <<16);
    encoder2 += ((long unsigned int) Wire.read() <<24);
  }
  encoder1Value = encoder1;
  encoder2Value = encoder2;
  Wire.requestFrom(42,8);
  delay(10);
  //if(Wire.available()==8)
  {
    encoder3 = (long unsigned int) Wire.read();
    encoder3 += ((long unsigned int) Wire.read() <<8);
    encoder3 += ((long unsigned int) Wire.read() <<16);
    encoder3 += ((long unsigned int) Wire.read() <<24);
    encoder4 = (long unsigned int) Wire.read();
    encoder4 += ((long unsigned int) Wire.read() <<8);
    encoder4 += ((long unsigned int) Wire.read() <<16);
    encoder4 += ((long unsigned int) Wire.read() <<24);
  }
  encoder3Value = encoder3;
  encoder4Value = encoder4;  
}

