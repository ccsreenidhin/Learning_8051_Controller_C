	 #include<reg52.h>
#define uc unsigned char
 

sbit rs=P3^4;
sbit en=P3^3;


void display(uc *str);
void lcd_data(uc);
void lcd_ini();
void lcd_cmd(uc);

void delay(unsigned int y);

  void main()

 {

//P1=0;
 P2=0;								  
 lcd_ini();
 delay(5);
 lcd_cmd(0x80);
display("hello dear");
 while(1);
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