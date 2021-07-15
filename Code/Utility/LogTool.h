#pragma once
#include "TimeTool.h"

extern int g_lu_debugs_level;

// https://blog.csdn.net/q343509740/article/details/79726708
/*
	All:��͵ȼ��ģ����ڴ�������־��¼.

	Trace:��׷�٣����ǳ����ƽ�һ��.

	Debug:ָ��ϸ������Ϣ�¼��Ե���Ӧ�ó����Ƿǳ��а�����.

	Info:��Ϣ�ڴ����ȼ�����ͻ��ǿ��Ӧ�ó�������й���.

	Warn:������漰warn���¼������־.

	Error:���������Ϣ��־.

	Fatal:���ÿ�����صĴ����¼����ᵼ��Ӧ�ó�����˳�����־.

	OFF:��ߵȼ��ģ����ڹر�������־��¼.
*/
enum LogLevel
{
	debug_log = 0x01,
	info_log = 0x02,
	error_log = 0x04
};

#define log_print(level, ...)	\
  do                                      \
  {                                       \
    if (g_lu_debugs_level & level##_log)  \
    {                                     \
      printf("%s", getTime());            \
      printf(__VA_ARGS__);                 \
    }                                     \
  } while (0)
