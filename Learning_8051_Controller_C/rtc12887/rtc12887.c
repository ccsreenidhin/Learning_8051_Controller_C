 #include<reg52.h>
  #include<absacc.h>
#define uc unsigned char
sbit rs=P1^0;
sbit e1=P1^1;
void sendString(uc *str);
void lcd_data(uc);
void delay(unsigned int y);
void lcd_ini();
void lcd_cmd(uc);

void main()
{
delay(200);
lcd_ini();
delay(20);

lcd_cmd(0x80);		   //ho0me forst line
//delay(20);
sendString("hello");	 
//for(s=0;s<4;s++)
//{
// delay(2);
//lcd_data(m[s]);
//}

while(1);
  }

void lcd_ini()
{
lcd_cmd(0x38);		   //clear display and memory
delay(1);
lcd_cmd(0x0c);		   //display curser off
delay(1);
lcd_cmd(0x01);		 //5by 7 fjormat
delay(1);
lcd_cmd(0x02);		  //
delay(1);
}
//void sendString(uc mybyte[50])
//{
//int m=0;
//delay(10);
//while(1)
//{
//lcd_data(mybyte[m]);
//delay(20);
//m++;
//}
//}
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