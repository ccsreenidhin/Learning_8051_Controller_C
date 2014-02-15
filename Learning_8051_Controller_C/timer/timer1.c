   	 #include<reg52.h>
#define uc unsigned char
int count=0;

sbit rs=P3^6;
sbit en=P3^7;
sbit hrsw=P1^6;
sbit minsw=P1^7;

void sendString(uc *str);
void lcd_data(uc);
void lcd_ini();
void lcd_cmd(uc);

void delay(unsigned int y);

void timer0() interrupt 1
{
count++;
}

void main()
 {

 unsigned char sec=0,min=0,hr=0,y,a,b,c,x,z,i,j,k;
 //P1=0xff;
 P2=0;
//  P1^6=0;
//P1^7=0;
// P3^5=1;
  TMOD=0x52;				//timer1 as counter in mode 2 fjor time setting..
  TH1=0X00;
  TL1=0X00;
 lcd_ini();
 delay(5);

 //  setting the time........
lcd_cmd(0x80);
 sendString("set time");
 delay(50);
 lcd_cmd(0x01);
delay(20);
 lcd_cmd(0x80);
 sendString("set hr");
 delay(20);
 
    	//Entering hour......
	TR1=1;	 
 while(hrsw==1)
 {
 hr=TL1;
 if(hr>23)
 {
TR1=0;
 TH1=0X00;
 TL1=0X00;
  TR1=1;
 } 
 y=hr/10;
 z=hr%10;

  lcd_cmd(0xc0);
    lcd_data(y+0x30);
 lcd_data(z+0x30);
 }
 TR1=0;

  lcd_cmd(0x01);
delay(20);
 lcd_cmd(0x80);
 sendString("set min");
delay(20);	
		   // Entering minutes
TH1=0X00;
 TL1=0X00;
TR1=1;								   
  while(minsw==1)
 {
 min=TL1;
 if(min>59)
 {
TR1=0;
 TH1=0X00;
 TL1=0X00;
  TR1=1;
}
 j=min/10;
 k=min%10;
  lcd_cmd(0xc0);
    lcd_data(j+0x30);
 lcd_data(k+0x30);
  }
 TR1=0;

 // .time is set ....now it is displayed....
 lcd_cmd(0x01);
delay(20);
 lcd_cmd(0x80);
  sendString("time");
 
 

 IE=0x82;
 TH0=0x05;
 TR0=1;
  while(1)
 {
 while(hr<24)
 {
  while(min<60)
  {
 while(sec<60)
 {
 while(count<3686) 
 {
 a=sec%100;
 b=a/10;
 c=sec%10;

 i=min%100;
 j=i/10;
 k=min%10;

x=hr%100;
 y=x/10;
 z=hr%10;

 lcd_cmd(0xc0);
    lcd_data(y+0x30);
 lcd_data(z+0x30);

   lcd_data(':');

   lcd_data(j+0x30);
 lcd_data(k+0x30);

 lcd_data(':');

  lcd_data(b+0x30);
 lcd_data(c+0x30);


  }
 count=0;
// P1=~P1;
 sec++;
 
 }
 sec=0;
min++;
}
min=0;
hr++;
}
hr=0;
 }
 }
// fns...........

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
delay(1);
en=0;
delay(1);
en=1;
}

  void lcd_data(uc databyte)
{
rs=1;
P2=databyte;
en=1;
delay(1);
en=0;
delay(1);
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