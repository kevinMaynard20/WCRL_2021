import processing.serial.*;
#include <SoftwareSerial.h>
#include <AFMotor.h>
 
SoftwareSerial hc05(10,11);//RX, TX
int BluetoothData;




AF_DCMotor m_Right(2, MOTOR12_64KHZ);
AF_DCMotor m_Left(2, MOTOR12_64KHZ);
AF_DCMotor m_ArmMaster(2, MOTOR12_64KHZ);
AF_DCMotor m_ArmSlave(2, MOTOR12_64KHZ);

final char FORWARD='a',TLEFT='b',TRIGHT='c',STOP='A',SMASH='d',STOP_SMASH='B',STOP_ALL='C',DROP='z',FLIP='Z', STOP_ARM='y';



void setup() {
  hc05.begin(9600);
  delay(1000);
  m_Right.setSpeed(100);
  m_Left.setSpeed(100);
  m_ArmMaster.setSpeed(255);
  m_ArmSlave.setSpeed(255);
  
  
}
void controller(char input){
   if(input==FORWARD) 
      moveForward();
   else if(input==TLEFT)
      turnLeft();
   else if(input==TRIGHT)
      turnRight();
   else if(input==SMASH)
      smash();
   else if(input==STOP)
      stopMove();
   else if(input==DROP)
      drop();
   else if(input==FLIP)
      flip();
   else if(input==STOP_ARM)
      stopArm();
   else if(input==STOP_ALL){
      stopMove();
      stopSmash();
   }
   else{
      stopMove();
      stopSmash();    
   }
}

void loop() {
  digitalWrite(m_Right,****);
  digitalWrite(m_RightBrake,****);

  digitalWrite(m_Left, ****);
  digitalWrite(m_LeftBrake, ****);
  
  digitalWrite(m_ArmMaster, ****);
  digitalWrite(m_MasterBrake, ****); 
   
  digitalWrite(m_ArmSlave, ****);
  digitalWrite(m_SlaveBrake, ****);
  
  if(hc05.available()==true){
    controller(hc05.read());
  }
  else{
    stopMove();
    stopSmash();
    Serial.write("Error communicating with device) 
  }

}

void moveForward(){
m_Right.run(FORWARD);
m_Left.run(BACKWARDS);
}
void turnLeft(){
m_Right.run(BACKWARDS);
m_Left.run(BACKWARDS); 
}
void turnRight(){
m_Right.run(FORWARD);
m_Left.run(FORWARD); 
}
void drop(){
m_ArmMaster.run(FORWARD);
m_ArmSlave.run(BACKWARDS;
delay(300); 
}
void flip(){
  m_ArmMaster.run(BACKWARDS);
m_ArmSlave.run(FORWARD);
}
void stopArm(){
  m_ArmMaster.run(RELEASE);
  m_ArmSlave.run(RELEASE);
}
void stopMove(){
  m_Right.run(RELEASE);
  m_Left.run(RELEASE);
}
