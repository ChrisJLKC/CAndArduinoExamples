#define ServoPinSignal 4
#define myJoystick 0

int midpoint = 495;
int joystick;

// Pulses duration: 600 - 0deg; 1450 - 90deg; 2300 - 180deg
// All pulses have to add up to 20000 microseconds

void setup() 
{
  pinMode(ServoPinSignal, OUTPUT);
  Serial.begin(9600);
}

void Servo_move() 
{ 
  if(joystick >= 600)
  {
    digitalWrite(ServoPinSignal, HIGH);
    delayMicroseconds(500);
    
    digitalWrite(ServoPinSignal, LOW);
    delayMicroseconds(19500);
    
    delay(10);
  }
  
  else if(joystick <= 400)
  {
    digitalWrite(ServoPinSignal, HIGH);
    delayMicroseconds(2500);
    
    digitalWrite(ServoPinSignal, LOW);
    delayMicroseconds(17500);
    
    delay(10);
  }
  
  else
  {
    digitalWrite(ServoPinSignal, HIGH);
    delayMicroseconds(1450);
    
    digitalWrite(ServoPinSignal, LOW);
    delayMicroseconds(18550);
    
    delay(10);
  }
  
} 

void Joystick_Value()
{
  joystick = analogRead(myJoystick);
  
  Serial.print(joystick);
  Serial.print("\n");
}

void loop() 
{
  Joystick_Value();
  Servo_move();
}
