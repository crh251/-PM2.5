#include "uart.h"

unsigned char uart_buffer[UART_BUFFERLEN] = {'\0'};
unsigned char uart_count = 0;


//32MHZ us��ʱ������
#pragma optimize=none
void uart_delayus(unsigned int n_us)
{
    n_us>>=1;
    while(n_us--)
    {
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
          asm("NOP");
    }
}


void set_32MHZ(void)
{
    CLKCONCMD &= ~0x40;  //ϵͳʱ��ԴΪ32MHZ����
    while(CLKCONSTA & 0x40); //�ȴ�ʱ���ȶ���
    CLKCONCMD &= ~0x47; //ϵͳ��ʱ��Ƶ�ʣ�32MHZ;
}


void uart_init(unsigned char sys_clock , unsigned int baudrate)
{  
     P0SEL  |= 0x0c;  //����P0.2��P0.3Ϊ���裬��GPIO
     U0CSR  |= 0x80;  //���õ�ǰΪUART����SPI
    
     //#define UART_BAUD_9600   598
     //���ò����ʣ�
     U0GCR  &= 0xf0;
     if(baudrate < 3000)
     {
         U0BAUD = baudrate/10;  //59
         baudrate %= 10; //8
         baudrate += sys_clock;  //32M:0   16:1
         U0GCR |= baudrate;  
     }
     else
     {
         U0BAUD = baudrate/100;
         baudrate %= 100;
         baudrate += sys_clock;
         U0GCR |= baudrate;
     }
     
     UTX0IF  = 0;     //����жϱ�־
     U0CSR |=  0x40;  //�����������
     IEN0  |=  0x04;  //�򿪽����ж�   
     EA  = 1;  //�����ж�
}


void uart_sendstring(unsigned char *str , unsigned char len)
{
     unsigned char i;
     
     U0CSR &= ~0x40;  //��ֹ���գ�
     
     for(i = 0; i < len; i++)
     {
         U0DBUF = *str++;  //���ַ���һ��һ���ֽ�д�뻺������
         while(UTX0IF == 0); //�ȴ��жϱ�־λ��1��ʾ������ɣ�
         UTX0IF = 0; //������0��
     }
     
     U0CSR |= 0x40;  //������գ�
}


//���ڽ����жϷ�����
#pragma vector = URX0_VECTOR  
__interrupt void UART0_ISR(void)  
{  
    URX0IF = 0;       // ���жϱ�־;
    
    if(uart_count < UART_BUFFERLEN)
      uart_buffer[uart_count++] = U0DBUF;
}


unsigned char uart_readstring(unsigned char *str , unsigned char len)
{
      unsigned char i;
      unsigned char re_val = 0;  

      //��Ҫ����ʱ
      for(i = 0 ; i < 100 ;i++) //100ms
        uart_delayus(1000); 
      
      U0CSR &= ~0x40;  //��ֹ���գ�
      
      re_val = uart_count;

      for(i = 0; i<re_val && i<len; i++)
      {
          str[i] = uart_buffer[i];
      }
      str[i] = '\0';
            
      uart_count = 0;
    
      U0CSR |= 0x40;  //������գ�
      
      return re_val;
}

