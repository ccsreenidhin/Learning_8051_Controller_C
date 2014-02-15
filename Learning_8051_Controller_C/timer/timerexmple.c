   	 #include<reg52.h>
#define uc unsigned char
void signal(uc);
//void signal1();
  void main()

 {
  
 P2=0;
 
  while(1)
 {
 P2=~P2;
 if(P1^0==0)
 {
 signal(0);
 }
 else
 {
 signal(1);
 }
 }
 }
 	
void signal(uc c)
{ 
TMOD=0X01;
if(c==0)
 {
 TH0=0xFC;
 TL0=0x65;
 }
 else
 {
 TH0=0xFD;
 TL0=0x98;
 }

 TR0=1;
 while(TF0==0);
 TF0=0;
 TR0=0;
 }

