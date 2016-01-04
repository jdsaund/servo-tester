#include <Servo.h>
 
Servo servo;

const int PIN_SERVO = 1;

String readString;
int pos = 1500;

void setup() {
  Serial.begin(9600);
  Serial.println("Servo test 0.1a");
  Serial.println("Enter pulse width (1000 to 2000)");

  servo.attach(PIN_SERVO);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    readString += c;
    delay(2);
  }

  if (readString.length() >0) {
    Serial.println(readString);
    int pos_temp = readString.toInt();
    
    if (pos_temp > 999 && pos_temp < 2001) {
      pos = pos_temp;
    } else {
      Serial.println("Enter a valid pulse width (1000 to 2000)");
    }
  }

  servo.writeMicroseconds(pos);
  readString="";
}
