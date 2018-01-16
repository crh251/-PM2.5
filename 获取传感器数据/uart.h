#ifndef __UART_H__
#define __UART_H__

//����ͷ�ļ�
#include <ioCC2530.h>


//ϵͳʱ��
#define SYS_CLOCK_32MHZ  0
#define SYS_CLOCK_16MHZ  1

//������
#define UART_BAUD_2400   596
#define UART_BAUD_4800   597
#define UART_BAUD_9600   598
#define UART_BAUD_14400  2168
#define UART_BAUD_19200  599
#define UART_BAUD_28800  2169
#define UART_BAUD_38400  5910
#define UART_BAUD_57600  21610
#define UART_BAUD_76800  5911
#define UART_BAUD_115200 21611
#define UART_BAUD_230400 21612

//���ն���
#define UART_BUFFERLEN 30  //���ջ��������ȣ�
extern unsigned char uart_buffer[UART_BUFFERLEN]; //���ջ�������
extern unsigned char uart_count; //��ǰ���ջ��������ֽ�����


/******************************************
*
*     ����������uart_delayus
*     �������ܣ�us��ʱ
*     ����ʹ�ã�
*               param1: ��ʱ���ٸ�us
*
*******************************************/
void uart_delayus(unsigned int n_us);


/******************************************
*
*     ����������set_32MHZ
*     �������ܣ�����ϵͳʱ��Ϊ32MHZ
*
*******************************************/
void set_32MHZ(void);


/******************************************
*
*     ����������uart_init
*     �������ܣ���ʼ������1��
*     ����ʹ�ã�
*               param1: ��ǰϵͳʱ��
*               param2: ͨ�Ų�����
*
*******************************************/
void uart_init(unsigned char sys_clock , unsigned int baudrate);


/******************************************
*
*     ����������uart_sendstring
*     �������ܣ�����1�����ַ���
*     ����ʹ�ã�
*               param1: Ҫ���͵��ַ���
*               param2: Ҫ�����ַ����ĳ���
*
*******************************************/
void uart_sendstring(unsigned char *str , unsigned char len);


/******************************************
*
*     ����������uart_readstring
*     �������ܣ�����1��ȡ�ַ���
*     ����ʹ�ã�
*               param1: ��ȡ�����ַ���
*               param2: param1�ĳ���
*     ��������ֵ����ȡ�����ֽ���
*
*******************************************/
unsigned char uart_readstring(unsigned char *str , unsigned char len);


#endif