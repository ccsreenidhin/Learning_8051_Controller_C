	 #include<reg52.h>
#define uc unsigned char
 

sbit rs=P3^4;
sbit en=P3^3;
  sbit buzzer=P0^2;
  
unsigned char s;



void display(uc *str);
void lcd_data(uc);
void lcd_ini();
void lcd_cmd(uc);

void delay(unsigned int y);


void external0() interrupt 0
{
buzzer=0;	   
}

  void main()

 {
 buzzer=1;
 P2=0;	
 lcd_ini();
 delay(5);
  lcd_cmd(0x80);
display("hello dear");
 delay(5000);							  
 display("    accdnt");
 TCON=0x01;
 IE=0X81;
 delay(5000);
 lcd_cmd(0x80);
display("      detctr");
 delay(4000);
  while(1)
 {
 if(buzzer==0)
 {
 lcd_cmd(0x01);
 for(s=0;s<7;s++)
  {
   lcd_cmd(0x85);
   display("accident");
    delay(1000);
	 lcd_cmd(0x01);
	  delay(1000);
	}
	buzzer=1;
	delay(2);
	}
}
 } 

	   void lcd_ini()
{
lcd_cmd(0x01);
delay(2);
lcd_cmd(0x0c);
delay(2);
lcd_cmd(0x38);
delay(2);
  lcd_cmd(0x02);   
  delay(2);
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
//delay(2);
while(*str)
{
lcd_data(*str);
//delay(2);
str++;
}
}
void delay(unsigned int k)
{
unsigned int i,j;
for(i=0;i<k;i++)
for(j=0;j<250;j++);
}