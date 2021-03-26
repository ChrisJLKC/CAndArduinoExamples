void intialisation() {
     // init vars
    float Max_Speed = 1.0;
    
    //Configure the terminal to high speed
    terminal.baud(115200);
    L_Direction = 0; // init forwards
    L_PWM.period_ms(4);  // init 250Hz Freq
    L_PWM.write(0.1f); // start 0 duty cycle
    
    while (L_HE1 == 0);
    while (L_HE1 == 1);
    L_PWM.write(0.0f);
    
    R_Direction = 0;
    R_PWM.period_ms(4);
    R_PWM.write(0.1f);
    
    while (R_HE1 == 0);
    while (R_HE1 == 1);
    R_PWM.write(0.0f);
    
    //Wait for USER button (blue pull-down switch) to start
    terminal.puts("Press USER button to start\r\n");
    led = 0;
    while (START_BUTTON);
    
    // Start
    led = 1;
    
    //timer.start(); // continue timer
    //timer.read_us(); // read timer in us
    //timer.stop(); // pause/stop timer
    //timer.reset(); // set timer to 0
    
    timer.start(); // continue timer
    
}