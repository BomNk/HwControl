#define DIR1_PIN 2
#define STEP1_PIN 3
#define DIR2_PIN 4
#define STEP2_PIN 5
#define DIR3_PIN 6
#define STEP3_PIN 7
#define DIR4_PIN 8
#define STEP4_PIN 9
//Create By BomNk
#define LED 13
int numstep=520; // 90 Degree
int step=numstep;
char ch;
int i;

void step1(char ch);
void step2(char ch);
void step3(char ch);
void step4(char ch);
void setup(){
    pinMode(DIR1_PIN, OUTPUT);
    pinMode(STEP1_PIN, OUTPUT);
    pinMode(DIR2_PIN, OUTPUT);
    pinMode(STEP2_PIN, OUTPUT);
    pinMode(DIR3_PIN, OUTPUT);
    pinMode(STEP3_PIN, OUTPUT);
    pinMode(DIR4_PIN, OUTPUT);
    pinMode(STEP4_PIN, OUTPUT);
    pinMode(LED,OUTPUT);
    
    Serial.begin(9600);
    
}

void loop(){
   
   //digitalWrite(DIR_PIN,HIGH);
   ch = Serial.read();
   //while(ch)
      step1(ch);
      step2(ch);
      step3(ch);
      step4(ch);
   
}
void step1(char ch){
    if(ch == 'a'){
       digitalWrite(LED,HIGH);
       digitalWrite(DIR1_PIN,LOW);
       for(int i=0;i<515;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP1_PIN,HIGH);
           delay(1);
           digitalWrite(STEP1_PIN,LOW);
           delay(1);
           
         // }
       }
    }
   if(ch == 'A'){
    digitalWrite(LED,LOW);
   digitalWrite(DIR1_PIN,HIGH);
   for(int i=0;i<515;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP1_PIN,HIGH);
           delay(1);
           digitalWrite(STEP1_PIN,LOW);
           delay(1);
           
          //}
       
      }
   }
}
void step2(char ch){
    if(ch == 'b'){
       digitalWrite(LED,HIGH);
       digitalWrite(DIR2_PIN,LOW);
       for(int i=0;i<515;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP2_PIN,HIGH);
           delay(1);
           digitalWrite(STEP2_PIN,LOW);
           delay(1);
           
         // }
       }
    }
   if(ch == 'B'){
   digitalWrite(DIR2_PIN,HIGH);
   for(int i=0;i<515;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP2_PIN,HIGH);
           delay(1);
           digitalWrite(STEP2_PIN,LOW);
           delay(1);
           
          //}
       
      }
   }
}
void step3(char ch){
    if(ch == 'c'){
       digitalWrite(LED,HIGH);
       digitalWrite(DIR3_PIN,LOW);
       for(int i=0;i<515;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP3_PIN,HIGH);
           delay(1);
           digitalWrite(STEP3_PIN,LOW);
           delay(1);
           
         // }
       }
    }
   if(ch == 'C'){
   digitalWrite(DIR3_PIN,HIGH);
   for(int i=0;i<515;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP3_PIN,HIGH);
           delay(1);
           digitalWrite(STEP3_PIN,LOW);
           delay(1);
           
          //}
       
      }
   }
}
void step4(char ch){
    if(ch == 'd'){
       digitalWrite(LED,HIGH);
       digitalWrite(DIR4_PIN,LOW);
       for(int i=0;i<515;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP4_PIN,HIGH);
           delay(1);
           digitalWrite(STEP4_PIN,LOW);
           delay(1);
           
         // }
       }
    }
   if(ch == 'D'){
    digitalWrite(LED,HIGH);
   digitalWrite(DIR4_PIN,HIGH);
   for(int i=0;i<515;i++){
          //if(digitalRead(SW)==1){
           digitalWrite(STEP4_PIN,HIGH);
           delay(1);
           digitalWrite(STEP4_PIN,LOW);
           delay(1);
           
          //}
       
      }
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
