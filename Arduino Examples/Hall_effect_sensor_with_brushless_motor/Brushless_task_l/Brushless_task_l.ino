const int Hall_effect_pulse = A0;

const int ESC_Pulse_pin = 9;

int Hall_Val = 0;
int Pulse = 0;

int i;
int j;
int k = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ESC_Pulse_pin, OUTPUT);
  Serial.begin(9600);
}

void digital_pulse(float ESC_pulse_size) {
  digitalWrite(ESC_Pulse_pin, HIGH);
  delay(ESC_pulse_size);
  digitalWrite(ESC_Pulse_pin, LOW);
  delay(20 - ESC_pulse_size);
}

void config_arming() {
  for(i=0; i=2000; i++) {
    digital_pulse(2.0);
  }

  for(j=0; j=2000; i++) {
    digital_pulse(1.0);
  } 
}

void High_speed() {
  digital_pulse(1.8); 
}

void Medium_speed() {
  digital_pulse(1.5);
}

void Low_speed() {
  digital_pulse(1.2);
}

void loop() {
  // put your main code here, to run repeatedly
  Hall_Val = analogRead(Hall_effect_pulse);
  Pulse = digitalRead(ESC_Pulse_pin);
  
  while(k = 0) {
    config_arming();
  }

  Medium_speed();

  //Serial.print(Hall_Val);
  //Serial.print(",");
  Serial.println(Pulse);
  
  k++;
}
