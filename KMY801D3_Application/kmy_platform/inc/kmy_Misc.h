#ifndef __KMY_MISC_H
#define __KMY_MISC_H




void kmy_MiscInit(void);
//�������ܣ�����ܳ�ʼ��
//������������
//����ֵ����
//ע�������


void kmy_MiscGetChipUniqueId(unsigned  char *buff);
//�������ܣ��õ�оƬΨһid
//����������
//	buff: оƬid���buff
//����ֵ����
//ע������뱣֤buff ��С���ڵ���25bytes


void kmy_MiscGetRandomNumber(unsigned  char *buff,unsigned int len);
//�������ܣ��õ������
//����������
//	buff: ��������buff
//����ֵ����
//ע�������



void kmy_MiscGetLibraryVersion(unsigned  char *buff);
//�������ܣ�ȡ��kmy  ������汾��
//����������
//	buff: kmy  ������汾�Ŵ��buff
//����ֵ����
//ע������뱣֤buff ��С���ڵ���9bytes




#endif
