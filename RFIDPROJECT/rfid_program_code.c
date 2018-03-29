#include<stdio.h>
#include<reg52.h>
#include<string.h>
#include<lcd_functions.h>
#include<uart_functions.h>//

//lcd_functions.h contains functions for LCD display
//uart_functions.h contains functions for serial port communication

sbit buzzer=P2^3;//in the video it says that the buzzer is connected to the pin 2 of port 3 but while typing they typed this
int i,j;
char stored_cardid[12]={"020010709BF9"};//id of the tag which has access

void motor(){//function for the motor to turn on and operate the gates
	P2=0x01;//will turn the gate clockwise
	delay(200);
	P2=0x00;//will stop the gate
	delay(200);
	P2=0x02;//will turn the gate anti-clockwise
	delay(200);
	P2=0x00;//will stop the gate
	delay(200);
}


void main(){
	while(1){
		int count=0;
		int count1=0;
		int count2=0;
		int count3=0;
		int count4=0;
		int count5=0;
		int flag=0;
		buzzer=0;
		lcdint();//initialize the lcd
		
		//after initialization display the text "sarnava" in the first line of the lcd
		
		while(text[count]!='\0'){//run the loop while there is character left in the text array
			display(text[count]);//display letters of "sarnava" one by one in quick succession
			count++;
		
	}
	 //display the text "RFID Access Cont" in the second line of the lcd
  	
	lcdcmd(0xC0);//go to the second line of the lcd
	
	while(text1[count1]!='\0'){//run the loop while there is character left in the text array
			display(text1[count1]);//display letters of "sarnava" one by one in quick succession
			count1++;
		
	}
	
	receive();//receive _data from the EM-18 redear module serially
	//run a loop 12 times to check if each of the letter of the card matches that of the stored card id;
	for(j=0;j<=11;j++){
		if(stored_cardid[j]==a[j]){
			flag=flag+1;
		}
	}
	
	if(flag==12){//if all the letters match
		lcdcmd(0x01);//clear the lcd screen
		lcdcmd(0x80);//bring the cursor to the first line of the lcd screen
	  
		while(text2[count2]!='\0'){//run the loop while there is character left in the text array
			display(text2[count2]);//display letters of "welcome" one by one in quick succession
			count2++;
		
	}
		
		lcdcmd(0xC0);//ini the cursor to the second line of the lcd
	
	 while(text3[count3]!='\0'){//run the loop while there is character left in the text array
			display(text3[count3]);//display letters of "access granted" one by one in quick succession
			count3++;
		
	}
	 
	delay(500);
	motor();//open the gates
}
	else{
		lcdcmd(0x01);//clear the lcd screen
		lcdcmd(0x80);//bring the cursor to the first line of the lcd screen
	  
		while(text4[count4]!='\0'){//run the loop while there is character left in the text array
			display(text4[count4]);//display letters of "access denied" one by one in quick succession
			count4++;
		
	}
		
	delay(500);
	
	buzzer=1;
	delay(100);
	buzzer=0;
	delay(100);
 }
}
	}

	
	
	
	
//	1.0th pin is the ground pin..connect it to any gnd pin of the dev board
//2.1st pin is the vcc pin..connect it to any vcc pin of the dev board
//3.2nd pin is the contrast control pin..connectiong it to gnd will give it max contrast..altrnatively could have connected it to 
//a potentiometer which would have adjusted its contrast.
//4.the 3rd pin is the _register pin..connect it to signal pin 7 of port 3
//5.the 4th pin is the read or write pin...connect it to signal pin 6 of port 3
//6.the 5th pin is the enable pin...connect it to signal pin 5 of port 3
//7.the 15th pin is a gnd pin..connect it to any gnd of dev board
//8.the 14th pin is a vcc pin..connect to any vcc pin of dev board..
//9.the rest are _data pins and are connected to port0 pins like..
  //D0 TO P0 PIN1,D1 TO P0 PIN2 and are continued like this
//10. the positive pin of the buzzer connected to L+ and negative to L-
//11.the red of the motor to R- and the black to R+.
//12.the ground of the EM-18 module connected to any gnd of the dev board
//13.the Tx pin of the module is connected to P3 signal pin 0 which is the Rx pin of the microcontroller..
//14.open the putty client and set the connection type to serial and the communication port to the channel to which the USB
//TO UART bridge is connected..to do this go to control panel and then device manager and then see to which port it is connected
//15.then follow the _code as it is written in keil
//16.
 




