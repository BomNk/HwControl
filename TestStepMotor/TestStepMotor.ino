#define DIR1_PIN 2
#define STEP1_PIN 3
#define DIR2_PIN 4
#define STEP2_PIN 5
#define DIR3_PIN 6
#define STEP3_PIN 7
#define DIR4_PIN 8
#define STEP4_PIN 9

#define DIR5_PIN 10
#define STEP5_PIN 11
#define DIR6_PIN 13
#define STEP6_PIN 12




//Create By BomNk
int sleep = 3;
//int numstep=520; // 90 Degree
int numstep = 50;
int numstep_slide = 150;

char ch;
int i;


void front(char ch);
void left(char ch);
void back(char ch);
void right(char ch);

void left_right(char ch);
void front_back(char ch);



void setup(){
    pinMode(DIR1_PIN, OUTPUT);
    pinMode(STEP1_PIN, OUTPUT);
    pinMode(DIR2_PIN, OUTPUT);
    pinMode(STEP2_PIN, OUTPUT);
    pinMode(DIR3_PIN, OUTPUT);
    pinMode(STEP3_PIN, OUTPUT);
    pinMode(DIR4_PIN, OUTPUT);
    pinMode(STEP4_PIN, OUTPUT);

    pinMode(DIR5_PIN,OUTPUT);
    pinMode(STEP5_PIN,OUTPUT);
    pinMode(DIR6_PIN,OUTPUT);
    pinMode(STEP6_PIN,OUTPUT);
    
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

      left_right(ch);
      front_back(ch);
     
}
// ส่วนของการหมุนลูกรูบิค
void front(char ch){
    if(ch == 'f'){
       //digitalWrite(LED,HIGH);
       digitalWrite(DIR1_PIN,LOW);
       for(int i=0;i<numstep;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP1_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP1_PIN,LOW);
           delay(sleep);
           
         // }
       }
    }
   if(ch == 'F'){
       //digitalWrite(LED,LOW);
       digitalWrite(DIR1_PIN,HIGH);
       for(int i=0;i<numstep;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP1_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP1_PIN,LOW);
           delay(sleep);
           
         // }
       }
    }
}
void left(char ch){
    if(ch == 'l'){
       //digitalWrite(LED,HIGH);
       digitalWrite(DIR2_PIN,LOW);
       for(int i=0;i<numstep;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP2_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP2_PIN,LOW);
           delay(sleep);
           
         // }
       }
    }
   if(ch == 'L'){
      digitalWrite(DIR2_PIN,HIGH);
      for(int i=0;i<numstep;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP2_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP2_PIN,LOW);
           delay(sleep);
           
          //}
       
      }
   }
}
void back(char ch){
    if(ch == 'b'){
       //digitalWrite(LED,HIGH);
       digitalWrite(DIR3_PIN,LOW);
       for(int i=0;i<numstep;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP3_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP3_PIN,LOW);
           delay(sleep);
           
         // }
       }
    }
   if(ch == 'B'){
   digitalWrite(DIR3_PIN,HIGH);
   for(int i=0;i<numstep;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP3_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP3_PIN,LOW);
           delay(sleep);
           
          //}
       
      }
   }
}
void right(char ch){
    if(ch == 'r'){
      
       digitalWrite(DIR4_PIN,LOW);
       for(int i=0;i<numstep;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP4_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP4_PIN,LOW);
           delay(sleep);
           
         // }
       }
    }
   if(ch == 'R'){
    
    digitalWrite(DIR4_PIN,HIGH);
    for(int i=0;i<numstep;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP4_PIN,HIGH);
           delay(sleep);
           digitalWrite(STEP4_PIN,LOW);
           delay(sleep);
           
          //}
       
      }
   }
}

void left_right(char ch){
  if(ch == 'a'){ // หมุนทวนทางซ้าย
         digitalWrite(DIR2_PIN,LOW);
         digitalWrite(DIR4_PIN,HIGH);
         for(int i=0;i<numstep;i++){
            //if(digitalRead(SW)==1){
             digitalWrite(STEP2_PIN,HIGH);
             digitalWrite(STEP4_PIN,HIGH);
             delay(sleep);
             digitalWrite(STEP2_PIN,LOW);
             digitalWrite(STEP4_PIN,LOW);
             delay(sleep);
             
           // }
         }
      }
     if(ch == 'A'){ // หมุนตามตัวทางซ้าย
         digitalWrite(DIR2_PIN,HIGH);
         digitalWrite(DIR4_PIN,LOW);
         for(int i=0;i<numstep;i++){
            //if(digitalRead(SW)==1){
             digitalWrite(STEP2_PIN,HIGH);
             digitalWrite(STEP4_PIN,HIGH);
             delay(sleep);
             digitalWrite(STEP2_PIN,LOW);
             digitalWrite(STEP4_PIN,LOW);
             delay(sleep);
             
           // }
         }
}

void front_back(char ch){
    if(ch == 'd'){ // หมุนทวนทางหน้า
         digitalWrite(DIR1_PIN,LOW);
         digitalWrite(DIR3_PIN,HIGH);
         for(int i=0;i<numstep;i++){
            //if(digitalRead(SW)==1){
             digitalWrite(STEP1_PIN,HIGH);
             digitalWrite(STEP3_PIN,HIGH);
             delay(sleep);
             digitalWrite(STEP1_PIN,LOW);
             digitalWrite(STEP3_PIN,LOW);
             delay(sleep);
             
           // }
         }
      }
     if(ch == 'D'){ // หมุนตามตัวทางหน้า
         digitalWrite(DIR1_PIN,HIGH);
         digitalWrite(DIR3_PIN,LOW);
         for(int i=0;i<numstep;i++){
            //if(digitalRead(SW)==1){
             digitalWrite(STEP1_PIN,HIGH);
             digitalWrite(STEP3_PIN,HIGH);
             delay(sleep);
             digitalWrite(STEP1_PIN,LOW);
             digitalWrite(STEP3_PIN,LOW);
             delay(sleep);
             
           // }
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
