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
double currentTime = 0;
double lastTime = 0;
double getLastTime(){
      return currentTime = millis()/1000.0 - lastTime;
}
MeBuzzer buzzer;

void setup(){
    for(int __i__=0;__i__<4;++__i__)
    {
        move(1,100);
        _delay(0.2);
        move(2,100);
        _delay(0.2);
    }
    for(int __i__=0;__i__<4;++__i__)
    {
        move(3,100);
        _delay(0.2);
        move(4,100);
        _delay(0.2);
    }
    for(int __i__=0;__i__<4;++__i__)
    {
        move(1,100);
        _delay(0.2);
        move(2,100);
        _delay(0.2);
        move(3,100);
        _delay(0.2);
        move(4,100);
        _delay(0.2);
    }
    move(1,0);
    buzzer.tone(262, 250);
    delay(20);
    buzzer.tone(294, 250);
    delay(20);
    buzzer.tone(330, 250);
    delay(20);
    buzzer.tone(262, 250);
    delay(20);
    buzzer.tone(262, 250);
    delay(20);
    buzzer.tone(294, 250);
    delay(20);
    buzzer.tone(330, 250);
    delay(20);
    buzzer.tone(262, 250);
    delay(20);
    buzzer.tone(330, 250);
    delay(20);
    buzzer.tone(349, 250);
    delay(20);
    buzzer.tone(392, 250);
    delay(20);
    _delay(0.3);
    buzzer.tone(330, 250);
    delay(20);
    buzzer.tone(349, 250);
    delay(20);
    buzzer.tone(392, 250);
    delay(20);
    _delay(0.3);
    buzzer.tone(392, 250);
    delay(20);
    buzzer.tone(440, 250);
    delay(20);
    buzzer.tone(392, 250);
    delay(20);
    buzzer.tone(349, 250);
    delay(20);
    buzzer.tone(330, 250);
    delay(20);
    buzzer.tone(262, 250);
    delay(20);
    buzzer.tone(392, 250);
    delay(20);
    buzzer.tone(440, 250);
    delay(20);
    buzzer.tone(392, 250);
    delay(20);
    buzzer.tone(349, 250);
    delay(20);
    buzzer.tone(330, 250);
    delay(20);
    buzzer.tone(262, 250);
    delay(20);
    buzzer.tone(262, 250);
    delay(20);
    buzzer.tone(220, 250);
    delay(20);
    buzzer.tone(262, 250);
    delay(20);
    _delay(0.3);
    buzzer.tone(262, 250);
    delay(20);
    buzzer.tone(220, 250);
    delay(20);
    buzzer.tone(262, 250);
    delay(20);
}

void loop(){
    motor_9.run((9)==M1?-(255):(255));
    motor_10.run((10)==M1?-(0):(0));
    _delay(1);
    motor_9.run((9)==M1?-(0):(0));
    motor_10.run((10)==M1?-(255):(255));
    _delay(1);
    if(((getLastTime())==(0))){
        motor_9.run((9)==M1?-(-100):(-100));
        motor_9.run((9)==M1?-(100):(100));
    }
    lastTime = millis()/1000.0;
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}
send encode mode
 binary mode  
