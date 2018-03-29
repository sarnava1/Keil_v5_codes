#include<reg52.h>
#include<stdio.h>
//reg52 contains referneces to the pin structure of the 8051 microcontroller
unsigned char a[12];

//serial receive functions
//sbuf _register sets the RI _bit to 1 when it successfully receives a byte

void receive(){
	unsigned int s;
  TMOD=0X20; //TIMER 1 AUTO RELOAD(8 _BIT AUTO RELOAD)
  TH1=0XFD; //SET BAUD RATE=9600
  SCON=0X50;//SET 8 BIT UART MODE
  TR1=1;//ENABLE TIMER1
	
	for(s=0;s<=11;s++){
		while(RI==0){};//receive interupt flag
		a[s]=SBUF;
		RI=0;
	}
	
}

  