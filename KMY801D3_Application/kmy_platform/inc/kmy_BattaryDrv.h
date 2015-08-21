#ifndef __KMY_BATTARTDRV_H
#define __KMY_BATTARTDRV_H



typedef enum
{ ChargeStatus_Charge = 1,
	ChargeStatus_DisCharge,
}CHARGESTATUS;


typedef enum
{ AcStatus_Plug = 1,
	AcStatus_UnPlug,
}ACSTATUS;



void kmy_BatInit(void);
//�������ܣ���� ��ʼ��
//������������
//����ֵ����
//ע�������



unsigned char kmy_BatGetChargeStatus(void);
//�������ܣ��õ����״̬
//������������
//����ֵ��
//	�ڳ�緵��(�궨��)ChargeStatus_Charge
//	���ڳ�緵��(�궨��)ChargeStatus_DisCharge
//ע�������



unsigned char kmy_BatGetACStatus(void);
//�������ܣ��õ���ӵ�Դ�Ƿ����״̬
//������������
//����ֵ��
//	��ӵ�Դ���뷵��(�궨��)AcStatus_Plug
//	��ӵ�Դδ���뷵��(�궨��)AcStatus_UnPlug
//ע�������



#endif
