///change the potentiometers, and values depending on the sensor to adjust sensitivity
/*





*/
// These constants won't change. They're used to give names to the pins used:
const int sensor1 = A0;  // Analog input pin that the potentiometer is attached to
const int led1 = 2; //Digital output pin that the LED is attached to
const int sensor2 = A1;
const int led2 = 3;
const int sensor3 = A2;
const int led3 = 11;
const int sensor4 = A3;
const int led4 = 12;
const int sensor5 = A4;
const int led5 = 4;

//antenna

const int eyer = 13;
const int eyel = A5;




int s1val = 0;        // value read from the pot
int s1 = 0;   // 100
int s2val = 0;
int s2 = 0; // 100
int s3val = 0;
int s3 = 0;  // 100
int s4val = 0;
int s4 = 0;  //100
int s5val = 0;
int s5 = 0;  //100


//wait


//Motors Pins 
 int ENABLER = 8;
  int DIRAR = 9; //PWM
  int DIRBR = 10; //PWM

  int ENABLEL = 7;
  int DIRAL = 6; //PWM
  int DIRBL = 5; //PWM
 

int speed = 210;
 

//Extra 
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  //initialize motorpins

  pinMode(ENABLEL,OUTPUT);
  pinMode(DIRAL,OUTPUT);
  pinMode(DIRBL,OUTPUT);
  pinMode(ENABLER,OUTPUT);
  pinMode(DIRAR,OUTPUT);
  pinMode(DIRBR,OUTPUT);


pinMode(eyer, OUTPUT);
pinMode(eyel, OUTPUT);
}


/*
analogWrite(DIRAR, 255); ON 
analogWrite(DIRAL, 180); ON
analogWrite(DIRBR, 0); OFF
analogWrite(DIRBL, 0); OFF
*/

void loop() {

//for timing empty
  unsigned long current = millis();
unsigned long interval = 500;
unsigned long prevtime = 0;

  
  // read the analog in value: SENSOR 1 - OUTERMOST
   s1val = analogRead(sensor1);
  // map it to the range of the analog out:
  s1 = map(s1val, 0, 1023, 0, 500);
  // change the analog out value:
  if(s1 >= 100){
  analogWrite(led1, (s1));
  }
  else( analogWrite(led1,LOW));

//SENSOR 2

 s2val = analogRead(sensor2);
  // map it to the range of the analog out:
  s2 = map(s2val, 0, 1023, 0, 400);
  // change the analog out value:
  if(s2 >= 100){
  analogWrite(led2, (s2));
  }
  else( analogWrite(led2,LOW));
  
 //SENSOR 3

 s3val = analogRead(sensor3);
  // map it to the range of the analog out:
  s3 = map(s3val, 0, 1023, 0, 500);
  // change the analog out value:
   if(s3 >= 150){
  analogWrite(led3, (s3));
  }
  else( analogWrite(led3,LOW));

 //SENSOR 4

  s4val = analogRead(sensor4);
  // map it to the range of the analog out:
  s4 = map(s4val, 0, 1023, 0, 255);
  // change the analog out value:
if(s4 >= 100){
  analogWrite(led4, (s4));
  }
  else( analogWrite(led4,LOW));

  //SENSOR 5

   s5val = analogRead(sensor5);
  // map it to the range of the analog out:
  s5 = map(s5val, 0, 1023, 0, 255);
  // change the analog out value:
if(s5 >= 100){
  analogWrite(led5, (s5));
  }
  else( analogWrite(led5,LOW));

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(s4val);
  Serial.print("\t output = ");
  Serial.println(s4);
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);


//Motor code. Whole bunch of if statements.

//Go straight ahead
if( (s3 > 150) || (s3 > 100 && s4 > 100) || (s2 > 100 && s3 > 100) || (s1 > 100 && s2 > 100 && s3 > 100 && s4 > 100 && s5 > 100 )){ 
 digitalWrite(ENABLEL,HIGH);
 digitalWrite(ENABLER,HIGH);
 analogWrite(DIRAL, speed); 
 analogWrite(DIRAR, speed);
 analogWrite(DIRBL, 0); 
 analogWrite(DIRBR, 0);

  
digitalWrite(eyel, HIGH);
digitalWrite(eyer, HIGH);
 delay(100);



}
//Go right curve
else if((s3 > 60 && s4 > 60 && s5 > 60) || ( s4 > 60 && s5 > 60) || s4 >60 || s5 > 60 || (s3 > 60 && s4 > 60 && s5 > 60 && s2 > 60 )|| (s3 > 60 && s4 >60))  {
  digitalWrite(ENABLEL,HIGH);
  digitalWrite(ENABLER,LOW);
  analogWrite(DIRAL, speed); 
  analogWrite(DIRAR, speed); 
   analogWrite(DIRBL, 0); 
 analogWrite(DIRBR, 0); 
  
     
digitalWrite(eyel, LOW);
digitalWrite(eyer, HIGH);
  delay(200);


}

//Go left curve
else if((s3 > 60 && s2 > 100 && s1 > 60) || ( s2 > 250 && s1 > 60 ) || s1> 100|| (s2>100) || (s3 > 60 && s2 > 250 && s1 > 60 && s4 > 60) ){ //Curve to Left
 digitalWrite(ENABLEL, LOW);
 digitalWrite(ENABLER,HIGH);
 analogWrite(DIRAL, speed); 
 analogWrite(DIRAR, speed);  
  analogWrite(DIRBL, 0); 
 analogWrite(DIRBR, 0);
 

    
digitalWrite(eyel, HIGH);
digitalWrite(eyer, LOW);
  delay(200);

}

//if s5 and s1 sense but nothing else

//Empty backwards
else if(( s1 < 100 && s2 < 100 && s3 < 150 && s4 < 100 && s5 < 100)){
 digitalWrite(ENABLEL,HIGH);
 digitalWrite(ENABLER,HIGH);
  analogWrite(DIRAL, 0); 
 analogWrite(DIRAR, 0); 
analogWrite(DIRBL, speed); 
 analogWrite(DIRBR, speed);


 
delay(100);



}





}
