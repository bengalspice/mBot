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
MeLEDMatrix ledMtx_1(1);
unsigned char drawBuffer[16];
unsigned char *drawTemp;
MeIR ir;

void setup(){
    ledMtx_1.setColorIndex(1);
    ledMtx_1.setBrightness(6);
    for(int __i__=0;__i__<5;++__i__)
    {
    drawTemp = new unsigned char[16]{124,68,92,16,0,124,68,124,0,124,80,124,0,124,4,4};
        memcpy(drawBuffer,drawTemp,16);
        free(drawTemp);
        ledMtx_1.drawBitmap(0,0,16,drawBuffer);
        motor_9.run((9)==M1?-(255):(255));
        motor_10.run((10)==M1?-(0):(0));
        _delay(2);
        motor_9.run((9)==M1?-(0):(0));
        motor_10.run((10)==M1?-(255):(255));
    }
    ir.begin();
    if(ir.keyPressed(64)){
        move(1,50);
    }
    if(ir.keyPressed(25)){
        move(2,50);
    }
    if(ir.keyPressed(9)){
        move(4,50);
    }
    if(ir.keyPressed(7)){
        move(3,50);
    }
    if(ir.keyPressed(22)){
        move(1,0);
    }
}

void loop(){
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    ir.loop();
}
