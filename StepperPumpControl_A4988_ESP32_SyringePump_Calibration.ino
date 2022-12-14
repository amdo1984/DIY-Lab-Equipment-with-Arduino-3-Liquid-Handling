////LIQUID HANDLINGT/////////////
//By Abd Almonem Doolaanea maker4ir@gmail.com
//Liked to the course: https://www.udemy.com/course/diy-lab-equipment-with-arduino-part-3-liquid-handling

//Use ESP32

/////Code to control stepper motor pump flow rate by changing the motor speed using A4988 driver - add calibrator and Bluetooth control/////

#include <AccelStepper.h>

#define pump1_STEP_PIN 17
#define pump1_DIR_PIN 16
#define pump1_ENABLE_PIN 25
AccelStepper pump1(AccelStepper::DRIVER, pump1_STEP_PIN, pump1_DIR_PIN);

int pump1_speed = 0;        // speed as step/sec
float calibrator = 0.0192;  //1 step/sec = 0.0192 mL/min
float flow_rate = 2;        // mL/min

// void PUMP_W(){
// pump1.moveTo(1);
// pump1.setSpeed(Xspeed);
// pump1.run();
// pump1.setCurrentPosition(0);
// pump1.setSpeed(Xspeed);
// }
//////BL/////////////
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
String message = "";
/////////////////

void setup() {
  Serial.begin(115200);
  pinMode(pump1_STEP_PIN, OUTPUT);
  pinMode(pump1_DIR_PIN, OUTPUT);
  pinMode(pump1_ENABLE_PIN, OUTPUT);
  digitalWrite(pump1_ENABLE_PIN, LOW);

  //calculate the pump speed from flow rate and calibrator
  pump1_speed = flow_rate / calibrator;

  pump1.setMaxSpeed(pump1_speed);
  pump1.setAcceleration(1000);
  pump1.setSpeed(pump1_speed);

  //BL
  SerialBT.begin("FlowControl");  //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  //for calibration
  //pump1.runToNewPosition(2000);//this is blocking intruction, the pump will stop after the number of steps
}

void loop() {

  // Input the flow rate using Bluetooth, can be changed during operation
  if (SerialBT.available()) {
    message = SerialBT.readString();
    flow_rate = message.toFloat();
    pump1_speed = flow_rate / calibrator;
    pump1.setMaxSpeed(pump1_speed);
    pump1.setAcceleration(1000);
    pump1.setSpeed(pump1_speed);
  }

  //PUMP_W();
  // Input the flow rate using Bluetooth, can be changed during operation
  pump1.runSpeed();
  ////Stopping the motor after specific duration
  // if (millis()> 60000)
  // {
  //   digitalWrite(pump1_ENABLE_PIN, HIGH);
  // }
}
