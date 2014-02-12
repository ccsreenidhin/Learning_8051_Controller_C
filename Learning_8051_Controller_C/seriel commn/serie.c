#include<reg52.h>
#define uc unsigned char
//lcd............
sbit rs=P3^4;
 sbit en=P3^3;

void display(uc *str);
void lcd_data(uc);
void lcd_ini();
void lcd_cmd(uc);
//serielj...................
void sendString(uc *str);
//unsigned char recvbyte();
void sendbyte(uc);
void delay(unsigned int y);
void seriel_ini();

unsigned char mybyte;
//void seriel() interrupt 4
//{
//if(RI==1)
//{

//mybyte=SBUF;
//lcd_data(mybyte);
//RI=0;
//}
//else
//TI=0;
//
//}
void main()
{
 P2=0;
 P1=0;
 //lcd_ini();
 delay(5);
 seriel_ini();
  delay(500);
delay(200);
 //lcd_cmd(0x80);
 //lcd_cmd(0x80);

while(1)
	{
	 sendString("hello.........");
	}
}

// lcd fns.........................
	   void lcd_ini()
{
lcd_cmd(0x01);
delay(10);
lcd_cmd(0x0c);
delay(10);
lcd_cmd(0x38);
delay(10);
  lcd_cmd(0x02);   
  delay(10);
}

void lcd_cmd(uc cmdword)
{	  
rs=0; 
P2=cmdword;
en=1;
delay(20);
en=0;
delay(20);
}

  void lcd_data(uc databyte)
{
rs=1;
P2=databyte;
en=1;
delay(20);
en=0;
delay(20);
}

void display(uc *str)
{
delay(10);
while(*str)
{
lcd_data(*str);
delay(10);
str++;
}
}
// seriel fns..........................
void seriel_ini()
{
delay(10);
TMOD=0x20;
SCON=0x50;
//IE=0X90;
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
//unsigned char recvbyte()
//{
//delay(20);
//while(!RI);
//RI=0;
//return(SBUF);
//}