#define analogInPin  A0 

#define JoystickCenterValue 506 

#define EnableL293D 7  

#define MotorSideA 6 

#define MotorSideB 5  

  

int joystickXValue = 0; 

  

void setup()  {  

pinMode(MotorSideB, OUTPUT);  

pinMode(MotorSideA, OUTPUT);  

pinMode(EnableL293D, OUTPUT);  

Serial.begin(9600);  

}  

  

void loop()  {  

digitalWrite(EnableL293D,HIGH); 

joystickXValue = analogRead(analogInPin);  

delay(80); 

Serial.print("\njoystick X value = ");  

Serial.print(joystickXValue);  

int val = analogRead(0); 

val = map(val, 0, 1020, 0, 255); 

int BVal = 255 - val; 

Serial.print("\tmapped output = ");  

Serial.print(val);  

Serial.print("\tPWM for other direction = "); 

Serial.print(BVal);  

  

if(joystickXValue<JoystickCenterValue)  {  

  

digitalWrite(MotorSideA, HIGH); 

delay(BVal); 

digitalWrite(MotorSideA, LOW); 

delay(val); 

digitalWrite(MotorSideB,LOW);   

  

}else if(joystickXValue>JoystickCenterValue){  

  

digitalWrite(MotorSideA, HIGH); 

delay(BVal); 

digitalWrite(MotorSideA, LOW); 

delay(val); 

digitalWrite(MotorSideA,LOW);  

  

}else{  

  

digitalWrite(MotorSideA,LOW);   

digitalWrite(MotorSideB,LOW);  

} 

} 
