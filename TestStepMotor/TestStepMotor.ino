#include<Servo.h>

#define DIR1_PIN 13
#define STEP1_PIN 2
#define DIR2_PIN 4
#define STEP2_PIN 5
#define DIR3_PIN 6
#define STEP3_PIN 7
#define DIR4_PIN 9
#define STEP4_PIN 8

#define Ms_F A0
#define Ms_L A1
#define Ms_B A2
#define Ms_R A3
/*
#define DIR5_PIN 10
#define STEP5_PIN 11
#define DIR6_PIN 13
#define STEP6_PIN 12
*/



//Create By BomNk
int sleep = 1;
int sleep1 = 1;

//int numstep=520; // 90 Degree
int numstep = 50;
int numstep_slide = 150;

char ch;
int i;

Servo servo1,servo2;


void front(char ch);
void left(char ch);
void back(char ch);
void right(char ch);

void left_right_totate(char ch);
//delay(500);
void front_back_rotate(char ch);
//delay(500);
void left_right_slide(char ch);
//delay(500);
void front_back_slide(char ch);



void setup(){
    pinMode(DIR1_PIN, OUTPUT);
    pinMode(STEP1_PIN, OUTPUT);
    pinMode(DIR2_PIN, OUTPUT);
    pinMode(STEP2_PIN, OUTPUT);
    pinMode(DIR3_PIN, OUTPUT);
    pinMode(STEP3_PIN, OUTPUT);
    pinMode(DIR4_PIN, OUTPUT);
    pinMode(STEP4_PIN, OUTPUT);

/*    pinMode(DIR5_PIN,OUTPUT);
    pinMode(STEP5_PIN,OUTPUT);
    pinMode(DIR6_PIN,OUTPUT);
    pinMode(STEP6_PIN,OUTPUT);*/

    pinMode(Ms_F,OUTPUT);
    pinMode(Ms_L,OUTPUT);
    pinMode(Ms_B,OUTPUT);
    pinMode(Ms_R,OUTPUT);

    servo1.attach(10);
    servo2.attach(11);
    
    servo1.write(90);
    servo2.write(0);

   digitalWrite(Ms_F,LOW);
   digitalWrite(Ms_L,LOW);
   digitalWrite(Ms_B,LOW);
   digitalWrite(Ms_R,LOW);
   
    Serial.begin(9600);
    
}

void loop(){
   
   //digitalWrite(DIR_PIN,HIGH);
   ch = Serial.read();
   //while(ch)
      front(ch);
      left(ch);
      back(ch);
      right(ch);

      left_right_rotate(ch);
      front_back_rotate(ch);
      left_right_slide(ch);
      front_back_slide(ch);
     
}
// ส่วนของการหมุนลูกรูบิค
void front(char ch){
    if(ch == 'f'){
       digitalWrite(Ms_F,HIGH);
       //digitalWrite(LED,HIGH);
       digitalWrite(DIR1_PIN,LOW);
       for(int i=0;i<numstep*4;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP1_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP1_PIN,LOW);
           delay(sleep);
           
         // }
       }
       digitalWrite(Ms_F,LOW);
    }
   if(ch == 'F'){
       digitalWrite(Ms_F,HIGH);
       //digitalWrite(LED,LOW);
       digitalWrite(DIR1_PIN,HIGH);
       for(int i=0;i<numstep*4;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP1_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP1_PIN,LOW);
           delay(sleep);
           
         // }
       }
       digitalWrite(Ms_F,LOW);
    }
}
void left(char ch){
    if(ch == 'l'){
      digitalWrite(Ms_L,HIGH);
       //digitalWrite(LED,HIGH);
       digitalWrite(DIR2_PIN,LOW);
       for(int i=0;i<numstep*4;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP2_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP2_PIN,LOW);
           delay(sleep);
           
         // }
       }
       digitalWrite(Ms_L,LOW);
    }
   if(ch == 'L'){
      digitalWrite(Ms_L,HIGH);
      digitalWrite(DIR2_PIN,HIGH);
      for(int i=0;i<numstep*4;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP2_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP2_PIN,LOW);
           delay(sleep);
           
          //}
       
      }
      digitalWrite(Ms_L,LOW);
   }
}
void back(char ch){
    if(ch == 'b'){
      digitalWrite(Ms_B,HIGH);
       //digitalWrite(LED,HIGH);
       digitalWrite(DIR3_PIN,LOW);
       for(int i=0;i<numstep*4;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP3_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP3_PIN,LOW);
           delay(sleep);
           
         // }
       }
       digitalWrite(Ms_B,LOW);
    }
   if(ch == 'B'){
    digitalWrite(Ms_B,HIGH);
   digitalWrite(DIR3_PIN,HIGH);
   for(int i=0;i<numstep*4;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP3_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP3_PIN,LOW);
           delay(sleep);
           
          //}
       
      }
      digitalWrite(Ms_B,LOW);
   }
}
void right(char ch){
    if(ch == 'r'){
        digitalWrite(Ms_R,HIGH);
       digitalWrite(DIR4_PIN,LOW);
       for(int i=0;i<numstep*4;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP4_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP4_PIN,LOW);
           delay(sleep);
           
         // }
       }
       digitalWrite(Ms_R,LOW);
    }
   if(ch == 'R'){
    digitalWrite(Ms_R,HIGH);
    digitalWrite(DIR4_PIN,HIGH);
    for(int i=0;i<numstep*4;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP4_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP4_PIN,LOW);
           delay(sleep);
           
          //}
       
      }
      digitalWrite(Ms_R,LOW);
   }
}

void left_right_rotate(char ch){
  if(ch == 'a'){ // หมุนทวนทางซ้าย
         digitalWrite(Ms_L,HIGH);
         digitalWrite(Ms_R,HIGH);
         
         digitalWrite(DIR2_PIN,LOW);
         digitalWrite(DIR4_PIN,HIGH);
         for(int i=0;i<numstep*4;i++){
            //if(digitalRead(SW)==1){
             digitalWrite(STEP2_PIN,HIGH);
             digitalWrite(STEP4_PIN,HIGH);
             delay(sleep1);
             digitalWrite(STEP2_PIN,LOW);
             digitalWrite(STEP4_PIN,LOW);
             delay(sleep1);
             
           // }
         }

        digitalWrite(Ms_L,LOW);
        digitalWrite(Ms_R,LOW);
      }
     if(ch == 'A'){ // หมุนตามตัวทางซ้าย
      digitalWrite(Ms_L,HIGH);
         digitalWrite(Ms_R,HIGH);
         
         digitalWrite(DIR2_PIN,HIGH);
         digitalWrite(DIR4_PIN,LOW);
         for(int i=0;i<numstep*4;i++){
            //if(digitalRead(SW)==1){
             digitalWrite(STEP2_PIN,HIGH);
             digitalWrite(STEP4_PIN,HIGH);
             delay(sleep1);
             digitalWrite(STEP2_PIN,LOW);
             digitalWrite(STEP4_PIN,LOW);
             delay(sleep1);
             
           // }
         }

         digitalWrite(Ms_L,LOW);
         digitalWrite(Ms_R,LOW);
     }
}

void front_back_rotate(char ch){
    if(ch == 'd'){ // หมุนทวนทางหน้า
         digitalWrite(Ms_F,HIGH);
         digitalWrite(Ms_B,HIGH);
          
         digitalWrite(DIR1_PIN,LOW);
         digitalWrite(DIR3_PIN,HIGH);
         for(int i=0;i<numstep*4;i++){
            //if(digitalRead(SW)==1){
             digitalWrite(STEP1_PIN,HIGH);
             digitalWrite(STEP3_PIN,HIGH);
             delay(sleep1);
             digitalWrite(STEP1_PIN,LOW);
             digitalWrite(STEP3_PIN,LOW);
             delay(sleep1);
             
           // }
         }
         digitalWrite(Ms_F,LOW);
         digitalWrite(Ms_B,LOW);
      }
     if(ch == 'D'){ // หมุนตามตัวทางหน้า
         digitalWrite(Ms_F,HIGH);
         digitalWrite(Ms_B,HIGH);
      
         digitalWrite(DIR1_PIN,HIGH);
         digitalWrite(DIR3_PIN,LOW);
         for(int i=0;i<numstep*4;i++){
            //if(digitalRead(SW)==1){
             digitalWrite(STEP1_PIN,HIGH);
             digitalWrite(STEP3_PIN,HIGH);
             delay(sleep1);
             digitalWrite(STEP1_PIN,LOW);
             digitalWrite(STEP3_PIN,LOW);
             delay(sleep1);
             
           // }
         }
         digitalWrite(Ms_F,LOW);
         digitalWrite(Ms_B,LOW);
     }
}

void left_right_slide(char ch){
   if(ch == 'J'){
      
       servo1.write(90);
       delay(1000);
    }
   if(ch == 'j'){
    
       servo1.write(0);
       delay(1000);
   }



   
}
void front_back_slide(char ch){
   if(ch == 'k'){
      
       servo2.write(0);
       delay(1000);
    }
   if(ch == 'K'){
       servo2.write(85);
       delay(1000);
       
   }
}

/*
void rotate(int steps, float speed){
    //rotate a specific number of microsteps (8 microsteps per step) – (negitive for reverse movement)
    //speed is any number from .01 -> 1 with 1 being fastest – Slower is stronger
    int dir = (steps > 0)? HIGH:LOW;
    steps = abs(steps);
    
    digitalWrite(DIR_PIN,dir);
    
    float usDelay = (1/speed) * 70;

    for(int i=0; i < steps; i++){ 
      digitalWrite(STEP_PIN, HIGH); 
      delayMicroseconds(usDelay); 
      digitalWrite(STEP_PIN, LOW); 
      delayMicroseconds(usDelay); 
      } 
 } 
void rotateDeg(float deg, float speed){ //rotate a specific number of degrees (negitive for reverse movement) //speed is any number from .01 -> 1 with 1 being fastest – Slower is stronger
    int dir = (deg > 0)? HIGH:LOW;
    digitalWrite(DIR_PIN,dir);

    int steps = abs(deg)*(1/0.225);
    float usDelay = (1/speed) * 70;

    for(int i=0; i < steps; i++){ 
      digitalWrite(STEP_PIN, HIGH); 
      delayMicroseconds(usDelay); 
      digitalWrite(STEP_PIN, LOW); 
      delayMicroseconds(usDelay); 
      } 
} 
*/
