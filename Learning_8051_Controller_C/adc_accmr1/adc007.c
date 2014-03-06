	 #include<reg52.h>
#define uc unsigned char
 sbit rs=P2^6;
 sbit en=P2^7;
sbit start=P3^0;
sbit eoc=P3^1;
sbit oe=P3^3;
sbit buzzer=P2^0;

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
 P0=0;
 lcd_ini();
 delay(5);
 lcd_cmd(0x80);
  sendString("hello");
 while(1)
 {
  lcd_cmd(0x80);
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
  void adcconv(unsigned int go)
  {
  unsigned int d,e,f,g,h;
  d=go/10;
  e=d/100;
  f=d%10;
  g=d/10;
  h=g%10;
  lcd_data(e+0x30);
  delay(2);
  lcd_data(h+0x30);
 delay(2);
lcd_data(f+0x30);
 delay(2);
// if(d>12)
// {
// buzzer=1;
// delay(100);
// buzzer=0;
// delay(100);

//  switch(d)
//  {
////  	case 1:
////	case 2:
////	case 3:
////
////	case 5:
////  		 lcd_data(0x38);
////		 lcd_data(0x66);
////			delay(2);
////			break;
//  
//// at 	15 degree rignt
// case 5:
//  		 lcd_data(0x31);
//		 lcd_data(0x35);
//			lcd_data(0x4c);
//			delay(2);
//				break;
// //at 	 8 degree rignt
// case 6:
//  		 lcd_data(0x38);
//		 lcd_data(0x4c);
//			delay(2);
//				break;
// //when sensor is level
//	case 7:
//
//  		 lcd_data(0x30);
//				delay(2);
//			break;
// //at 8 degree
// 		case 8:
// 
//  		 lcd_data(0x38);
//		 lcd_data(0x52);
//			delay(2);
//			break;
////at 15 degree left
//	 case 9:
//  		 lcd_data(0x31);
//			   lcd_data(0x35);
//			   		 lcd_data(0x52);
//			delay(2);
// 			 break;
// // at all other degrees towards left and rignt
//   default:
//		  lcd_data(0x66);
//		  lcd_data(0x61);
//  		  lcd_data(0x69);
//		  lcd_data(0x6c);
//		//  buzzer=1;
//		  delay(2);
//		  break;
//  }
  }

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
P0=cmdword;
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
P0=databyte;
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