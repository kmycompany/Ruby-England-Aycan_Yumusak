#ifndef __KMY_PA1200DRV_H
#define __KMY_PA1200DRV_H

#define ReadMagCardReturnInit		0x02
#define ReadMagCardReturnPrev		0x03
#define ReadMagCardTimeOut			0x04
#define ReadMagCardDateError		0x05
#define ReadMagCardReturnEnter		0x06

#define ReadMagCardSuccess			0x0a

void kmy_MagcardInit(void);
//�������ܣ���������ʼ��
//������������
//����ֵ����
//ע�������






char kmy_MagcardRead(unsigned char *track1,unsigned char *track2,unsigned char *track3,unsigned int timeout_Seconds);
//�������ܣ�������������
//����������
//	track1:	��1�ŵ�������
//	track2:	��2�ŵ�������
//	track3:	��3�ŵ�������
//����ֵ��
//	�����ɹ�����(�궨��)ReadMagCardSuccess
//	�û���EXIT ������(�궨��)ReadMagCardReturnInit
//	�û���Return������(�궨��)ReadMagCardReturnPrev
//	�û���Confirm ������(�궨��)ReadMagCardReturnEnter
//	��ʱ����(�궨��)ReadMagCardTimeOut
//	�����ݴ��󷵻�(�궨��)ReadMagCardDateError
//ע�����
//	1. ���е�Ӳ��û��track1�����������ΪNULL
//	2. �������Ҫ��track3�����԰�����β���ΪNULL,����track2 һ������ΪNULL
//	3. �ŵ�1 track1 Ӧ�ô���200bytes
//	4. �ŵ�2 track2 Ӧ�ô���200bytes
//	5. �ŵ�3 track2 Ӧ�ô���200bytes






#endif
