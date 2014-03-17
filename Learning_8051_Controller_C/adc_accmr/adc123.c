 #include<reg52.h>
#define uc unsigned char
 sbit rs=P3^7;
 sbit en=P3^6;
sbit start=P0^3;
sbit eoc=P0^4;
sbit oe=P0^5;

void sendString(uc *str);
void lcd_data(uc);
void lcd_ini();
void lcd_cmd(uc);

void adcconv(uc gotdata);

void delay(unsigned int y);

  void main()

 {
  unsigned char gotdata;
 //P3=0;
 P1=0xff;
 P2=0;
 lcd_ini();
 delay(5);
 lcd_cmd(0x80);
  sendString("hello");
 while(1)
 {
  lcd_cmd(0xc0);
 oe=1;
   eoc=1;
 start=0;
 delay(10);
 start=1;
 
 while(eoc);
  oe=0;
 delay(5);
 gotdata=P1;
 adcconv(gotdata);
 delay(5);

 }
 }








//fns.........
  void adcconv(unsigned char go)
  {
  unsigned char d,e,f,g,h;
  d=go/10;
  e=go/100;
  h=d%10;
  f=go%10;
  lcd_data(e+0x30);
  delay(2);
  lcd_data(h+0x30);
 delay(2);
lcd_data(f+0x30);
 delay(2);
  }
//  switch(d)
//  {
//  	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//  		 lcd_data(0x38);
//			delay(2);
//			break;
// case 6:
// case 7:
// case 8:
//  		 lcd_data(0x35);
//			delay(2);
//				break;
// case 9:
// case 10:
// case 11:
//  		 lcd_data(0x32);
//			delay(2);
//				break;
// 
//	case 12:
//  		 lcd_data(0x30);
//			delay(2);
//			break;
// 	case 13:
//	case 14:
//	case 15:
//  		 lcd_data(0x34);
//			delay(2);
//			break;
//	case 16:
//  		 lcd_data(0x39);
//			delay(2);
// 			 break;
// 
//  		

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
delay(5);
en=1;
delay(20);
en=0;
delay(10);
en=1;
delay(20);
}

  void lcd_data(uc databyte)
{
rs=1;
P2=databyte;
en=1;
delay(20);
en=0;
delay(10);
en=1;
delay(20);
}

void sendString(uc *str)
{
delay(10);
while(*str)
{
lcd_data(*str);
delay(10);
str++;
}
}
void delay(unsigned int k)
{
unsigned int i,j;
for(i=0;i<k;i++)
for(j=0;j<250;j++);
}