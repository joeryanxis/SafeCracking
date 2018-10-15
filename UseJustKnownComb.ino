
//7= 1
//8=2

void setup() {
pinMode(8,OUTPUT);//key 1
pinMode(9,OUTPUT);//key 2
//pinMode(3,OUTPUT);//key 3
pinMode(4,OUTPUT);//key 4
pinMode(5,OUTPUT);//key 5
pinMode(6,OUTPUT);//key 6

//digitalWrite(8,LOW);
//digitalWrite(9,LOW);
//digitalWrite(3,LOW);
//digitalWrite(4,LOW);
//digitalWrite(5,LOW);
//digitalWrite(6,LOW);

digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
//digitalWrite(3,HIGH);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
 openLock();
}

void loop() {
 //openLock();

}

void openLock(){
  //code is 2550 which is (4,6) (4,5) (4,5) (1,4) and (1,2)

  digitalWrite(4,LOW);
  digitalWrite(6, LOW);//2
  delay(100);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);//20ff
  
  digitalWrite(4,LOW);
  digitalWrite(5, LOW);//5
  delay(100);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);//5off
  
  digitalWrite(4,LOW);
  digitalWrite(5, LOW);//5
  delay(100);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);//5off
  
  digitalWrite(8,LOW);
  digitalWrite(4, LOW);//0
  delay(100);
  digitalWrite(8, HIGH);
  digitalWrite(4, HIGH);//0off
  
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);//Enter 
  delay(100);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH); //Enteroff
}
 // Turn them low?
  

