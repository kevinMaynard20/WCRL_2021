
#include <SoftwareSerial.h>
#include <AFMotor.h>
 
SoftwareSerial hc05(A3,A5);//RX, TX
int BluetoothData;




AF_DCMotor m_Right(2, MOTOR12_64KHZ);
AF_DCMotor m_Left(1, MOTOR12_64KHZ);
AF_DCMotor m_ArmMaster(3, MOTOR12_64KHZ);
AF_DCMotor m_ArmSlave(4, MOTOR12_64KHZ);

 char FORWARDS='a',TLEFT='b',TRIGHT='c',STOP='A',STOP_ALL='C',DROP='z',FLIP='Z', STOP_ARM='y';



void setup() {
  hc05.begin(9600);
  delay(1000);
  m_Right.setSpeed(100);
  m_Left.setSpeed(100);
  m_ArmMaster.setSpeed(255);
  m_ArmSlave.setSpeed(255);
  
  
}
void controller(char input){
   if(input==FORWARDS) 
      moveForward();
   else if(input==TLEFT)
      turnLeft();
   else if(input==TRIGHT)
      turnRight();
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
      stopArm();
   }
   //else{
      //stopMove();
     // stopArm();    
   //}
}

void loop() {
  //digitalWrite(m_Right,****);
  //digitalWrite(m_RightBrake,****);

  //digitalWrite(m_Left, ****);
  //digitalWrite(m_LeftBrake, ****);
  
  //digitalWrite(m_ArmMaster, ****);
  //digitalWrite(m_MasterBrake, ****); 
   
  //digitalWrite(m_ArmSlave, ****);
  //digitalWrite(m_SlaveBrake, ****);
  
  
  //if(hc05.available()==true){
    controller(hc05.read());
    
  //}
  //else{
   // stopMove();
   // stopArm();
   // Serial.write("Error communicating with device"); 
 // }

}
void moveBackwards(){
  m_Right.setSpeed(100);
  m_Left.setSpeed(100);
m_Right.run(FORWARD);
m_Left.run(BACKWARD);
}
void moveForward(){
  m_Right.setSpeed(100);
  m_Left.setSpeed(100);
m_Right.run(FORWARD);
m_Left.run(BACKWARD);
}
void turnLeft(){
  m_Right.setSpeed(50);
  m_Left.setSpeed(50);
m_Right.run(FORWARD);
m_Left.run(FORWARD); 
}
void turnRight(){
  m_Right.setSpeed(50);
  m_Left.setSpeed(50);
m_Right.run(BACKWARD);
m_Left.run(BACKWARD); 
}
void drop(){
m_ArmMaster.run(FORWARD);
m_ArmSlave.run(BACKWARD);
 
}
void flip(){
  m_ArmMaster.run(BACKWARD);
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
