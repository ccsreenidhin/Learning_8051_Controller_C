    	 #include<reg52.h>
#define uc unsigned char

void main()
 {
 int count=0,bigcount=0;
 //unsigned char sec,y,a,b,c;
 
 
 
 TMOD=0x06;		
 TH0=0x00;
  while(1)
  {
 TR0=1;
 
 count=TL0;
 P2=count;
 
 }
 }