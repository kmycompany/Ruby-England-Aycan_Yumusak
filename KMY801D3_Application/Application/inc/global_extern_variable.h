#ifndef global_extern_variable_H
#define global_extern_variable_H

#include "main.h"

//#include "global_extern_variable.h"


extern MyCallFuction	CurProc_Return;
extern MyCallFuction	CurProc;


extern char InitFlag;
extern char NoElecFlashLed;
extern char ShortcutKeyEnterFlag;				//��ݼ������־


extern const unsigned char softwareversion[9];
extern char RequirePin;
extern unsigned char gEnterPowerDownFlag;
extern unsigned char gFlushDataFlag;

extern char ATsendreceive_Lock;
extern char gCheckOrderFail;
extern char Net_ONOFF;//Net_ONOFF=0 on; Net_ONOFF=1 off;
extern char Net_State;
extern char WiFiState; 


#endif

