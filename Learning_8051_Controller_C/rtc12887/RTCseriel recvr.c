 #include<reg52.h>
  #include<absacc.h>
#define uc unsigned char
sbit rs=P3^6;
sbit e1=P3^7;
 uc mybyte;
void sendbyte(uc ch);
//lcd................
void display(uc *str);
void lcd_data(uc);
void delay(unsigned int y);
void lcd_ini();
void lcd_cmd(uc);


void seriel0()interrupt 4
{ 
if(RI==1)
{
 mybyte=SBUF;
//lcd_cmd(0x80);
delay(20);
 lcd_data(mybyte);
}
RI=0;
}
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
IE=0x92;
lcd_cmd(0x80);
delay(10);
display("hai ");
delay(10);	

while(1)
{

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
P0=commandword;
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
P0=ch;
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


//void sendString(uc *str)
//{
//delay(100);
//while(*str)
//{
//sendbyte(*str);
//delay(20);
//str++;
//}
//}
//void sendbyte(uc ch)
//{
//SBUF=ch;
//while(!TI);
//TI=0;
//}