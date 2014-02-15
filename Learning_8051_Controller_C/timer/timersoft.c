	 #include<reg52.h>
#define uc unsigned char
sbit mybit=P1^7;
 void main()
 {
 int count=0;
 unsigned char sec,min;
   P2=0;
   mybit==1;
   P3^4==1;
 TMOD=0x05;
 TH0=0x00;
 TL0=0x00;
 TR0=1;
  while(mybit==0)
 {
 min=TL0;
 
 if(min>5)
 {
 TR0=0;
 TH0=0X00;
 TL0=0X00;
  TR0=1;
  }
 P2=min;
}

  }
