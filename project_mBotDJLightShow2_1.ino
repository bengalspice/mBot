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
MeRGBLed rgbled_7(7, 7==7?2:4);
MeBuzzer buzzer;



void setup(){
    buzzer.tone(494, 250);
    delay(20);
    _delay(0.02);
    buzzer.tone(440, 250);
    delay(20);
    _delay(0.02);
    buzzer.tone(392, 250);
    delay(20);
    _delay(0.02);
    buzzer.tone(440, 250);
    delay(20);
    _delay(0.02);
    buzzer.tone(494, 250);
    delay(20);
    _delay(0.02);
    buzzer.tone(494, 250);
    delay(20);
    _delay(0.02);
    buzzer.tone(494, 250);
    delay(20);
    _delay(0.02);
    
}

void loop(){
    
    motor_9.run((9)==M1?-(255):(255));
    motor_10.run((10)==M1?-(0):(0));
    _delay(2);
    motor_9.run((9)==M1?-(0):(0));
    motor_10.run((10)==M1?-(255):(255));
    _delay(1);
    rgbled_7.setColor(0,255,0,0);
    rgbled_7.show();
    _delay(1);
    rgbled_7.setColor(0,0,255,0);
    rgbled_7.show();
    _delay(1);
    rgbled_7.setColor(0,0,0,255);
    rgbled_7.show();
    _delay(1);
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

