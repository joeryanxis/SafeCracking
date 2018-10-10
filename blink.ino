int sensorVal=0;//hold sensor Value
int photoCellValue = A0;
void setup() {
Serial.begin(9600);
pinMode(photoCellValue, INPUT);
pinMode(11, OUTPUT);
pinMode(3,INPUT);//failed button
pinMode(2,INPUT);//success button
}

void loop() {
sensorVal = analogRead(photoCellValue);
//if(sensorVal<200){
//  Serial.println("_");
//}
if(sensorVal>375){
  delay(3000);//delay 3 seconds
  sensorVal = analogRead(photoCellValue);
  if(sensorVal>375){
  Serial.println("SUCESSFUL COMBINATION");
  exit;
  }else{
   Serial.println("FAILED");
  }
}
//Serial.print("sensor: ");
//Serial.println(sensorVal);
//HERE IS THE PROBLEM:
//We have delays, which stops everything else from happening. including the sensor reading the values
  
if(digitalRead(3) == LOW){
//  failedCombination();
digitalWrite(11,HIGH);
}else{
  digitalWrite(11,LOW);
}
if(digitalRead(2) == LOW){
//  successfulCombination();
digitalWrite(11,HIGH);
}

}

void failedCombination(){
digitalWrite(11, HIGH);
delay(150);
digitalWrite(11, LOW);
delay(75);
digitalWrite(11, HIGH);
delay(150);
digitalWrite(11, LOW);
delay(75);
digitalWrite(11, HIGH);
delay(150);
digitalWrite(11, LOW);  
}

void successfulCombination(){
  digitalWrite(11, HIGH);
delay(150);
digitalWrite(11, LOW);
delay(75);
digitalWrite(11, HIGH);
delay(150);
digitalWrite(11, LOW);
delay(75);
digitalWrite(11, HIGH);
delay(150);
digitalWrite(11, LOW);
delay(75);
digitalWrite(11, HIGH);
delay(4000);
digitalWrite(11, LOW);

}

