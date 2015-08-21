#ifndef __KMY_PRINTERDRV_H
#define __KMY_PRINTERDRV_H

#define Printer_OK							1
#define Printer_NoPaper						2

extern const  char WidthZoom1[4];//����� X 1
extern const  char WidthZoom2[4];//����� X 2
extern const  char WidthZoom3[4];//����� X 3
extern const  char WidthZoom4[4];//����� X 4
extern const  char WidthZoom5[4];//����� X 5

extern const  char HighZoom1[4]; //����� X 1
extern const  char HighZoom2[4]; //����� X 2
extern const  char HighZoom3[4]; //����� X 3
extern const  char HighZoom4[4]; //����� X 4
extern const  char HighZoom5[4]; //����� X 5

extern const  char Zoom1[4];     //���� X 1
extern const  char Zoom2[4];     //���� X 2

/*Ŀǰֻ֧����������ASCII����л���ʹ��ʱֻ�轫������������strcat����ӡ�ַ����м���*/
extern const  char Font1[4];     //���� 16 X 16
extern const  char Font2[4];     //���� 24 X 24

extern const char underlineOFF[4];     //�»��߹�
extern const char underlineON[4];     //�»��߿�


void kmy_PrinterInit(unsigned char mode);
//�������ܣ���ӡ����ʼ��
//����������
//   mode:  0   ��ʼ�����д�ӡ������
//          1   ֻ��ʼ����ӡ����Ŀ��ߡ�
//����ֵ��  ��
//ע�������


char kmy_PrinterSetcommand(const char * command,unsigned char len);
//�������ܣ���ӡ����������
//����������
//	command:  �����ַ���
//	len: �����
//����ֵ��
//	���óɹ�����(�궨��)Printer_OK
//  ������ȱֽ���ʱ: ȱֽ����Printer_NoPaper
//ע�������


char kmy_PrinterString(unsigned char *Data);
//�������ܣ���ӡ����ӡ�ַ���
//����������
//	*Data:  �ַ���
//����ֵ��
//	��ӡ��ɷ���(�궨��)Printer_OK
//	ȱֽ����(�궨��)Printer_NoPaper
//ע�����
//	1. Data�������ַ������Ⱦ���С��2048bytes

char kmy_PrinterBitmap(const unsigned char *p,unsigned int width, unsigned int height,unsigned int LeftMarginNum);
//�������ܣ���ӡ����ӡλͼ
//����������
//	p:  λͼ���ݻ������׵�ַ
//	width:  λͼ���
//	height:  λͼ�߶�
//	LeftMarginNum:  λͼ������ĵ㿪ʼ����
//����ֵ��
//	��ӡ��ɷ���(�궨��)Printer_OK
//	ȱֽ����(�궨��)Printer_NoPaper
//ע�����
//	λͼ��ʽΪ:��ɫ����Һ����ģ������ȡģ���ֽڵ���
//	LeftMarginNum+width��ֵӦ��С��384��
//	λͼ���Ŀ��Ϊ384


char PrintBarCode(char *Databuff);
//�������ܣ���ӡ����ӡ����(ֻ֧�ִ�ӡcode128��)
//����������
//	*Databuff:  �����ַ�
//����ֵ��
//	��ӡ��ɷ���(�궨��)Printer_OK
//	ȱֽ����(�궨��)Printer_NoPaper
//ע�����
//	1. �ܴ�ӡ��ȵ�Ӱ�죬Databuff�������ַ������Ȳ��ܴ���10���ַ���

char kmy_PrintFlashBitmap(void);

#endif

