#define StepperCoilA 6
#define StepperCoilB 9
#define StepperCoilC 10
#define StepperCoilD 11

float f, e, g, i, k;

float h;

float j;

float l;

int a,b,c,d;

void setup() 
{
  pinMode(StepperCoilA, OUTPUT);
  pinMode(StepperCoilB, OUTPUT);
  pinMode(StepperCoilC, OUTPUT);
  pinMode(StepperCoilD, OUTPUT);
  Serial.begin(9600);
}

void Full_step_mode() 
{
  digitalWrite(StepperCoilA, HIGH);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, HIGH);
  delay(5);

  digitalWrite(StepperCoilA, HIGH);
  digitalWrite(StepperCoilB, HIGH);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, LOW);
  delay(5);

  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, HIGH);
  digitalWrite(StepperCoilC, HIGH);
  digitalWrite(StepperCoilD, LOW);
  delay(5);

  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, HIGH);
  digitalWrite(StepperCoilD, HIGH);
  delay(5);
}

void Wave_drive_mode()
{
  digitalWrite(StepperCoilA, HIGH);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, LOW);
  delay(5);
  
  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, HIGH);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, LOW);
  delay(5);
  
  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, HIGH);
  digitalWrite(StepperCoilD, LOW);
  delay(5);
  
  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, HIGH);
  delay(5);
}

void Half_step_mode() 
{
  digitalWrite(StepperCoilA, HIGH);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, HIGH);
  delay(1.25);

  digitalWrite(StepperCoilA, HIGH);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, LOW);
  delay(1.25);

  digitalWrite(StepperCoilA, HIGH);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, LOW);
  delay(1.25);

  digitalWrite(StepperCoilA, HIGH);
  digitalWrite(StepperCoilB, HIGH);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, LOW);
  delay(1.25);
  
  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, HIGH);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, LOW);
  delay(1.25);

  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, HIGH);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, LOW);
  delay(1.25);

  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, HIGH);
  digitalWrite(StepperCoilC, HIGH);
  digitalWrite(StepperCoilD, LOW);
  delay(1.25);

  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, HIGH);
  digitalWrite(StepperCoilD, LOW);
  delay(1.25);

  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, HIGH);
  digitalWrite(StepperCoilD, LOW);
  delay(1.25);

  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, HIGH);
  digitalWrite(StepperCoilD, HIGH);
  delay(1.25);

  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, HIGH);
  delay(1.25);

  digitalWrite(StepperCoilA, LOW);
  digitalWrite(StepperCoilB, LOW);
  digitalWrite(StepperCoilC, LOW);
  digitalWrite(StepperCoilD, HIGH);
  delay(1.25);
}

void microstepping_v1() 
{
  for(a=255; a>=0; a--) {
    b++;
  }

  for(b=255; b>=0; b--) {
    a++;
  }

  analogWrite(StepperCoilA, a);
  analogWrite(StepperCoilB, 0);
  analogWrite(StepperCoilC, 0);
  analogWrite(StepperCoilD, b);
  delay(5);

  analogWrite(StepperCoilA, a);
  analogWrite(StepperCoilB, b);
  analogWrite(StepperCoilC, 0);
  analogWrite(StepperCoilD, 0);
  delay(5);

  analogWrite(StepperCoilA, 0);
  analogWrite(StepperCoilB, a);
  analogWrite(StepperCoilC, b);
  analogWrite(StepperCoilD, 0);
  delay(5);

  analogWrite(StepperCoilA, 0);
  analogWrite(StepperCoilB, 0);
  analogWrite(StepperCoilC, a);
  analogWrite(StepperCoilD, b);
  delay(5);
}

void microstepping_v2() {
  for(a = 0; a<25; a++)

  {

    e= a/25.00;

    f = sin(e*3.1*2);

   

    g= (a+5)/20.00;

     h = sin(g*3.1*2);

     

    i= (a+10)/20.00;

     j = sin(i*3.1*2);

      

    k= (a+15)/20.00;

     l = sin(k*3.1*2);

    if(f<0){

      f=0;

    }

    if(h<0){

      h=0;

    }

    if(j<0){

      j=0;

    }

    if(l<0){

      l=0;

    }

   

    Serial.print(l);

    Serial.print('\n');
    
    analogWrite(StepperCoilA, f*255);
    analogWrite(StepperCoilB, h*255);
    analogWrite(StepperCoilC, j*255);
    analogWrite(StepperCoilD, l*255);
    delay(0.5);
  }
}

void loop() 
{
  microstepping_v2();
}
