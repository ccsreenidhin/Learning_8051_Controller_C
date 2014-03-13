#include<reg52.h>
#include<absacc.h>
#define uc unsigned char
void delay(unsigned int y);

void main()
{
delay(400);
XBYTE[10]=0x20;	//A
XBYTE[11]=0x83;
XBYTE[0]=0x55;
XBYTE[2]=0x15;
XBYTE[4]=0x10;
XBYTE[7]=0x22;
XBYTE[8]=0x01;
XBYTE[9]=0x13;
//XBYTE[1]=0x00;
//XBYTE[3]=0x55;
//XBYTE[5]=0x14;
XBYTE[11]=0x03;
while(1)
{
P2=0;
delay(100);
P2=0xff;
delay(100);
}
}
void delay(unsigned int y)
{
unsigned int i,k;
for(i=0;i<y;i++)
for(k=0;k<250;k++);

}