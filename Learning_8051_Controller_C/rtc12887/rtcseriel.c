 #include<reg52.h>
  #include<absacc.h>
#define uc unsigned char
sbit rs=P1^0;
sbit e1=P1^1;
uc valH,valL,i; 
void sendbyte(uc ch);
void sendString(uc *str);
//lcd................
void display(uc *str);
void lcd_data(uc);
void delay(unsigned int y);
void lcd_ini();
void lcd_cmd(uc);
//rtc...............
void bcdconv(uc val);

//void external0()interrupt 0
//{ 
//P1^2==1;
//for(i=0;i<10;i++)
//{
//lcd_cmd(0x01);
//delay(200);
//lcd_cmd(0x85);
//sendString("ALARM");
//delay(200);
//}
//P1^2==0;
//}
//main..................
void main()
{
unsigned char sec,min,hr,day,month,year;
delay(200);
//P2=0;
//P1=0;
lcd_ini();
delay(20);
TMOD=0X20;
TH1=0XFD;
SCON=0X50;
TR1=1;
//TCON=0x01;
//IE=0x81;
lcd_cmd(0x80);
delay(10);
display("DATE ");
delay(10);	
sendString("hello");	
delay(10);   //ho0me forst line
while(1)
{
//date display............
//lcd_cmd(0x01);
//lcd_cmd(0x80);
//delay(20);
 //sendString("DATE ");
 //lcd_cmd(0x85);
 //delay(10);		
//day=XBYTE[7];
//bcdconv(day);
// lcd_data(':');
//month=XBYTE[8];
//bcdconv(month);
//lcd_data(':');
//year=XBYTE[9];
//bcdconv(year);
//time displayj..................
lcd_cmd(0x01);
//sendString("TIME ");
//lcd_cmd(0xC5);
//delay(10);
delay(20);
hr=XBYTE[4];
bcdconv(hr);
sendbyte(':');
min=XBYTE[2];
bcdconv(min);
sendbyte(':');
sec=XBYTE[0];
bcdconv(sec);
//if(hr>80)
//{
//lcd_data(' ');
//lcd_data('P');
//}
//else
//{
//lcd_data(' ');
//lcd_data('A');
//}
//lcd_data('M');
}
  }

void lcd_ini()
{
lcd_cmd(0x38);		   //clear display and memory
delay(10);
lcd_cmd(0x0c);		   //display curser off
delay(10);
lcd_cmd(0x01);		 //5by 7 fjormat
delay(10);
lcd_cmd(0x02);		  //
delay(10);
}

void display(uc *str)
{
delay(100);
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
delay(20);
e1=1;
delay(20);
e1=0;
delay(20);
e1=1;
}
void lcd_data(uc ch)
{
rs=1;
P2=ch;
delay(20);
e1=1;
delay(20);
e1=0;
delay(20);
e1=1;
}
void delay(unsigned int y)
{
unsigned int i,k;
for(i=0;i<y;i++)
for(k=0;k<250;k++);

}
void bcdconv(uc val)
{
//if(val>0x80)
//{
//valH=val&0x10;
//valH=valH>>4;
//valH=valH|0x30;
//lcd_data(valH);
//
//valL=val&0x0f;
//valL=valL|0x30;
//lcd_data(valL);
//}
//
//else
//{
valH=val&0xf0;
valH=valH>>4;
valH=valH|0x30;
sendbyte(valH);
delay(10);
valL=val&0x0f;
valL=valL|0x30;
sendbyte(valL);
//}
}

void sendString(uc *str)
{
delay(100);
while(*str)
{
sendbyte(*str);
delay(20);
str++;
}
}
void sendbyte(uc ch)
{
SBUF=ch;
while(!TI);
TI=0;
}