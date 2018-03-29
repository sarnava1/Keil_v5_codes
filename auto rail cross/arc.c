#include<stdio.h>
#include<reg52.h>
#define open 0x0a;//to open the gate by rotating it clockwise
#define close 0x05;//to close the gate by rotating it anti clockwise
#define stop 0x00;//to stop the movement of the gate
//_sbit c=P0^5;//this is where the red led is connected
sbit d=P0^6;//this is where the red led is connected
sbit e=P0^7;//this is where the green led is connected
//_sbit f=P0^4;//this is where the red led is connected
sbit rs1=P0^4;
sbit rs2=P0^3;
sbit check=P0^5;
unsigned int a,b,i,j;

void delay(unsigned int t){
for(i=0;i<t;i++){
for(j=0;j<1275;j++){
}
}
}
//============================FEW THINGS ABOUT THE SETUP WHEN THE VIDEO WAS SHOT=====================================
//1.the second motor was not working because of loose connection
//2.all the sensors except one road sensor was not working
//3.except the case of when vehicles will be stranded even when the train is approaching was not being handled
//4.i tried making many changes for that to work and that why all the comments and changes
//5.i introduced the red led on pin 6 and also introduced a checking led to see if my road sensor was working well
//6.since i had used leds on only one side of the road i commented out the connections of the other leds
//7.with more time and patience this project can be developed into something really big and working and with correct code
//======================================================================================================================



//here my road sensors are connected to pin 2 and 3 of the of port 0 
//my road sensor 2 does not work that is the sensor connected to the pin 3 of port 0 does not work and so i have in the conditions
//of train approaching and vehicles stranded have only taken into account rs1==1
//if both would have worked we would have written rs1==1||rs2==1
//pin0 and pin 1 of port 0 has the rail track sensors connected to it
//i have connected the green led to pin 7 and the red led to pin 5 of port 0 of the dev board
//the leds of the other side are not connected due to the lack of jumper wires(sorry i had enuf jumpers but had no time and patience)

void main(){
while(1){
a=P0&0x03;
if(a==0x00){
P2=stop;//no movement of gates
  //d=1;//the green led should be on
	e=1;//the green led should be on
	//d=1;//the green led should be on
	//c=0;//turn off the red led
	d=0;//turn off the red led
	if(rs1==1)
		check=1;
	else
		check=0;
}
////
//train arriving from right
if(a==0x01){
//d=;//turn off the green led
e=0;//turn off the green led
d=1;//turn on the red led
//c=1;//turn on the red led
P2=close;//close the gates
delay(300);
P2=stop;//keep the gates closed
delay(600);
P2=open;
delay(300);
		if(rs1==1)
		check=1;
	else
		check=0;
}


//train is approaching from the left
if(a==0x02){
//d=0;//turn off the green led	
e=0;//turn off the green led
d=1;//turn on the red led
//c=1;//turn on the red led	
P2=close;//close the gates
delay(300);
P2=stop;//keep the gates closed
delay(600);
P2=open;
delay(300);
		if(rs1==1)
		check=1;
	else
		check=0;
}


//both the sensors are sensing the approach of train
if(a==0x03){
//d=0;//turn off the green led	
e=0;//turn off the green led
d=1;//turn on the red led
//c=1;//turn on the red led	
P2=close;//close the gates
delay(300);
P2=stop;//keep the gates closed
delay(600);
P2=open;
delay(300);	
		if(rs1==1)
		check=1;
	else
		check=0;
}


//train is arriving from right and the road sensors 1 or 2 sense vehicles on the road
if(rs1==1&&a==0x02){
		if(rs1==1)
		check=1;
	else
		check=0;
e=1;//turn on the green led

//d=1;//turn on the green led	
d=0;//turn off the red led
//c=0;//turn off the red led
P2=stop;	
P2=open;//open the gates
delay(300);
P2=stop;
delay(300);
e=0;//turn off the green led
///d=0;//turn off the green led	
d=1;//turn on the red led
//c=1;//turn on the red led	
P2=close;//close the gates
delay(900);
P2=stop;
delay(200);	
d=0;//turn off the red led
//c=0;//turn off the red led	
e=1;//turn on the green led
//d=0;//turn on the green led	
P2=open;
delay(300);
P2=stop;
delay(600);
}



//train is coming from the left and 1 or 2 vehicles are stranded on the road

if(rs1==1&&a==0x01){
	if(rs1==1)
		check=1;
	else
		check=0;
	e=1;//turn on the green led

//d=1;//turn on the green led	
d=0;//turn off the red led
//c=0;//turn off the red led
P2=stop;	
P2=open;//open the gates
delay(300);
P2=stop;
delay(300);
e=0;//turn off the green led
///d=0;//turn off the green led	
d=1;//turn on the red led
//c=1;//turn on the red led	
P2=close;//close the gates
delay(900);
P2=stop;
delay(200);	
d=0;//turn off the red led
//c=0;//turn off the red led	
e=1;//turn on the green led
//d=0;//turn on the green led	
P2=open;
delay(300);
P2=stop;
delay(600);

}
}
}


//=======================CONNECTIONS=========================================
//1.all are very easy
//2.do the motor setup and then connect two batteries in parallel for powering the motor
//3.the usbasp programmer is easy and very easily connected to the dev board
//4.the four ir sensors dout is connected to pins 0,1,2,3 of PORT 0.
//5.the four ir sensors ground and vcc are connected to any ground and vcc of the dev board
//6.the wiring connections as shown in the video is bakwaas and need be done..i did it with jumper wires..its easy
//if you understand the logic
//7.bas these were all the connections that needed to be done..additionally you can connect the leds to give the signal lights
//they are also very easy
//==========================THE END OF CONNECTIONS==============================
