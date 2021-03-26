const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int Hall_effect_pin = A3;

const int analogOutPin = 9; // Analog output pin that the LED is attached to

// const int WaveTestOne = 3;
//const int WaveTestTwo = 5;
//const int WaveTestThree = 6;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

int wave1 = 0;
int wave2 = 0;
int wave3 = 0;

int Hall = 0;

int RPM = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  pinMode(Hall_effect_pin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 100, 200);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  Hall = analogRead(Hall_effect_pin); 

  Serial.print("\t Hall_effect = ");
  Serial.println(Hall);
  

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
