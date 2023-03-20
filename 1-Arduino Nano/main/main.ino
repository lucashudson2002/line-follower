#define SENSOR_MR A0
#define SENSOR_FR A1
#define SENSOR_R A2
#define SENSOR_C A3
#define SENSOR_L A4
#define SENSOR_FL A5
#define SENSOR_ML A6
#define LED 13
#define BUZZER 12
#define PWMA 11
#define AIN2 10
#define AIN1 9
#define STBY 8
#define BIN1 7
#define BIN2 6
#define PWMB 5
#define BTN 4
#define ENB1 3
#define ENA1 2

int pulse_A=0;
int pulse_B=0;

bool btn_control=0;

void encoderA()
{
  pulse_A++;
}

void encoderB(){
  pulse_B++;
}

bool readButton(const byte button, bool &control){
  if(!digitalRead(button)) 
    control = 1;
  if(digitalRead(button) && control)
  {
    control = 0;
    return true;
  } 
  return false;
}

void setup() {
  pinMode(SENSOR_MR, INPUT);
  pinMode(SENSOR_FR, INPUT);
  pinMode(SENSOR_R, INPUT);
  pinMode(SENSOR_C, INPUT);
  pinMode(SENSOR_L, INPUT);
  pinMode(SENSOR_FL, INPUT);
  pinMode(SENSOR_ML, INPUT);

  pinMode(BUZZER, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  digitalWrite(STBY, HIGH);

  pinMode(ENA1, INPUT);
  pinMode(ENB1, INPUT);

  attachInterrupt(digitalPinToInterrupt(ENA1), encoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENB1), encoderB, CHANGE);

  Serial.begin(9600);
}

void loop() {
  // Serial.print(analogRead(SENSOR_FL));
  // Serial.print(" ");
  // Serial.print(analogRead(SENSOR_L));
  // Serial.print(" ");
  // Serial.print(analogRead(SENSOR_C));
  // Serial.print(" ");
  // Serial.print(analogRead(SENSOR_R));
  // Serial.print(" ");
  // Serial.print(analogRead(SENSOR_FR));
  // Serial.println(" ");

  // Serial.print(analogRead(SENSOR_ML));
  // Serial.print(" ");
  // Serial.print(analogRead(SENSOR_MR));
  // Serial.println(" ");

  // digitalWrite(AIN1, LOW);
  // digitalWrite(AIN2, HIGH);
  // digitalWrite(BIN1, LOW);
  // digitalWrite(BIN2, HIGH);
  // analogWrite(PWMA, 50);
  // analogWrite(PWMB, 50);

  // Serial.println(pulse_A);
  // Serial.println(pulse_B);

  // if (readButton(BTN, btn_control))
  //   Serial.println("Apertou");
  
  delay(100);
}
