#include <TimerOne.h>
#include <ColorRecognition.h>
#include <ColorRecognitionTCS230.h>

void setup() {
  Serial.begin(9600);
  
  ColorRecognitionTCS230* tcs230 = ColorRecognitionTCS230::getInstance();
  tcs230->initialize(2, 3, 4);
  
  Serial.print("Adjusting the white balance... show something white to the sensor.");
  
  // Show something white to it during 4 seconds.
  tcs230->adjustWhiteBalance();
  
  while (1) {
    Serial.print("Red: ");
    Serial.println(tcs230->getRed());
    Serial.print("Green: ");
    Serial.println(tcs230->getGreen());
    Serial.print("Blue ");
    Serial.println(tcs230->getBlue());
    delay(3000);
  }
}

void loop() {
}
