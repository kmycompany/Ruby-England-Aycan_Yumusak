#ifndef _kmy_adc_h
#define _kmy_adc_h

#include "stm32f10x.h"

void kmyAdcInit(void);
//�������ܣ�ADC ��ʼ��
//������������
//����ֵ����
//ע�������

uint16_t kmyGetAdc(void);   
//�������ܣ���ȡ����ֵ
//������������
//����ֵ�����ز���ֵ
//ע�������

uint16_t kmyGetVoltage(void);
//�������ܣ���ȡ����ֵ
//������������
//����ֵ�����ص�ѹֵ
//ע�������

#endif
