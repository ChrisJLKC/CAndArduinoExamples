struct wheelDist { 
    float left, right; 
}; 
typedef struct wheelDist Struct; 

struct MoveWheels(float distance, float angle){
    Struct s;
    angle = -angle*1.05;
    if (angle == 0){
        s.left = distance;
        s.right = distance;
        return s;
    }
    else{
        float r1 = (360*distance)/(2*3.14159*angle);
        float r0 = r1 - (gap_between_wheels)/2;
        float r2 = r1 + (gap_between_wheels)/2;
        float s0 = 2 * 3.14159 * r0 * (angle/360);
        float s2 = 2 * 3.14159 * r2 * (angle/360);
        s.left = s0;
        s.right = s2;
        return s;
    }
}