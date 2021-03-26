const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int Hall_effect_pin = A1;

const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

float Wave_A = 0;
float Wave_B = 0;
float Wave_C = 0;
float x = 0;

float g = 0;
float h = 0;
float i= 0;

int Hall = 0;
int RPM = 0;
int b = 0;
int c = 0;
int a = 0;
int d;
int e;

void setup() {
  // initialize serial communications at 9600 bps:
  pinMode(Hall_effect_pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void Hall_effect() {
  Hall = analogRead(Hall_effect_pin); 

  if((Hall > 800) && (a < 1)) {
    a++;
  }
  
  else if((Hall < 200) && (a == 1)){
    a = 0;
    c++;
  }
 
  d++;
  
  if(d>50){
    e = (c - b)*60/14*10;
    d = 0;
    b=c;
  }
}

void Back_EMF_processing() {
  Wave_A = e/5*sin(x*e/300);
  Wave_B = e/5*sin((x*e/300)+2);
  Wave_C = e/5*sin((x*e/300)+4);
  
  x += 0.1;
  Serial.print(Wave_A);
  Serial.print(",");
  Serial.print(Wave_B);
  Serial.print(",");
  Serial.print(Wave_C);
  Serial.print(",");
  Serial.print(e);
  Serial.print(",");
}

void Active_Phase_processing() {

  if(0.6<sin(x*e/300)){
    g = 0.6;
  }
  else if(-0.6>sin(x*e/300)){
    g = -0.6;
  }
  else{g = sin(x*e/300);}

  if(0.6<sin(x*e/300+2)){
    h = 0.6;
  }
  else if(-0.6>sin(x*e/300+2)){
    h = -0.6;
  }
  else{h = sin(x*e/300+2);}

  if(0.6<sin(x*e/300+4)){
    i = 0.6;
  }
  else if(-0.6>sin(x*e/300+4)){
    i = -0.6;
  }
  else{i = sin(x*e/300+4);}
  
  Serial.print((e/5*g) - 500);
  Serial.print(",");
  Serial.print((e/5*h) - 1000);
  Serial.print(",");
  Serial.println((e/5*i) - 1500);
}

void loop() {
  
  sensorValue = analogRead(analogInPin);
  
  outputValue = map(sensorValue, 0, 1023, 100, 200);
  
  analogWrite(analogOutPin, outputValue);

  Hall_effect();
  Back_EMF_processing();
  Active_Phase_processing();

  delay(2);
}
