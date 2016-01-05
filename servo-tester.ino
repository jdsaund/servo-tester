#include <Servo.h>

#define defPos 1500
#define minPos 900
#define maxPos 2100
#define inputSize 6
 
Servo servo[8];
const byte pin[8] = {1,3,4,5,6,7,8,9};
int pos[8];

void setup() {
  Serial.begin(9600);
  Serial.println("Servo test 0.1a");
  Serial.println("Enter pulse width (1000 to 2000)");
  
  for (int i=0; i<8; i++){
    servo[i].attach(pin[i]);
    pos[i] = defPos;
    servo[i].writeMicroseconds(pos[i]);
    delay(100);
  }

delay(2000);
}

void loop() {
  
  char input[inputSize + 1];
  byte size = Serial.readBytes(input, inputSize);
  input[size] = 0;
  
  char* command = strtok(input, "&");
  while (command != 0) {
      // Split the command in two values
      char* separator = strchr(command, ':');
      if (separator != 0)
      {
          // Actually split the string in 2: replace ':' with 0
          *separator = 0;
          int servoId = atoi(command);
          ++separator;
          int posTemp = atoi(separator);
  
          // Do something with servoId and position
          Serial.print("Servo ID ");  Serial.print(servoId);  Serial.print(", PWM to ");  Serial.println(posTemp);
          
          if (servoId < 0 || servoId > 7) {
            Serial.print(servoId); Serial.println(" is not a valid servo ID (must be 1 to 8).");
          }
          
          if (posTemp < 900 || posTemp > 2100) {
            Serial.print("Limit reached for servo ");  Serial.println(servoId);
          }
          
          pos[servoId] = posTemp;
      }
      // Find the next command in input string
      command = strtok(0, "&");
  }
  
  for (int i=0; i<8; i++){
    pos[i] = constrain(pos[i], minPos, maxPos);
    servo[i].writeMicroseconds(pos[i]);
  }
}
