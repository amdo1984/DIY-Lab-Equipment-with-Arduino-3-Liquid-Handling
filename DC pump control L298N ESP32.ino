////LIQUID HANDLINGT/////////////
//By Abd Almonem Doolaanea maker4ir@gmail.com
//Liked to the course: https://www.udemy.com/course/diy-lab-equipment-with-arduino-part-3-liquid-handling

//Use ESP32

/////Code to control DC motor pump flow rate by changing the motor speed using L298N driver/////

// Pump A connections
#define enA 25
#define in1 16
#define in2 17
// Pump B connections
#define enB 26
#define in3 18
#define in4 19

//Setting Analog write in ESP32
// use first channel of 16 channels (started from zero)
#define LEDC_CHANNEL_0 0

// use 13 bit precission for LEDC timer
#define LEDC_TIMER_13_BIT 13

// use 5000 Hz as a LEDC base frequency
#define LEDC_BASE_FREQ 5000

void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax = 255) {
  // calculate duty, 8191 from 2 ^ 13 - 1
  uint32_t duty = (8191 / valueMax) * min(value, valueMax);

  // write duty to LEDC
  ledcWrite(channel, duty);
}

void setup() {

  Serial.begin(115200);
  Serial.println("Pump program started");

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);

  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(enA, LEDC_CHANNEL_0);  //connect enable pin A (first motor) to the channel 0 of PWM
}

void loop() {
  //ON the pump in one direction at full speed
  ledcAnalogWrite(LEDC_CHANNEL_0, 255); //speed ranges from 0 to 255
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(2000);
  // OFF the pump
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);

  //ON the pump in the opposite direction at different speed
  ledcAnalogWrite(LEDC_CHANNEL_0, 200);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(2000);
}
