sbit RS=P3^7;//_register select pin
sbit RW=P3^6;//read and write pin
sbit EN=P3^5;//enable pin

char text[7]=("SARNAVA");

unsigned char text1[20]=("RFID Access Cont");
unsigned char text2[7]=("WELCOME");
unsigned char text3[15]=("Access Granted");
unsigned char text4[18]=("Access Denied");

void delay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++){
		for(j=0;j<1275;j++);
	}
	
}

//function for sending value to the command _register of lcd


void lcdcmd(unsigned char value){

	//for the lcd module to accept command the RS pin and the RW pin must be set to low and the EN pin must be set to 1 for the 
	//lcd module to process _data and then we add a delay to accomodate the minimum execution time which is 10 milisec
	RS=0;
	RW=0;
	P0=value;
	EN=1;
	delay(10);
	EN=0;
	
	return;
}

//function to send the value to the _data _register of the lcd

void display(unsigned char value){
	RS=1;
	RW=0;
	P0=value;
	EN=1;
	delay(10);
	EN=0;
	return;
}

//function to initialize the registers and the pins of the lcd
//always use with every lcd of hitachi
void lcdint(void){
	lcdcmd(0x38);
	delay(20);
	lcdcmd(0x0C);
	delay(20);
	lcdcmd(0x01);
	delay(20);
	lcdcmd(0x06);
	delay(20);
	lcdcmd(0x80);
	delay(20);
}


