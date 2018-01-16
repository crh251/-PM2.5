#ifndef __PUBLIC_H__
#define __PUBLIC_H__

//����ͷ�ļ�
#include <ioCC2530.h>


/**************************************************
*       �˿ں�����λ�궨�壬�����޸�
*/
//�˿�
#define Port0 0
#define Port1 1
#define Port2 2

//����λ
#define Bit0  0
#define Bit1  1
#define Bit2  2
#define Bit3  3
#define Bit4  4
#define Bit5  5
#define Bit6  6
#define Bit7  7

/**************************************************
*       ָ���˿�����ģʽ�������޸�
*/
#define Pn_m_IN_UP    0  //��������;
#define Pn_m_IN_DOWN  1  //��������
#define Pn_m_OUT      2  //���;





/**************************************************
*       ��������üĴ����������޸�
*/
//��λ������
#define LEFT_SHIFT(x) (1<<x)

//�Ĵ���PxSEL���ã�
#define PORTSEL_CONF(port , pin , val) { if(val == 0) P##port##SEL &= ~LEFT_SHIFT(pin);\
                                         else   P##port##SEL |= LEFT_SHIFT(pin);     }


//�Ĵ���PxDIR���ã�
#define PORTDIR_CONF(port , pin , val) { if(val == 0) P##port##DIR &= ~LEFT_SHIFT(pin);\
                                         else   P##port##DIR |= LEFT_SHIFT(pin);     }


//�Ĵ���PxINP���ã�
#define PORTINP_CONF(port , pin , val) { if(val == 0) P##port##INP &= ~LEFT_SHIFT(pin);\
                                         else   P##port##INP |= LEFT_SHIFT(pin);    }

//�漰���ļĴ����������ã�
#define REGISTER_CONF(port , pin , mode) {\
  if(mode == Pn_m_IN_UP || mode == Pn_m_IN_DOWN)\
    {\
      PORTDIR_CONF(port , pin , 0);\
        PORTSEL_CONF(port , pin , 0);\
          PORTINP_CONF(port , pin , 0);\
            PORTINP_CONF(2 , (5+port) ,mode);\
      }\
      else if(mode == Pn_m_OUT)\
        {\
          PORTDIR_CONF(port , pin , 1);\
            PORTSEL_CONF(port , pin , 0);\
      }\
}


/**************************************************************
*
*       �������ƣ�  register_config
*       ��������:     ����ָ���˿����ŵ�״̬
*       ����������
*                 param1���˿�(Port0/Port1/Port2)��
*                 param2: �˿ڵ�ĳ������(Bit0/Bit1/.../Bit7)
*                 param3���������Ź���ģʽ(����������/���)
*       ע�����P1_0 �� P1_1 ��������Ϊ����ģʽ          
*       ʹ��ʵ����
*                 //���� P2_0 Ϊ ��������;
*                 register_config(Port2 , Bit0 , Pn_m_IN_DOWN);
*                 
***************************************************************/
static void register_config(unsigned char port , unsigned char pin , unsigned char mode)
{
  switch(mode)
  {
  case Pn_m_IN_UP:
    {
      switch(port)
      {
      case Port0:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port0 , Bit0 , Pn_m_IN_UP) break;
          case Bit1:REGISTER_CONF(Port0 , Bit1 , Pn_m_IN_UP) break;
          case Bit2:REGISTER_CONF(Port0 , Bit2 , Pn_m_IN_UP) break;
          case Bit3:REGISTER_CONF(Port0 , Bit3 , Pn_m_IN_UP) break;
          case Bit4:REGISTER_CONF(Port0 , Bit4 , Pn_m_IN_UP) break;
          case Bit5:REGISTER_CONF(Port0 , Bit5 , Pn_m_IN_UP) break;
          case Bit6:REGISTER_CONF(Port0 , Bit6 , Pn_m_IN_UP) break;
          case Bit7:REGISTER_CONF(Port0 , Bit7 , Pn_m_IN_UP) break;
          default:
            break;
          }
        }
        break;
        
      case Port1:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port1 , Bit0 , Pn_m_IN_UP) break;
          case Bit1:REGISTER_CONF(Port1 , Bit1 , Pn_m_IN_UP) break;
          case Bit2:REGISTER_CONF(Port1 , Bit2 , Pn_m_IN_UP) break;
          case Bit3:REGISTER_CONF(Port1 , Bit3 , Pn_m_IN_UP) break;
          case Bit4:REGISTER_CONF(Port1 , Bit4 , Pn_m_IN_UP) break;
          case Bit5:REGISTER_CONF(Port1 , Bit5 , Pn_m_IN_UP) break;
          case Bit6:REGISTER_CONF(Port1 , Bit6 , Pn_m_IN_UP) break;
          case Bit7:REGISTER_CONF(Port1 , Bit7 , Pn_m_IN_UP) break;
          default:
            break;
          }
        }
        break;
      case Port2:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port2 , Bit0 , Pn_m_IN_UP) break;
          case Bit1:REGISTER_CONF(Port2 , Bit1 , Pn_m_IN_UP) break;
          case Bit2:REGISTER_CONF(Port2 , Bit2 , Pn_m_IN_UP) break;
          case Bit3:REGISTER_CONF(Port2 , Bit3 , Pn_m_IN_UP) break;
          case Bit4:REGISTER_CONF(Port2 , Bit4 , Pn_m_IN_UP) break;
          case Bit5:REGISTER_CONF(Port2 , Bit5 , Pn_m_IN_UP) break;
          case Bit6:REGISTER_CONF(Port2 , Bit6 , Pn_m_IN_UP) break;
          case Bit7:REGISTER_CONF(Port2 , Bit7 , Pn_m_IN_UP) break;
          default:
            break;
          }
        }
        break;
      default:
        break;
      }
    }
    break;  //Pn_m_IN_UP
    
  case Pn_m_IN_DOWN:
    {
      switch(port)
      {
      case Port0:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port0 , Bit0 , Pn_m_IN_DOWN) break;
          case Bit1:REGISTER_CONF(Port0 , Bit1 , Pn_m_IN_DOWN) break;
          case Bit2:REGISTER_CONF(Port0 , Bit2 , Pn_m_IN_DOWN) break;
          case Bit3:REGISTER_CONF(Port0 , Bit3 , Pn_m_IN_DOWN) break;
          case Bit4:REGISTER_CONF(Port0 , Bit4 , Pn_m_IN_DOWN) break;
          case Bit5:REGISTER_CONF(Port0 , Bit5 , Pn_m_IN_DOWN) break;
          case Bit6:REGISTER_CONF(Port0 , Bit6 , Pn_m_IN_DOWN) break;
          case Bit7:REGISTER_CONF(Port0 , Bit7 , Pn_m_IN_DOWN) break;
          default:
            break;
          }
        }
        break;
        
      case Port1:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port1 , Bit0 , Pn_m_IN_DOWN) break;
          case Bit1:REGISTER_CONF(Port1 , Bit1 , Pn_m_IN_DOWN) break;
          case Bit2:REGISTER_CONF(Port1 , Bit2 , Pn_m_IN_DOWN) break;
          case Bit3:REGISTER_CONF(Port1 , Bit3 , Pn_m_IN_DOWN) break;
          case Bit4:REGISTER_CONF(Port1 , Bit4 , Pn_m_IN_DOWN) break;
          case Bit5:REGISTER_CONF(Port1 , Bit5 , Pn_m_IN_DOWN) break;
          case Bit6:REGISTER_CONF(Port1 , Bit6 , Pn_m_IN_DOWN) break;
          case Bit7:REGISTER_CONF(Port1 , Bit7 , Pn_m_IN_DOWN) break;
          default:
            break;
          }
        }
        break;
      case Port2:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port2 , Bit0 , Pn_m_IN_DOWN) break;
          case Bit1:REGISTER_CONF(Port2 , Bit1 , Pn_m_IN_DOWN) break;
          case Bit2:REGISTER_CONF(Port2 , Bit2 , Pn_m_IN_DOWN) break;
          case Bit3:REGISTER_CONF(Port2 , Bit3 , Pn_m_IN_DOWN) break;
          case Bit4:REGISTER_CONF(Port2 , Bit4 , Pn_m_IN_DOWN) break;
          case Bit5:REGISTER_CONF(Port2 , Bit5 , Pn_m_IN_DOWN) break;
          case Bit6:REGISTER_CONF(Port2 , Bit6 , Pn_m_IN_DOWN) break;
          case Bit7:REGISTER_CONF(Port2 , Bit7 , Pn_m_IN_DOWN) break;
          default:
            break;
          }
        }
        break;
      default:
        break;
      }
    }
    break; //Pn_m_IN_DOWN
    
  case Pn_m_OUT:
    {
      switch(port)
      {
      case Port0:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port0 , Bit0 , Pn_m_OUT) break;
          case Bit1:REGISTER_CONF(Port0 , Bit1 , Pn_m_OUT) break;
          case Bit2:REGISTER_CONF(Port0 , Bit2 , Pn_m_OUT) break;
          case Bit3:REGISTER_CONF(Port0 , Bit3 , Pn_m_OUT) break;
          case Bit4:REGISTER_CONF(Port0 , Bit4 , Pn_m_OUT) break;
          case Bit5:REGISTER_CONF(Port0 , Bit5 , Pn_m_OUT) break;
          case Bit6:REGISTER_CONF(Port0 , Bit6 , Pn_m_OUT) break;
          case Bit7:REGISTER_CONF(Port0 , Bit7 , Pn_m_OUT) break;
          default:
            break;
          }
        }
        break;
        
      case Port1:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port1 , Bit0 , Pn_m_OUT) break;
          case Bit1:REGISTER_CONF(Port1 , Bit1 , Pn_m_OUT) break;
          case Bit2:REGISTER_CONF(Port1 , Bit2 , Pn_m_OUT) break;
          case Bit3:REGISTER_CONF(Port1 , Bit3 , Pn_m_OUT) break;
          case Bit4:REGISTER_CONF(Port1 , Bit4 , Pn_m_OUT) break;
          case Bit5:REGISTER_CONF(Port1 , Bit5 , Pn_m_OUT) break;
          case Bit6:REGISTER_CONF(Port1 , Bit6 , Pn_m_OUT) break;
          case Bit7:REGISTER_CONF(Port1 , Bit7 , Pn_m_OUT) break;
          default:
            break;
          }
        }
        break;
      case Port2:
        {
          switch(pin)
          {
          case Bit0:REGISTER_CONF(Port2 , Bit0 , Pn_m_OUT) break;
          case Bit1:REGISTER_CONF(Port2 , Bit1 , Pn_m_OUT) break;
          case Bit2:REGISTER_CONF(Port2 , Bit2 , Pn_m_OUT) break;
          case Bit3:REGISTER_CONF(Port2 , Bit3 , Pn_m_OUT) break;
          case Bit4:REGISTER_CONF(Port2 , Bit4 , Pn_m_OUT) break;
          case Bit5:REGISTER_CONF(Port2 , Bit5 , Pn_m_OUT) break;
          case Bit6:REGISTER_CONF(Port2 , Bit6 , Pn_m_OUT) break;
          case Bit7:REGISTER_CONF(Port2 , Bit7 , Pn_m_OUT) break;
          default:
            break;
          }
        }
        break;
      default:
        break;
      }
    }
    break; //Pn_m_OUT
    
  default:
    break;
  }
}








#endif