const byte HALL_SENSOR = 2;
const int analogOutPin = 9; 

volatile int c = 0;
int d = 0;
int e = 0;
int b = 0;
float g = 0.000;
float h = 0.000;
float i = 0.000;
float x = 0.0;
int delay_val;
int startup_val;
int timer1_counter;
void setup()
{
  
  pinMode(analogOutPin, OUTPUT);
  // initialize timer1 
  Serial.begin(9600);
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  // Set timer1_counter to the correct value for our interrupt interval
  //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  timer1_counter = 3036;   // preload timer 65536-16MHz/256/2Hz
  
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts



  //Serial.begin(9600);
  pinMode(HALL_SENSOR, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(HALL_SENSOR), magnet_detect, CHANGE);//Initialize the intterrupt pin (Arduino digital pin 2)

  
}
ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
  TCNT1 = timer1_counter;   // preload timerseria
  b = (c- e)*60/14/2;
  e = c;
  
  d++;
}
void loop()
{
  startup_val++;
  if(120 > startup_val){delay_val = 2000;}
  else if (180 > startup_val){delay_val = 1000;}
  else if (startup_val > 220){delay_val = 1500;}

  else if ((b > 0) && (b <= 250)){delay_val = 1250;}
  else if ((b > 250) && (b <= 500)){delay_val = 1500;}
  else if ((b > 500) && (b <= 750)){delay_val = 1750;}
  else if ((b > 750) && (b <= 1000)){delay_val = 2000;}

  digitalWrite(analogOutPin, HIGH);
  delayMicroseconds(delay_val);
  digitalWrite(analogOutPin, LOW);
  delayMicroseconds(20000 - delay_val);

  delay(2);
  
  
  if(0.7<sin(x*b/300)){
    g = 0.7;
  }
  else if(-0.7>sin(x*b/300)){
    g = -0.7;
  }
  else{g = sin(x*b/300);}

  if(0.7<sin(x*b/300+2)){
    h = 0.7;
  }
  else if(-0.7>sin(x*b/300+2)){
    h = -0.7;
  }
  else{h = sin(x*b/300+2);}

  if(0.7<sin(x*b/300+4)){
    i = 0.7;
  }
  else if(-0.7>sin(x*b/300+4)){
    i = -0.7;
  }
  else{i = sin(x*b/300+4);}
  
  x+=0.1;
  Serial.print(b/5*g);
  Serial.print(",");
  Serial.print(b/5*h);
  Serial.print(",");
  Serial.print(b/5*i);
  Serial.print(",");
  Serial.println(b);

}

void magnet_detect()
{
  c++;
}
