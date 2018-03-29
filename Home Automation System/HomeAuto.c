#include<reg52.h>
#include<stdio.h>

//_sbit variable type is used to refer to particular pins of a port
//_ is used with _sbit as _sbit is a keyword(understand it nicely)
sbit b=P0^0;
sbit c=P0^1;

unsigned int a;
//store the value of the bits in the SBUF reg

void receive(){
	TMOD=0X20; //TIMER 1 AUTO RELOAD(8 _BIT AUTO RELOAD)
	TH1=0XFD; //SET BAUD RATE=9600
	SCON=0X50;//SET 8 BIT UART MODE
	TR1=1;//ENABLE TIMER1
  
	while(RI==0);//WAIT FOR RECEIVE INTERRUPT TO BECOME 1
	a=SBUF;//VALUE FROM SBUF STORED IN VARIABLE A
	RI=0;
}

void main(){
	P0=0X00;//SETTING ALL PINS OF PORT0 TO 0;
	
	while(1){
		receive();
	
		if(a=='a'){
			b=0;
		}
		
		if(a=='A'){
			b=1;
		}

		if(a=='b'){
			c=0;
		}

		if(a=='B'){
			c=1;
		}
	}
}
