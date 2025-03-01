#include <Servo.h>

int buttonUP = 0;
int buttonDOWN = 0;
int buttonSTOP = 0;

int posUP = 180;    // Move to 180° when UP is pressed
int posDOWN = 0;    // Move to 0° when DOWN is pressed
int posSTOP = 90;   // Move to 90° when STOP is pressed (neutral position)

Servo servo_10;

void setup() {
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
  servo_10.attach(10, 500, 2500);

  // Initialize the servo to the STOP position
  servo_10.write(posSTOP);
}

void loop() {
  buttonUP = digitalRead(4);
  buttonDOWN = digitalRead(3);
  buttonSTOP = digitalRead(8);

  Serial.print("UP: ");
  Serial.println(buttonUP);
  Serial.print("DOWN: ");
  Serial.println(buttonDOWN);
  Serial.print("STOP: ");
  Serial.println(buttonSTOP);

  if (buttonUP == HIGH) {
    servo_10.write(posUP);
  } 
  else if (buttonDOWN == HIGH) {
    servo_10.write(posDOWN);
  } 
  else if (buttonSTOP == HIGH) {
    servo_10.write(posSTOP);
  }

  delay(10); // Small delay to prevent bouncing issues

  //All kod har blivit direkt kopierad och duplicerad från Arduino IDE, vissa saker må inte fungera i C++