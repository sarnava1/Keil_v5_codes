//the STARTUP.A51 contains instructions to be run when the microcontroller is reset
//steps to write a project in keil:
//1.open it from taskbar or anywhere
//2.from project click on new mewvision project
//3.after that in the desired folder save your new project by giving it a name
//4.after that give your file a suitable name and the extension will be given by them only
//5.after that follow the normal steps
//6.after that click on on new for new file and write the _code there and give it a .c extension.
//7.enjoy coding
//====================================================================================================

#include<stdio.h>
#include<reg52.h>
sbit led0=P0^0;//relay 1 controls the bright bulb!!!!
sbit led1=P0^1;//relay 2 controls the dim bulb!!!!!

signed int occupants,s1,s2;

void main(){
	occupants=0;
	s1=0;//variable associated with the first sensor
	s2=0;//variable associated with the 2nd sensor
	EA=1;//this enables all the interrupts of the 8051 microcontroller as it is the global enable _interrupt _bit
	EX0=1;//enabling the external interrupts of pin 2 and 3 of port 3
	EX1=1;//enabling the external interrupts of pin 2 and 3 of port 3
	IT0=1;//setting the falling edge triggered _interrupt in the TCON _register
	IT1=1;//setting the falling edge triggered _interrupt in the TCON _register
	
	led0=1;
	led1=1;
	
//	while(1){
//		if(occupants>0){
//			led0=1;//switches on the bright bulb
//			led1=0;//switches off the dim bulb
//		}
//		else{
//			led0=0;//switches off the bright bulb!!!
//			led1=1;//switches on the dim bulb!!!!
//		}
//	}
//}

	while(1){
		if(occupants%2==1){
			led0=0;//switches on the bright bulb
			led1=1;//switches off the dim bulb
		}
		else{
			led0=1;//switches off the bright bulb!!!
			led1=0;//switches on the dim bulb!!!!
		}
	}
}


//writing the _interrupt service routine
//second method is this
//void ISR_ex0(void) //_interrupt 0
//{
//	s1++;
//	if(s1-s2>0){
//		occupants++;
//	}
//}

//void ISR_ex1(void) _interrupt 1
//{
//	s2++;
//	if(s2-s1>0){
//		occupants--;
//	}
//}

//the first method

void ISR_ex0(void) interrupt 0
{
	s1++;
	if(s1%2==1){
		occupants++;
}
}


//=============================CONNECTIONS==================================================================

//1.the relay connections are the same as as that of project 1
//2.the usbasp programmer connections are the same as they were in all the projects.
//3.the 220V ac connections to the relay and then to the bulbs are the same as that of project 1 and are drawn in my diary.
//4.the only new thing is the IC 7404 and the 2 PIR sensors.
//5.the pin diagram of the pir sensors are easily available in the net
//6.connect the vcc pin of the pir sensors to the vcc row of the breadboard and the ground pin of the pir sensors to the ground row 
//of the pir sensors
//7.take a breadboard and connect ground and vcc from the dev board to the last row of the dev board(i think you are understanding 
//what i am talking of now
//8.take the ic 7404(NOT GATE) and then connect its 14th pin to the vcc row and the 7th pin to the ground row
//9.connect the voltage output pin of the two pirs to the 1 and 3 pin of the ic
//10.conect the 2nd pin of the ic to the port 3 pin 2 signal pin
//11.connect the 4th pin of the ic to the port 3 pin 3 signal pin
//12.the relay connections are as usual the same thing
//13.bas!!!!only these were the connections of this project
//========================THANK YOU =========================================================================