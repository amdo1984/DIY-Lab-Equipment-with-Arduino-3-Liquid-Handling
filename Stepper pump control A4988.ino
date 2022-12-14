////LIQUID HANDLINGT/////////////
//By Abd Almonem Doolaanea maker4ir@gmail.com
//Liked to the course: https://www.udemy.com/course/diy-lab-equipment-with-arduino-part-3-liquid-handling

//Use ESP32

/////Code to control stepper motor pump flow rate by changing the motor speed using A4988 driver/////

#include <AccelStepper.h>

#define pump1_STEP_PIN 17
#define pump1_DIR_PIN 16
#define pump1_ENABLE_PIN 25
AccelStepper pump1(AccelStepper::DRIVER, pump1_STEP_PIN, pump1_DIR_PIN);
int Xspeed = 200;

// void PUMP_W(){
// pump1.moveTo(1);
// pump1.setSpeed(Xspeed);
// pump1.run();
// pump1.setCurrentPosition(0);
// pump1.setSpeed(Xspeed);
// }

void setup() {
  Serial.begin(115200);
  pinMode(pump1_STEP_PIN, OUTPUT);
  pinMode(pump1_DIR_PIN, OUTPUT);
  pinMode(pump1_ENABLE_PIN, OUTPUT);
  digitalWrite(pump1_ENABLE_PIN, LOW);
  pump1.setMaxSpeed(1000);
  pump1.setAcceleration(1000);
  pump1.setSpeed(Xspeed);
}

void loop() {
  //PUMP_W();
  //Run the pump continuously at constant speed
  pump1.runSpeed();

  ////Stopping the motor after specific duration
  // if (millis()> 5000)
  // {
  //   digitalWrite(pump1_ENABLE_PIN, HIGH);
  // }  
}
