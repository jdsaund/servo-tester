# USB Servo Tester

USB powered, arduino-based servo tester that allows user to type pulse width into terminal where it will be fed into the servo

Basic feature list:

 * USB Powered
 * Based on [SparkFun Pro Micro - 5V/16MHz](https://www.sparkfun.com/products/12640)
 * Starts with 1500us (mid) pulse width by default
 * User-defined pulse widths via serial monitor with live update
 * 1000 to 2000us pulse widths allowed
 * Perfect for RC helicopter setup

### How to use:

 * Connect servo to cable
 * Connect USB cable between Servo Tester and computer
 * Servo will now rapidly move to its mid point
 * If you just need to check the mid-point of the servo you can stop here
 * Install Arduino IDE and drivers
 * Open serial monitor in Arduino IDE
 * Type in value between 1000 and 2000 and hit enter

