#ifndef __KMY_USART3DRV_H
#define __KMY_USART3DRV_H





void kmy_USART3Init(unsigned long BaudRate);
//�������ܣ����ڳ�ʼ��
//����������brd: ������
//����ֵ����
//ע�������



void kmy_USART3SendString(const unsigned char *Buff);
//�������ܣ� �����ַ���
//����������Buff: �����ַ�����buff
//����ֵ����
//ע�������





void kmy_USART3SendData(const unsigned char *Buff, unsigned int SendSize);
//�������ܣ�  ��������
//����������
//	Buff:  �������ݵ�buff
//	SendSize:�������ݵĳ���
//����ֵ����
//ע�������





void kmy_USART3ReceiveReset(void);
//�������ܣ� ��USART3 �ѽ��ܵ������ֽڶ���
//������������
//����ֵ����
//ע�������





unsigned int kmy_USART3ReceiveData(unsigned char *Buff,unsigned int RecSize,unsigned long timeout_MilliSeconds);
//�������ܣ� ���ܴ��ڵ�����
//����������
//	Buff: �������ݴ�ŵĵط�
//	RecSize: ���ܶ��ٸ��ֽ�
//	timeout_MilliSeconds: ��ʱ�ĺ�����
//����ֵ�����ؽ��ܵ����ֽ���
//ע�������


#endif
