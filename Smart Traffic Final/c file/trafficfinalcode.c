#include<stdio.h>
#include<reg52.h>
unsigned int a,i,j;
void delay(unsigned int t){
    for(i=0;i<t;i++){
      a=P3&0x0f;
      if(a!=0x00)
      break;
      for(j=0;j<5000;j++);
     }
}
//i have wrote a better _code for this traffic system in notepad file name "mytrafficcode".
//please have a look into that _code
//actually here when no cars will be coming from any side then one side at a time will be on and the delay function will be called 
//wherein it will wait for a few seconds for the particular lane to be on and the others will be red.
//but there is a problem that there in that delay function it will again check whether there is a car at that time and if yes
//it will break from that particulart loop and go to main function again...now this is absolutely fine if no car is coming from
//any side but if a car is coming from any side then there will be problem with the delay function.
//this is because it will check in the main function from where a car is coming and will turn on the green led for that lane and will
// call the same delay function wherein there will be a check again from where the car is coming..now the problem is if a car is detected
//from another side then there will be the problem that my initial car led will be switched from green to red in a very short span 
//of time leaving scope for a accident..so i have introduce sigdelay function in my new _code
//please see my notepad file for that

//void sigdelay(){
	//_int k=0;
	//for(k=0;k<=4000;k++);
//}


void main(){
   while(1){
     a=P3&0x0f;
		 if(a==0x00){
			 P0=0x1e;
			 delay(150);
			 P0=0x2d;
			 delay(150);
			 P0=0x4b;
			 delay(150);
			 P0=0x87;
			 delay(150);
		 }
		 //side 1 is on my right and side 3 is on my left and side 2 is on top of the screen side and side 4 is on the bottom of the screen
		 //if car comes from side 1 then green led connected to pin 4 will glow and the others reds will glow except pin 0;
		 if(a==0x01){
			 P0=0x1e;
			 delay(250);
		 }
		 //if car comes from side 2 then green led connected to pin 5 will glow and the others reds will glow except pin 1;
		 if(a==0x02){
			 P0=0x2d;
			 delay(250);
		 }
		 //if car comes from side 3 then green led connected to pin 6 will glow and the others reds will glow except pin 2;
		 if(a==0x04){
			 P0=0x4b;
			 delay(250);
		 }
		 //if car comes from side 4 then green led connected to pin 7 will glow and the others reds will glow except pin 3;
		 if(a==0x08){
			 P0=0x87;
			 delay(250);
		 }
	 }
 }

//==================================================================
//         CONNECTIONS
//==================================================================
//1.the USBASP programmer connections are easy to made as it has only 6 pins and the corresponding pins in the dev board are 
// clearly marked
 //2.the four object sensors are connected to the port 3 of the board like : it has 8 pins..we wikll attach our pins to the first 4
 //pins of the port 3..our first object sensor will go to P3 pin 0,second to P3 pin 1,third to P3 pin 2 and fourth to P3 pin 3
 //each of the sensors will have 3 pins coming out..one is Vcc,another in ground and the DOUT..vcc goes to the outermost socket of 
 // a pin,the ground goes to the second socket of a pin and the last DOUT pin goes to the innermost socket of a pin...these finishes
 //all the connections of the socket..
 //3.now the leds are connected to port 0..the earthing of all the leds are common and is connected to any ground pin of the board
 //and the anodes of all the leds are connected to the 8 pins of the port 0...now it will be like suppose if the red led anode 
 //is connected to the pin 0 then its corresponding green led in connected to pin 4,like this red of another to pin 1 and its green to pin 5
 //and like this it continues..
 //4.thus all the connectionns are finished and we are done with it...but after we finish flashing the _code to the microcontroller
 //we will disconnect the wirings of the usbasp programmer....
 
 
