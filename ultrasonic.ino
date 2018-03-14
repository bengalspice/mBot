#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);
void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
          leftSpeed = speed;
          rightSpeed = speed;
      }else if(direction == 2){
          leftSpeed = -speed;
          rightSpeed = -speed;
      }else if(direction == 3){
          leftSpeed = -speed;
          rightSpeed = speed;
      }else if(direction == 4){
          leftSpeed = speed;
          rightSpeed = -speed;
      }
      motor_9.run((9)==M1?-(leftSpeed):(leftSpeed));
      motor_10.run((10)==M1?-(rightSpeed):(rightSpeed));
}
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeUltrasonicSensor ultrasonic_3(3);
double left;
double right;

void setup(){
    move(3,255);
    _delay(0.25);
    left = ultrasonic_3.distanceCm();
    move(4,255);
    _delay(0.5);
    right = ultrasonic_3.distanceCm();
    move(3,255);
    _delay(0.25);
    if((left) > (right)){
        move(3,255);
        _delay(0.25);
        move(1,0);
    }else{
        move(4,255);
        _delay(0.25);
        move(1,0);
    }
}

void loop(){
    if((ultrasonic_3.distanceCm()) < (8)){
        move(4,255);
        _delay(0.25);
    }else{
        motor_9.run((9)==M1?-(200):(200));
        motor_10.run((10)==M1?-(200):(200));
    }
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}
