#ifndef __KMY_EEPROMDRV_H
#define __KMY_EEPROMDRV_H



void kmy_EepromInit(void);

char kmy_EepromWrite(unsigned short addr,const unsigned char *data, int n);

char kmy_EepromWriteByte(unsigned short addr,const unsigned char data);


char kmy_EepromWritePage(unsigned short addr,const unsigned char *data,unsigned char n);


char kmy_EepromReadByte(unsigned short addr,unsigned char *readvalue);


char kmy_EepromReadSequent(unsigned short addr,unsigned char *readvalue,unsigned short nByte);	  


unsigned char kmy_EepromCheckWhetherBlankChip(void);
//�������ܣ����eepromоƬ�Ƿ�Ϊ�µĿ�оƬ
//����������
//	оƬ���µĿ�оƬ����1
//	оƬ�����µĿ�оƬ����0
//����ֵ����
//ע�������

#endif
