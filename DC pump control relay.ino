////LIQUID HANDLINGT/////////////
//By Abd Almonem Doolaanea maker4ir@gmail.com
//Liked to the course: https://www.udemy.com/course/diy-lab-equipment-with-arduino-part-3-liquid-handling

//Use ESP32

/////Code to control DC motor pump as On and OFF with relay module/////

#define pump_pin 17

void setup() {

Serial.begin(115200);
Serial.println("Pump program started");

pinMode(pump_pin, OUTPUT);
digitalWrite(pump_pin, HIGH); //low level trigger relay

}

void loop() {
  //ON the pump
digitalWrite(pump_pin, LOW);
delay(2000);

//OFF the pump
digitalWrite(pump_pin, HIGH);
delay(2000);

}
