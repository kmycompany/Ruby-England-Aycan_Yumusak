#ifndef __KMY_KEYDRV_H
#define __KMY_KEYDRV_H


//key define
#define KEY1				0x02
#define KEY2				0x01
#define KEY3				0x06
#define KEY4				0x05
#define KEY5				0x04
#define KEY6				0x03
#define KEY7				0x08
#define KEY8				0x0c
#define KEY9				0x07
#define KEY0				0x0a
#define KEYXING				0x0b
#define KEYJING				0x09

#define KEY_UP				0x18
#define KEY_DOWN			0x19
#define KEY_LEFT			0x17
#define KEY_RIGHT			0x16

#define KEY_L1				0x10
#define KEY_L2				0x0f

#define KEY_R1				0x15
#define KEY_R2				0x0d
#define KEY_R3				0x14
#define KEY_R4				0x13
#define KEY_R5				0x1c
#define KEY_R6				0x1e


#define KEY_pseudo					255			//pseudo key
#define KEY_WaitTimeout				254			//wait timeout pseudo key
#define KEY_NONE					0
#define KEY_ReturnPrevious			KEY_L1		//return previous key
#define KEY_ReturnInitInterface		KEY_R2		//return init interface key
#define KEY_Enter					KEY_R1		//Enter key
#define KEY_DEL						KEY_L2		//delete key
#define KEY_F1						KEY_R3
#define KEY_F2						KEY_R4
#define KEY_F3						KEY_R5
#define KEY_F4						KEY_R6
#define KEY_HandsFree				KEY_R6






void kmy_KeyInit(void);
//�������ܣ�key ��ʼ��
//������������
//����ֵ����
//ע�������


unsigned char kmy_GetKeyValue(void);
//�������ܣ�ȡ����ֵ
//������������
//����ֵ��
//	���水���궨��
//ע�������


void kmy_AutoOffLcdLight(unsigned long seconds);
//�������ܣ����ö������ر�lcd �ı���
//����������
//	seconds: ʱ�������
//����ֵ����
//ע�����
// 	1 ���seconds==0ȡ�����õ�����
// 	2 ���û��ʱ�����������������
// 	֮ǰ���õ�������ȡ�����Ա��ε�
// 	���������¼���


void kmy_AutoPostKey(unsigned long seconds);
//�������ܣ����ö�������Զ�����KEY_WaitTimeout
//����������
//	seconds: ʱ�������
//����ֵ����
//ע�����
// 	1 ���seconds==0ȡ�����õ�����
// 	2 ���û��ʱ�����������������
// 	֮ǰ���õ�������ȡ�����Ա��ε�
// 	���������¼���
// 	3 �����������������kmy_GetKeyValue()����
// 	�����������ϻ�õ�KEY_WaitTimeout ����ֵ


void kmy_PostKey(unsigned char key);
//�������ܣ�ֱ���ü�ֵ
//����������
//	key: ����ֵ�������ļ��ĺ궨��
//����ֵ����
//ע�����
//	1 ��ִ���������֮����kmy_GetKeyValue()����
// 	�����������ϻ�õ��β�key �� ����ֵ
// 	2 ���������һЩ����ĳ����ã�һ���û������õ�



void kmy_EnterPowerDownMode(void);
//�������ܣ�����͹��ĵ�ֹͣģʽ
//������������
//����ֵ����
//ע�����
//	����˺�������Ļ�����κ���ʾ
//	��������˳��͹��ĵ�ֹͣģʽ


#endif
