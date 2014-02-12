#include<reg52.h>

#define uc unsigned char
void seriel_ini();
void sendString(uc *str);
unsigned char recvbyte();
void sendbyte(uc);

void delay(unsigned int y);

 void main()
{
delay(20);
seriel_ini();
delay(1000);
delay(200);	

while(1)
	{

 sendString("i am jabir...");

	}
}
// seriel fns..........................
void seriel_ini()
{
delay(10);
TMOD=0x20;
SCON=0x50;
//IE=0X92;
TH1=0xFD;
TR1=1;
}
void sendString(uc *str)
{
delay(10);
while(*str)
{
delay(1000);
sendbyte(*str);
str++;
}
}
void sendbyte(uc ch)
{
SBUF=ch;
delay(20);
while(!TI);
TI=0;
}
void delay(unsigned int y)
{
unsigned int i,k;
for(i=0;i<y;i++)
for(k=0;k<250;k++);
}