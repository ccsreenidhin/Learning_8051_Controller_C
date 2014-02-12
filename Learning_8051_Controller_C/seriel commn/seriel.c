	 #include<reg52.h>
#define uc unsigned char

void sendString(uc *str);
void delay(unsigned int y);
void main()

 {	
 SCON=0X50;
 TMOD=0X20;
 TH1=0XFD;
 TR1=1;   
 
 delay(10);
  while(1){
  sendString("set time.....");
  delay(10);
  }
}
  

  void sendString(uc *str)
{
uc ch;
delay(10);
while(*str)
{
ch=*str;
SBUF=ch;
delay(10);
while(!TI);
str++;
}
}
void delay(unsigned int k)
{
unsigned int i,j;
for(i=0;i<k;i++)
for(j=0;j<250;j++);
}