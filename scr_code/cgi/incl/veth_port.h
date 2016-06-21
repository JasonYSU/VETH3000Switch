/**
****************************************************************************************
@File    : D:\ProgramFiles\KEIL\hal\src_code\cgi\incl\veth_port.h
@Author  : Duke Lee
@Date    : 21-Oct-2014
@Version : V1.0.00
@Breif   : CGI接口 ：port项头文件
****************************************************************************************
**/

#ifndef _VETH_PORT_H__
#define _VETH_PORT_H__

#include <stdint.h> 
#include "veth_marvell_88e6097f.h"
#include "veth_hal_init.h"
/*可能用到的宏定义*/
#define LINK_ON    1
#define LINK_DOWN  0

#define FULL_DPX   1
#define HALF_DPX   0

#define PACKAGE_MAX_LENTH  9600

#define CLEAR_ALL  0xff  //调用CLEAR_ALL_COUNTER 函数时，将此值传递给port变量表示清除所有的计数器
 /**
接口函数声明
**/

/***********************************************************************/
//函数名  ： Port_demo();
//功能    ： cgi接口函数：port项程序测试样例
//参数    ： None
//返回值  ： None
/***********************************************************************/
void Port_demo(void);

/***********************************************************************/
//函数名  :  Get_link_status(int portNo) 
//功能    ： 获取端口的link状态
//参数    ： 端口号portNo
//返回值  ： ’1‘ link on  ’0‘link down
//
/***********************************************************************/
int Get_link_status(int portNo);

/***********************************************************************/
//函数名  : Get_speed_status(int portNo)
//功能    ：获取端口的速率
//参数    ：端口号 portNo
//返回值  ：’10‘ 10M ，’100‘100M ，‘1000’ 1G
//
/***********************************************************************/
int Get_speed_status(int portNo);

/***********************************************************************/
//函数名  : Get_duplex_status(int portNo)
//功能    ：获取双工模式
//参数    ：端口号portNo
//返回值  ：’1‘表示全双工，’0‘表示半双工
//
/***********************************************************************/
int Get_duplex_status(int portNo);

/***********************************************************************/
//函数名  : Set_port_status(int portNo, PORT_STAS sta)
//功能    ：设置端口的速率
//参数    ：端口号：portNo ，需要设置的状态 PORT_STAS sta 端口状态枚举，具体看枚举定义
//返回值  ：None
//
/***********************************************************************/
void Set_port_status(int portNo, PORT_STAS sta);

/***********************************************************************/
//函数名  : Set_flow_control(int portNo, int flow_con)
//功能    ：设置端口的流控
//参数    ：端口号portNo，flow_con ：’1‘表示设置流控，’0‘表示取消流控设置
//返回值  ：None
//
/***********************************************************************/
void Set_flow_control(int portNo, int flow_con);

/***********************************************************************/
//函数名  : Get_flow_status(int portNo)
//功能    ：获取流控开启状态
//参数    ：端口号portNo
//返回值  ：'1'表示流控开启，’0‘表示流控关闭
//
/***********************************************************************/
int Get_flow_status(int portNo);

/***********************************************************************/
//函数名  : getPortType(int portNo)
//功能    ：获取端口类型
//参数    ：端口号portNo
//返回值  ：'1'表示光口，’0‘表示电口
//
/***********************************************************************/
int getPortType(int portNo);
 
/***********************************************************************/
//函数名  :  Get_max_package()
//功能    ： 获取支持的最大包长
//参数    ： None
//返回值  ： 最大包长
//
/***********************************************************************/
int Get_max_package(void);

/***********************************************************************/
//函数名  : Display_Rough_Statistics(int portNo，API_ROUGH_COUNTER_T *prough_cnt)
//功能    ：显示端口的流量统计
//参数    ：portNo，填入端口号进行统计
//          prough_cnt 传入的API_ROUGH_COUNTER_T指针，用来收集统计结果
//返回值  ：None
//
/***********************************************************************/
void Display_Rough_Statistics(int portNo,API_ROUGH_COUNTER_T *p_rough);

/***********************************************************************/
//函数名  : Display_Detail_Statistics(int portNo，API_DETAIL_COUNTER_T *pdetail)
//功能    ：显示端口的流量详细统计
//参数    ：portNo，填入端口号进行统计
//          pdetail 传入的API_DETAIL_COUNTER_T指针，用来收集统计结果
//返回值  ：None
//
/***********************************************************************/
void Display_Detail_Statistics(int portNo,API_DETAIL_COUNTER_T *p_detail);

/***********************************************************************/
//函数名  : Flush_ALL_counters()
//功能    ：清楚所有的数据统计
//参数    ：None
//返回值  ：None
//
/***********************************************************************/ 
void Flush_ALL_counters(void);

/***********************************************************************/
//函数名  : Flush_Port_counters(int portNo)
//功能    ：清除指定端口的计数器
//参数    ：端口号portNo
//返回值  ：None
//
/***********************************************************************/
void Flush_Port_counters(int portNo);

/***********************************************************************/
//函数名   ：Change_stats_mode()
//功能     ：切换关于端口流量详细统计的具体字节统计模式，64octets等等
//参数     ：histogram ,uint8_t 类型，取值范围在1到3之间 
//           模式'1'表示64octets一类的计数器只计Rx ，模式’2‘表示64octets一类计数器只计Tx，
//           模式’3‘表示64octets一类计数器计算Rx&Tx
//特别注意 ：每次切换详细字节64octets列计数模式时，内置所有计数器清0函数
/***********************************************************************/
void changeStatsMode(uint8_t histogram);

/***********************************************************************/
//函数名   ：Get_stats_mode()
//功能     ：获取关于端口流量详细统计的具体字节统计模式，64octets等等
//参数     ：None
//返回值   ：模式'1'表示64octets一类的计数器只计Rx ，模式’2‘表示64octets一类计数器只计Tx，
//             模式’3‘表示64octets一类计数器计算Rx&Tx
/***********************************************************************/
uint8_t getStatsMode(void);





#endif

