#include <EEPROM.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);//Gives the LCD screen an i2c address

#define num1 2
#define num2 3
#define num3 4
#define num4 5
#define num5 6
#define num6 7
#define num7 8
#define num8 9
#define num9 10
#define num0 12//used to be 11
#define enter 11//used to be 12
//set pins that will control the relays that short the two wires together

byte address = 0;
int digit1 ,digit2  ,digit3 ,digit4;//places to store input digits
int number;//temporary place to hold input
int counter = 0; // counts how many digits have been submitted
int powerCounter = 0;
String keyInput; // string to hold input

//photosensor reading variables
int sensorVal=0;//hold sensor Value
int photoCellValue = A0;
int sensorGoal, darkState, light1, light2, light3, light4; //what the sensor value should be

//servo code 
Servo myServo;
int pos = 180;//set initial position to zero

//display code
String number1,number2,number3,number4, success, failure;

void setup() {
  Serial.begin(9600);
  pinMode(num1,OUTPUT);
  pinMode(num2,OUTPUT);
  pinMode(num3,OUTPUT);
  pinMode(num4,OUTPUT);
  pinMode(num5,OUTPUT);
  pinMode(num6,OUTPUT);
  pinMode(num7,OUTPUT);
  pinMode(num8,OUTPUT);
  pinMode(num9,OUTPUT);
  pinMode(num0,OUTPUT);
  pinMode(enter, OUTPUT);
  pinMode(A3,OUTPUT);
  //starts all pins at LOW
  digitalWrite(num1,LOW);
  digitalWrite(num2,LOW);
  digitalWrite(num3,LOW);
  digitalWrite(num4,LOW);
  digitalWrite(num5,LOW);
  digitalWrite(num6,LOW);
  digitalWrite(num7,LOW);
  digitalWrite(num8,LOW);
  digitalWrite(num9,LOW);
  digitalWrite(num0,LOW);
  digitalWrite(enter,LOW);
  digitalWrite(A3,LOW);

  pinMode(photoCellValue, INPUT);//sets pin to read photosensor value
  light1 = analogRead(A0);
  delay(10);
  light2 = analogRead(A0);
  delay(10);
  light3 = analogRead(A0);
  delay(10);
  light4 = analogRead(A0);
  darkState = ((light1 + light2 +light3 +light4)/4);
  sensorGoal = darkState + 10;
  myServo.attach(A2);//Set servo control pin to #1, because all our other pins are taken
  myServo.write(pos);
  Serial.println("Hello, Type a number between 0 and 9 in the box above to send it to the keypad. Or type a : to start the algorithm");
  powerCycle();

  //display code
  lcd.init();//Initializes the LCD
  lcd.backlight(); //turns on the backlight
  success = "Success!";
  failure = "Failure :(";

  
}

void loop() {
  if(counter == 4){//if 4 numbers have been pressed
      pressEnter();//calls function to press enter
    }
  if(Serial.available() > 0){//if you type a thing
    keyInput = Serial.read();//reads input, puts it in keyinput
    number = keyInput.toInt()-'0';//converts it to the ASCII value, 0 being 48, 9 being 57

    if(number < 0 || number > 10 ){
      //Makes sure it's an integer input
      Serial.println("Please type a number between 0 and 9");
    }
    else if (number == 1 && counter != 4){
      //Makes sure the counter isn't already at the max
      EEPROM.put(address, number);//stores the digit in EEPROM
      Serial.println(number);//Prints the number
      buttonPress(num1);//calls the function to simulate pressing the 1 button on the keypad
      address = address + sizeof(int);//increments address, so the next value is written to an empty space in EEPROM
      counter++; //increments counter, gets closer to pressing enter
      
    }
    else if (number == 2 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num2);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 3 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num3);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 4 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num4);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 5 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num5);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 6 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num6);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 7 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num7);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 8 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num8);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 9 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num9);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 0 && counter != 4){
      
      EEPROM.put(address, number);
      Serial.println(number);
      buttonPress(num0);
      address = address + sizeof(int);
      counter++; 
      
    }
    else if (number == 10){
      
     
      Serial.println("Algorithm");
      algorithm();
       
      
    }

 }
}


void buttonPress(int a){

  digitalWrite(a, HIGH);
  delay(300);
  digitalWrite(a, LOW);
  delay(300);
  Serial.print("Pin #");
  Serial.println(a);
}
void buttonPressAlgorithm(int a){
  int b;
  if(a == 0){
    b = num0;
  }
  if(a == 1){
    b = num1;
  }
  if(a == 2){
    b = num2;
  }
  if(a == 3){
    b = num3;
  }
  if(a == 4){
    b = num4;
  }
  if(a == 5){
    b = num5;
  }
  if(a == 6){
    b = num6;
  }
  if(a == 7){
    b = num7;
  }
  if(a == 8){
    b = num8;
  }
  if(a == 9){
    b = num9;
  }
  digitalWrite(b, HIGH);
  delay(500);
  digitalWrite(b, LOW);
  delay(500);
  Serial.print("Pin #");
  Serial.println(b);
}



void pressEnter(){
 
  digitalWrite(enter,HIGH);
  delay(100);
  digitalWrite(enter,LOW);
  //delay(100);
  counter = 0;//resets counter to 0
  
  
  check();
  delay(500);
}

void check(){
  sensorVal = analogRead(photoCellValue);
  Serial.println("Checking...");
  Serial.println(sensorVal);
  Serial.println(sensorGoal);
 // if(sensorVal>sensorGoal){
    delay(2000);//delay 2 seconds
    //sensorVal = analogRead(photoCellValue);
  if(sensorVal>sensorGoal){
      Serial.println("success");
       turnHandle();
        lcd.setCursor(3,1);
        lcd.print(success);
        turnHandle();
        while(1==1){
          
        }
    }else{
     Serial.println("FAILED");
     lcd.setCursor(3,1);
      lcd.print(failure);
      delay(1000);
      lcd.clear();
     if(powerCounter == 3){
      powerCounter = 0;
     }
     if(powerCounter == 2){
      delay(1000);
      powerCycle();
     }
     powerCounter++;
     
    }
  //}
}

void turnHandle(){
  myServo.write(75);
}

void algorithm(){
   for(int i = 0; i<9; i++){
    for(int j = 0; j<9;j++){
      for(int k = 0;k<9;k++){
        for(int l = 0;l<9;l++){
          number1 = String(i);
          number2 = String(j);
          number3 = String(k);
          number4 = String(l);
          lcd.setCursor(4,0);
          lcd.print(number1);
          lcd.setCursor(6,0);
          lcd.print(number2);
          lcd.setCursor(8,0);
          lcd.print(number3);
          lcd.setCursor(10,0);
          lcd.print(number4);
          delay(1000);
          
          buttonPressAlgorithm(i);
          Serial.println(i);
          buttonPressAlgorithm(j);
          Serial.println(j);
          buttonPressAlgorithm(k);
          Serial.println(k);
          buttonPressAlgorithm(l);
          Serial.println(l);
          pressEnter();
          
          Serial.print(i);
          Serial.print(",");
          Serial.print(j);
          Serial.print(",");
          Serial.print(k);
          Serial.print(",");
          Serial.println(l);
        }
      }
    }
  }
}


void powerCycle(){
  digitalWrite(A3,HIGH);
  delay(1000);
  digitalWrite(A3,LOW);
  delay(1000);
  Serial.println("power cycled");
  
  
}


