 #include<reg52.h>
#define uc unsigned char
//lcd......
sbit rs=P3^6;
sbit en=P3^7;
void sendString(uc *str);
void lcd_data(uc);
void lcd_ini();
void lcd_cmd(uc);
//adc......
sbit start=P3^0;
sbit eoc=P3^1;
sbit oe=P3^2;
void adcconv(unsigned char value);
//......
void delay(unsigned int y);
//main.................
void main()
{
unsigned char value,b;
P2=0;			  /*.......for writing to lcd........*/
P1=0xff;				/*.....tne i/p from adc.....*/
P3=0;
delay(20);
lcd_ini();
delay(20);
lcd_cmd(0x80);
delay(10);
	  sendString("hello");
	  delay(200);


	while(1)
	{
	start=0;
	delay(10);
		start=1;
	while(eoc==1);

	delay(1);
		value=P1;
		oe=1;
	delay(10);
	oe=0;
	delay(10);
	adcconv(value);
	delay(10);
	//start=0;
eoc=1;
	
	}
}
void lcd_ini()
{
lcd_cmd(0x38);
delay(1);
lcd_cmd(0x0c);
delay(1);
lcd_cmd(0x01);
delay(1);
lcd_cmd(0x02);
delay(1);
}
void sendString(uc *str)
{
delay(10);
while(*str)
{
lcd_data(*str);
delay(20);
str++;
}
}
void lcd_cmd(uc commandword)
{
rs=0;
P2=commandword;
delay(10);
e1=1;
delay(10);
e1=0;
delay(10);
e1=1;
}
void lcd_data(uc ch)
{
rs=1;
P2=ch;
delay(10);
e1=1;
delay(10);
e1=0;
delay(10);
e1=1;
}
void delay(unsigned int y)
{
unsigned int i,k;
for(i=0;i<y;i++)
for(k=0;k<250;k++);
}

void adcconv(unsigned int x)
{
unsigned int d,e,f,t;
f=x%10;
t=x/10;
e=t%10;
d=t/10;

//lcd_cmd(0xc0);
lcd_data(d+0x30);
delay(2);
lcd_data(e+0x30);
delay(2);
lcd_data(f+0x30);
delay(2);
}