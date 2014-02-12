#include<reg52.h>
#define uc unsigned char
//lcd............
sbit rs=P1^7;
sbit en=P3^3;
void display(uc *str);
void lcd_data(uc);
void lcd_ini();
void lcd_cmd(uc);
//serielj...................
void sendString(uc *str);
unsigned char recvbyte();
void sendbyte(uc);
void delay(unsigned int y);
void seriel_ini();
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
//}
// main.............................................
void main()
{
uc k[20],i=0;
 P2=0;
 lcd_ini();
 delay(5);
 lcd_cmd(0x80);
 display("hi");

seriel_ini();


  while(i<8)
	{
	k[i]=recvbyte();
	lcd_data(k[i]);
	i++;
	}
 
while(1)
	{
	}
}

// lcd fns.........................
	   void lcd_ini()
{
lcd_cmd(0x01);
delay(20);
lcd_cmd(0x0c);
delay(20);
lcd_cmd(0x38);
delay(20);
  lcd_cmd(0x02);   
  delay(20);
}

void lcd_cmd(uc cmdword)
{	  
rs=0; 
P2=cmdword;
en=1;
delay(2);
en=0;
delay(2);
}

  void lcd_data(uc databyte)
{
rs=1;
P2=databyte;
en=1;
delay(2);
en=0;
delay(2);

}

void display(uc *str)
{

while(*str)
{
lcd_data(*str);
str++;
}
}
// seriel fns..........................
void seriel_ini()
{
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
delay(100);
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
unsigned char recvbyte()
{
while(!RI);
RI=0;
return(SBUF);
}