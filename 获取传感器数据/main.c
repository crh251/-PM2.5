#include "uart.h"
#include "sensor.h"
#include <stdio.h>
#include "DHT11.h"
#include <string.h>

void main(void)
{
  unsigned int pmval = 0;
  
  char str[21];
  float calcVoltage = 0;
  float dustDensity = 0;
  
  uchar temp[3]; 
  uchar humidity[3];   
  uchar strTemp[13]="Temperature:";
  uchar strHumidity[10]="Humidity:";
  

  set_32MHZ();
  uart_init(SYS_CLOCK_32MHZ , UART_BAUD_115200);//���ڲ�����Ϊ115200 8N1
  sensor_init();  //��ʼ�����������;
  
  delay_ms(2000);          //���豸�ȶ�
  
  while(1)
  {
    memset(temp, 0, 3);
    memset(humidity, 0, 3);
     

    DHT11();             //��ȡ��ʪ��
    pmval = sennor_getpmval(); //��ȡģ��ֵ
    calcVoltage = (float)pmval * (3.3 / 2047.0); //��ģ��ֵת��Ϊ��ѹֵ
    
    
    //����ѹֵת��Ϊ�۳��ܶ������λ 
    //ȡ�����ȡƽ��ֵ*��Ӧ��ϵ��(����ϵ��ʹ��800~1000)����ʾPM2.5
    //������β���GP2Y1010AU0F����ϵ��Ϊ800 GP2Y1014Ϊ120�ȽϺ���
    dustDensity = calcVoltage*200.0;
    
    
    //����ʪ�ȵ�ת�����ַ���
    temp[0]=wendu_shi+0x30;
    temp[1]=wendu_ge+0x30;
    humidity[0]=shidu_shi+0x30;
    humidity[1]=shidu_ge+0x30;
    
    //��õ���ʪ��ͨ�����������������ʾ
    uart_sendstring((unsigned char *)strTemp , 12);
    uart_sendstring((unsigned char *)temp , 2);
    uart_sendstring((unsigned char *)" " , 1);
    uart_sendstring((unsigned char *)strHumidity , 9);
    uart_sendstring((unsigned char *)humidity , 2);
    uart_sendstring((unsigned char *)" " , 1);

    sprintf( str, "Dust:%.1f\r\n", dustDensity);
    uart_sendstring((unsigned char *)str , strlen(str));
    
    delay_ms(1000);
  }
  
}









