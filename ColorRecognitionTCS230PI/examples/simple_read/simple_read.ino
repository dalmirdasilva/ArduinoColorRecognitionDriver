#include <ColorRecognition.h>
#include <ColorRecognitionTCS230PI.h>

void setup() {

  Serial.begin(9600);
  
  ColorRecognitionTCS230PI tcs230(2, 3, 4);
  
  Serial.println("Adjust white color, show something white to the sensor and press y."); 
  while(!Serial.available() && Serial.read() != 'y');
  Serial.read(); // just read the 'enter'
  Serial.println("Adjusting...");
  tcs230.adjustWhiteBalance();
  
  Serial.println("Adjust black color, show something black to the sensor and press y."); 
  while(!Serial.available() && Serial.read() != 'y');
  Serial.read(); // just read the 'enter'
  Serial.println("Adjusting...");
  tcs230.adjustBlackBalance();
  
  while (1) {
    Serial.print("Read: ");
    Serial.println(tcs230.getRed());
    Serial.print("Green: ");
    Serial.println(tcs230.getGreen());
    Serial.print("Blue ");
    Serial.println(tcs230.getBlue());
    delay(3000);
  }
}

void loop() {
}