void execute_move(float leftDist,float rightDist, float Max_Speed){ // in cm
    bool L_HE1_old = 0;
    bool R_HE1_old = 0;
    if (leftDist < 0){
        L_Direction = 1;
        leftDist = -leftDist;
    } else {L_Direction = 0;}                                     // 20.8 shaft rotations per wheel rotations
    if (rightDist < 0){                                           // whole rotation has 63 pulses
        R_Direction = 1;                                          // Every 63 pulses = C distance (c = circumference)
        rightDist = -rightDist;                                   // 1 pulse = c/63 
                                                                  // diameter of wheel is 56mm.
    } else {R_Direction = 0;}                                     // 2 x pi x r = c = 175.92mm
                                                                  // 1 pulses = 175.92 / 63 =  2.792 mm 
    float remainingLeftDist = leftDist;                           // seperate functions in seperate files using declarations in C and specify if
    float remainingRightDist = rightDist;                         // it is an interger or a string.
    R_PWM.write(Max_Speed);                                       // int resolution  = 2.792;
    L_PWM.write(Max_Speed);                                       // int pulses_to_count = (int)(amount / 2.792);
    while (remainingLeftDist > 0 || remainingRightDist > 0){      // set wheels to 1
        if (L_HE1 != L_HE1_old){                                  // if (pulses == amount_worked_pulses) {  set wheels to 0f
            remainingLeftDist = remainingLeftDist - 0.143485f;    // tell the motor to reduce the amount of voltage over time once near          
            L_HE1_old = L_HE1;                                    // destination.
        }                                                         // look at nicks code to see how he counts the pulses.
        else if (R_HE1 != R_HE1_old){                             // then plus the amount of pulses by 1, with (variable)++
            remainingRightDist = remainingRightDist - 0.143485f;
            R_HE1_old = R_HE1;
        }
        if (remainingLeftDist < 2 || remainingRightDist < 2){ // in need of testing
            Max_Speed = Max_Speed * 0.9;
        }
        if (remainingLeftDist < remainingRightDist){
            R_PWM.write(Max_Speed);
            L_PWM.write(Max_Speed * (remainingLeftDist/remainingRightDist));
        }
        else if (remainingRightDist < remainingLeftDist){
            L_PWM.write(Max_Speed);
            R_PWM.write(Max_Speed * (remainingRightDist/remainingLeftDist));
        }
    }
    L_PWM.write(0.0f);
    R_PWM.write(0.0f);
    
}
