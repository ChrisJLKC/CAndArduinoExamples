#include "mbed.h"
#include "Move-Buggy.c"
#include "Move_Wheel_Dist.c"
#include "intialisation.c"

DigitalOut led(LED1);
 
//Motors
PwmOut L_PWM(PA_8);
PwmOut R_PWM(PB_4);
DigitalOut L_Direction(PA_9); // 0 = Forwards, 1 = Backwards
DigitalOut R_Direction(PB_10);// 0 = Forwards, 1 = Backwards
 
//Hall-Effect Sensor Inputs
DigitalIn L_HE1(PB_2);
DigitalIn L_HE2(PB_1);
DigitalIn R_HE1(PB_14);
DigitalIn R_HE2(PB_15);

//On board switch
DigitalIn START_BUTTON(USER_BUTTON);

//Use the serial object so we can use higher speeds
Serial terminal(USBTX, USBRX);

Timer timer;

float gap_between_wheels = 13; // in cm

extern struct wheelDist();
extern struct MoveWheels();
extern void execute_move();

int main()
{
    extern void intialisation();
          
    Struct result; 
    while(1){
    result = MoveWheels(80.0,0); // (Distance, Angle)
    execute_move(result.left,result.right,Max_Speed);
    result = MoveWheels(0.0,90); // (Distance, Angle)
    execute_move(result.left,result.right,Max_Speed);
    result = MoveWheels(80.0,0); // (Distance, Angle)
    execute_move(result.left,result.right,Max_Speed);
    result = MoveWheels(0.0,90); // (Distance, Angle)
    execute_move(result.left,result.right,Max_Speed);
    result = MoveWheels(80.0,0); // (Distance, Angle)
    execute_move(result.left,result.right,Max_Speed);
    result = MoveWheels(0.0,90); // (Distance, Angle)
    execute_move(result.left,result.right,Max_Speed);
    result = MoveWheels(80.0,0); // (Distance, Angle)
    execute_move(result.left,result.right,Max_Speed);
    result = MoveWheels(0.0,90); // (Distance, Angle)
    execute_move(result.left,result.right,Max_Speed);
    }
}