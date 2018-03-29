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

			 
