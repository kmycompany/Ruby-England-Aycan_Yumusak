#ifndef __KMY_PA1200DRV_H
#define __KMY_PA1200DRV_H

#define ReadMagCardReturnInit		0x02
#define ReadMagCardReturnPrev		0x03
#define ReadMagCardTimeOut			0x04
#define ReadMagCardDateError		0x05
#define ReadMagCardReturnEnter		0x06

#define ReadMagCardSuccess			0x0a

void kmy_MagcardInit(void);
//函数功能：磁条卡初始化
//函数参数：无
//返回值：无
//注意事项：无






char kmy_MagcardRead(unsigned char *track1,unsigned char *track2,unsigned char *track3,unsigned int timeout_Seconds);
//函数功能：读磁条卡数据
//函数参数：
//	track1:	第1磁道缓冲区
//	track2:	第2磁道缓冲区
//	track3:	第3磁道缓冲区
//返回值：
//	读卡成功返回(宏定义)ReadMagCardSuccess
//	用户按EXIT 键返回(宏定义)ReadMagCardReturnInit
//	用户按Return键返回(宏定义)ReadMagCardReturnPrev
//	用户按Confirm 键返回(宏定义)ReadMagCardReturnEnter
//	超时返回(宏定义)ReadMagCardTimeOut
//	卡数据错误返回(宏定义)ReadMagCardDateError
//注意事项：
//	1. 现行的硬件没有track1，这个参数可为NULL
//	2. 如果不需要读track3，可以把这个形参设为NULL,但是track2 一定不能为NULL
//	3. 磁道1 track1 应该大于200bytes
//	4. 磁道2 track2 应该大于200bytes
//	5. 磁道3 track2 应该大于200bytes






#endif
