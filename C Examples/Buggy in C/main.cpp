#include "mbed.h"
#include "motor.h"
//#include "ultrasonic.h"

float TRIG_PIN = A0;
float ECHO_PIN = A1;

Serial pc(USBTX,USBRX); 


DigitalIn microswitch1(D4);       //Instance of the DigitalIn class called 
//'microswitch1'
DigitalIn microswitch2(D3);       //Instance of the DigitalIn class called 
//'microswitch2'

//Instance of the Motor Class called 'Wheel' 
//see motor.h and motor.cpp

DigitalIn myButton(USER_BUTTON);  //USER_BUTTON is the Blue Button on the NUCLEO
// Board



Motor Wheel(D15,D14,D13,D12); //Instance of the Motor Class called 'Wheel' 
//see motor.h and motor.cpp

#define TIME_PERIOD 2             //Constant compiler Values here 2 equates to
// 2ms or 500Hz base Frequency
#define DUTY 0.9                  //DUTY of 1.0=100%, 0.4=40% etc.,
int countt = 0; //creates varible countt


float TurnMoveV;
float LmotorV = 0;
float RmotorV = 0;
float MeasureDistanceV;
float speedMV;
float Timefor;
float DistanceV = 0;

float MeasureDistance()
{
    
    unsigned long start_time, end_time, pulse_time;

    TRIG_PIN = 1;
    wait_us(10);
    TRIG_PIN = 0;

    while(ECHO_PIN == 0);

    while(ECHO_PIN == 1);
    pulse_time = end_time - start_time;

    if (pulse_time > 23200)
    {
        pulse_time = 23200;
    }

    float dist_mm = pulse_time / 5.8;
    float dist_cm = pulse_time / 58.0;
    float dist_in = pulse_time / 148.0;

    wait_us(60);

    return dist_mm; 
}




void MoveForward()
{
    //while distance from the wall is under a certain amount we want the buggy 
    //to drive forward and to stop the minimum distance from the wall so it can 
    //turn with the scoop pushing as many beads as possible away from the wall
    
    if ( RmotorV == 0 && LmotorV == 0) //runs code if both motors variable = 0
    {
        //move until 7.5cm from wall
        DistanceV = MeasureDistance();
        while (DistanceV > 7.501); // runs code inside while loop until distance is less than 7.5cm from wall
        { 
            Wheel.Speed(1.0f, 1.0f);//runs the motors at full power      /////////////////
            DistanceV = MeasureDistance(); //recalculates distance from wall
        }
        Wheel.Speed(0.0f, 0.0f);//stops motors      //////////////////////////////////////////////////
    }
    else if ( RmotorV == 0)//runs if the above if wasnt true
    {
        Timer BuggyMove; //creates timer 
        BuggyMove.start(); //starts the timer
        float timee;//creates variable timee
        timee = BuggyMove.read(); //records time in timer and records it in timee variable
        while (timee < LmotorV) //runs everything in the while until timee is bigger than turnmovet
        {
            Wheel.Speed(-1.0f, 1.0f);//runs the motor       ///////////////////////////////////
            timee = BuggyMove.read(); //records timer value in timee
        }
        Wheel.Speed(0.0f, 0.0f);//stops motors      /////////////////////////////////////////////
           
    }
    else if ( LmotorV == 0)
    {
    Timer BuggyMove; //creates timer 
        BuggyMove.start(); //starts the timer
        float timee;//creates variable timee
        timee = BuggyMove.read(); //records time in timer and records it in timee variable
        while (timee < RmotorV) //runs everything in the while until timee is bigger than turnmovet
        {
            Wheel.Speed(1.0f, -1.0f);//runs the motor       ///////////////////////////////////
            timee = BuggyMove.read(); //records timer value in timee
        }
        Wheel.Speed(0.0f, 0.0f);//stops motors      /////////////////////////////////////////////
        
    }   
}

void SpeedM()
{
    //measure speed of buggy from how far it is from the wall using a timer and
    //distance sensor then calculate how long to move forward after turn to 
    //to travel 7.5cm
    Timer T; //
    float StartDist = DistanceV;  //
    float EndDist;  //
    float timing ;  //
    T.start();  //
    while (timing < 1.0)  //
    {
        timing = T.read(); //measure time and record
        EndDist = DistanceV; //measure distance and record it
        
        }
    T.stop();
    float distPS;
    distPS = EndDist - StartDist;
    
    float A;
    A = distPS/speedMV;
   
    Timefor = timing/A;
    
}


void Lturn()
{
    //once closest proximity to wall is reached we want the buggy to turn 90
    //degrees move forward then turn 90 degrees again 
    speedMV = 11.78;
    SpeedM();
    LmotorV = Timefor;
    MoveForward();//calls forward and runs motors for Turnmovet amount of time
    countt = countt + 1;
    
    }
    
void Rturn()  
{
    
    //once closest proximity to wall is reached we want the buggy to turn -90
    //degrees move forward then turn -90 degrees again 
    speedMV = 11.78;
    SpeedM();
    RmotorV = Timefor;
    MoveForward();  
    countt = countt + 1;
    
    }
    
    
    


void Backwards()
{
    //once beads have been pushed up against the barrior the back scoop will 
    //push them over to the other side.
    float timeF = 0;
    Timer R;
    R.start();
    while (timeF < 1.0f)
    {
        Wheel.Speed(1.0f, 0.8f);
        timeF = R.read();
    }
    R.stop();
    R.reset();
    while (1)
    {
        Wheel.Speed(-1.0f, -1.0f);   
    }
}

  

int main() {
    
    pc.baud(9600);               //BAUD Rate to 9600
    pc.printf("ROCO104 Demonstration Robot Buggy Plymouth University 2018/19\n\r");

    Wheel.Period_in_ms(TIME_PERIOD);//Set frequency of the PWMs
  
    Wheel.Stop();
    
    while(1)
    {
    
    while(DistanceV > 1);   //repeats while distance from wall is greater than 1
    {
        
        MoveForward(); //calls move forward function //////////////////////
        DistanceV = MeasureDistance();
    } 
    if ( countt == 0)   { //does the statements inside the if if count is equal to 0
        Rturn();
        
    }
    else if (countt == 2 || countt == 4) //does the statements inside the if if count is even 
    {
        Rturn();
        
    }
    else if (countt == 6)
    {
        Backwards();   
    }
    else //carries out code when neither if statement is true
    {
        Lturn();
        
    }
    }
}
    

    