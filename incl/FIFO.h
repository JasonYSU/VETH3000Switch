/***************************************************************************************
�����⣺FIFO.C
ԭʼ�汾�ţ�V1.0
��ʼ�ˣ���ǿ
���°汾�ţ�V1.0
����˵����
�����ˣ�
***************************************************************************************/


#ifndef _FIFO_H
#define _FIFO_H
#include <stdint.h>
#include <stdlib.h>
//#include "config.h"

#define OneCircle     1//��ʾдָ����ָ���Ѿ�ѭ����һȦ
#define ZeroCircle    0//��ʾдָ����ָ��û��ѭ��һȦ���������߶��Ѿ�����һȦ
#define NOMORENUM     0//��ʾû�ж���Ŀռ�
#define WriteSuccess  1//�ɹ�������д��FIFO
#define ReadSuccess   1//�ɹ���FIFO��������

typedef struct _FIFO
{
    uint8_t   *pFirst;//ָ��FIFO���׵�ַ
    uint8_t    *pLast; //ָ��FIFO��ĩ��ַ
    uint8_t    *pCurrentData;//�ñ���û��ʹ��
    uint32_t  Length;//FIFO���ܳ���

    uint8_t   FlagWrite;//д��FIFO�����ݱ�־����ѡZeroCircle����OneCircle
    uint8_t   FlagRead;//����FIFO�����ݱ�־����ѡZeroCircle����OneCircle
    uint32_t  CanWriteNum;//���ܱ�д������ݳ���
    uint32_t  CanReadNum;//�ܱ����������ݳ���
    uint32_t  CurrentWriteNum;//��ǰдָ��������׵�ַ�ǵڼ�������
    uint32_t  CurrentReadNum;//��ǰ��ָ��������׵�ַ�ǵڼ�������
}FIFO;

/***************************************************************************************
��  ����void CreateFIFO(uint32 FIFOLength)
��������FIFOLength��Ҫ������FIFO�ĳ��ȴ�С
����ֵ����
��  ע���ú���ʹ���˶�̬�ڴ���䣬����Ҫ����ʹ����
***************************************************************************************/
void CreateFIFO(FIFO *DmaFIFO,uint32_t FIFOLength);

void InitFIFO(FIFO *DmaFIFO,uint8_t *pbuffer,uint32_t FIFOLength);
/***************************************************************************************
��  ����uint8 WriteFIFO(int8* pSource,uint32 WriteLength)
��������pSource��ָ��Ҫ����Դ��һ��ָ��
        WriteLength��Ҫд��FIFO�����ݳ���
����ֵ��0--��ʾҪд��ĳ��ȳ�����FIFO��д��ĳ��ȣ�
        1--��ʾ�ɹ�д��
��  ע���ú�������������FIFO����д��ָ�����ȵ����ݣ�������ݳ�����д���Ƚ����ش���ֵ
***************************************************************************************/
uint8_t WriteFIFO(FIFO *myFIFO,uint8_t* pSource,uint32_t WriteLength);

/***************************************************************************************
��  ����uint8 ReadFIFO(int8 *pAim,uint32 ReadLength)
��������pAim��ָ��ҪĿ��Դ��һ��ָ��
        ReadLength��Ҫд��FIFO�����ݳ���
����ֵ��0--��ʾҪ��ȡ�ĳ��ȳ�����FIFO�ɶ�ȡ�ĳ��ȣ�
        1--��ʾ�ɹ���ȡ
��  ע���ú����������ǽ�FIFO��������ݶ�����ָ����һ���ط�
***************************************************************************************/
uint8_t ReadFIFO(FIFO *myFIFO,uint8_t *pAim,uint32_t ReadLength);

/***************************************************************************************
��  ����uint32 CheckFIFOLength(void)
��������
����ֵ��FIFO���ܳ���
��  ע��
***************************************************************************************/
uint32_t CheckFIFOLength(FIFO *myFIFO);

/***************************************************************************************
��  ����int8* CheckCurrentWritePoint(void)
��������
����ֵ����ǰдָ��ľ���λ��
��  ע��
***************************************************************************************/
uint8_t * CheckCurrentWritePoint(FIFO *myFIFO);

/***************************************************************************************
��  ����int8* CheckCurrentReadPoint(void)
��������
����ֵ����ǰ��ָ��ľ���λ��
��  ע��
**************************************************************************************/
uint8_t * CheckCurrentReadPoint(FIFO *myFIFO);

/***************************************************************************************
��  ����void FreeFIFO(void)
��������
����ֵ��
��  ע���ͷ�FIFOռ�õ��ڴ�
***************************************************************************************/
void FreeFIFO(FIFO *myFIFO);

/***************************************************************************************
��  ����uint32 CheckCanWriteNum(void)
��������
����ֵ�����ػ���д��FIFO�����ݳ���
��  ע��
***************************************************************************************/
uint32_t CheckCanWriteNum(FIFO *myFIFO);

/***************************************************************************************
��  ����uint32 CheckCanReadNum(void)
��������
����ֵ�������ܱ�������FIFO���ݳ���
��  ע��
***************************************************************************************/
uint32_t CheckCanReadNum(FIFO *myFIFO);

#endif