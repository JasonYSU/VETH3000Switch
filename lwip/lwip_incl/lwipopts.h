/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Simon Goldschmidt
 *
 */
#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

/* Prevent having to link sys_arch.c (we don't test the API layers in unit tests) */
#define NO_SYS                          1
#define LWIP_NETCONN                    0
#define LWIP_SOCKET                     0

#define LWIP_SNMP                       1    //打开snmp的支持
#define SO_REUSE                        1    //支持连接的再利用，不需要每次都要创建连接

#define HTTPD_TCP_PRIO                   5

#define SERIAL_SERVER_ONE_PRIO			1
#define SERIAL_SERVER_TWO_PRIO			2
#define SERIAL_SERVER_THREE_PRIO		3
#define SERIAL_SERVER_FOUR_PRIO			4

#define LWIP_CHECKSUM_ON_COPY           0

#define MEMP_NUM_UDP_PCB                50

#define LWIP_HTTPD_DYNAMIC_HEADERS      1

#define TCP_QUEUE_OOSEQ   				0

#define MEM_SIZE                        4 * 1024 * 1024
/* TCP Maximum segment size. */
#define TCP_MSS                1476

#define MEMP_NUM_TCP_PCB                100
#define MEMP_NUM_TCP_PCB_LISTEN         20

/* TCP sender buffer space (bytes). */
#define TCP_SND_BUF             1024 * TCP_MSS
#define MEMP_NUM_TCP_SEG         4 * 1024
/* TCP sender buffer space (pbufs). This must be at least = 2 *
   TCP_SND_BUF/TCP_MSS for things to work. */
//#define TCP_SND_QUEUELEN        2 * TCP_SND_BUF/TCP_MSS

#define LWIP_HTTPD_MAX_TAG_INSERT_LEN  10 * 1024
#define LWIP_HTTPD_MAX_TAG_NAME_LEN    20

/* TCP receive window. */
#define TCP_WND                16 * 1024

#define LWIP_RAND()    rand()
/* Minimal changes to opt.h required for tcp unit tests: */

//#define TCP_SND_QUEUELEN                40
//#define MEMP_NUM_TCP_SEG                TCP_SND_QUEUELEN
//#define TCP_SND_BUF                     (12 * TCP_MSS)
//#define TCP_WND                         (10 * TCP_MSS)

/* Minimal changes to opt.h required for etharp unit tests: */
#define ETHARP_SUPPORT_STATIC_ENTRIES   1

#define ETHARP_TRUST_IP_MAC             1

#endif /* __LWIPOPTS_H__ */