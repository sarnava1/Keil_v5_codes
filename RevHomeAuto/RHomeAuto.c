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
	P0=0XFF;//SETTING ALL PINS OF PORT0 TO 1;
	
	while(1){
		receive();
	
		if(a=='a'){
			b=1;
		}
		
		if(a=='A'){
			b=0;
		}

		if(a=='b'){
			c=1;
		}

		if(a=='B'){
			c=0;
		}
	}
}
//the 'C','c','b','B' are actually the syntax of the app...they are of no such imp logic..it will only switch on and off the
//digital signals to the pin


//==================================================================
//         CONNECTIONS
//==================================================================
//1.the USBASP programmer connections are easy to made as it has only 6 pins and the corresponding pins in the dev board are 
// clearly marked
//2.the oonnections from the main 220v ac to the bulbs via the plug is clearly drawn in my diary..also the connections to the 
//relay are easily understood by seeing in the diary and it is clearly done..
//3.now the vcc and ground of the relay are connected to any vcc and ground pin of the dev board and the relay pin 1 of the relay
//are connected to the P0 pin 0 and the relay pin 2 of the relay are connected to the P0 pin 1..
//4.now the connections of the bluetooth module is left..the vcc and ground of the module are connected to the vcc and ground sockets of P3 pin 0
//and the transmission pin of the module is connected to the P3 pin 0 signal socket as it is the bluetooth receiving pin(it is the general
//receiver) of the board
//with this we finish all the connections of the project
