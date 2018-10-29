//test to see that the aurdino can talk to the safe
//the board is set up with 4 relays, one for each of the numbers in the combination (2,5,5,0, ENTER)


void setup() {
Serial.begin(9600);
pinMode(7,OUTPUT);//Enter
pinMode(8,OUTPUT);//0
pinMode(9,OUTPUT);//5
pinMode(10,OUTPUT);//2

//all pins need to start low

digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
}

//send power to one relay at a time, which shorts two wires, which talk to the safe.
//2=(4,6), 5=(4,5), 0=(1,4), Enter=(1,2) 

//**NOTE, because it is going through a loop, it may start on any number. It may take a few tries before the safe hits
//the numbers 2550E, but eventually it will loop correctly. 
//TRIED AND SUCCESSFUL

void loop() {
digitalWrite(10,HIGH);//2 on
delay(500);
digitalWrite(10,LOW);//2 off
delay(500);
digitalWrite(9,HIGH);//5 on
delay(500);
digitalWrite(9,LOW);//5 off
delay(500);
digitalWrite(9,HIGH);//5 on
delay(500);
digitalWrite(9,LOW);//5 off
delay(500);
digitalWrite(8,HIGH);//0 on
delay(500);
digitalWrite(8,LOW);//0 off
delay(500);
digitalWrite(7,HIGH);//enter on
delay(500);
digitalWrite(7,LOW);//enter off
delay(500);
}
