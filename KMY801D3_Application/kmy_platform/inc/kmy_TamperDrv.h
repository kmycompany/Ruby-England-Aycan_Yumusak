#ifndef __KMY_TAMPERDRV_H
#define __KMY_TAMPERDRV_H




#define TAMPER_TRIGGERED	0x01
#define TAMPER_NO_TRIGGER	0x02



void kmy_BackUpInit(void);
//�������ܣ� ��������ܳ�ʼ��
//������������
//����ֵ����
//ע�������



unsigned char kmy_CheckTamper(void);
//�������ܣ�������
//������������
//����ֵ��
//	���������TAMPER_TRIGGERED
//	û�������TAMPER_NO_TRIGGER
//ע�����
//	1. ִ�д˺���һ�κ����������־



void kmy_ClearTamper(void);
//�������ܣ���������־
//������������
//����ֵ����
//ע�������



#endif
