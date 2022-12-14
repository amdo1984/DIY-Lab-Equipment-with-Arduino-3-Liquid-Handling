////LIQUID HANDLINGT/////////////
//By Abd Almonem Doolaanea maker4ir@gmail.com
//Liked to the course: https://www.udemy.com/course/diy-lab-equipment-with-arduino-part-3-liquid-handling

//Use Arduino UNO

/////Code to control DC motor pump flow rate by changing the motor speed using L298N driver/////

// Pump A connections
#define enA 3 //PWM capable pin
#define in1 4
#define in2 5


void setup() {

  Serial.begin(115200);
  Serial.println("Pump program started");

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);


  digitalWrite(enA, HIGH);
 
}

void loop() {
  //ON the pump in one direction at fraction of full speed
  analogWrite(enA, 150); //the speed ranges from 0 to 255
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(2000);

  // OFF the pump
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);

  //ON the pump in the opposite direction at different speed
  analogWrite(enA, 200);  //the speed ranges from 0 to 255
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(2000);

  // OFF the pump
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);
}