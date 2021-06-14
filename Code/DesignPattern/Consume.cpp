#include "Consume.h"
#include <iostream>
#include <thread>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // _WIN32

BlockingQueue<int> g_queue;


// �������߳�
void Produce()
{
	for (int i = 0; i < 10; ++i)
	{
		g_queue.push(i);
		std::cout << "Produce��" << i << std::endl;
	}
}

// �������߳�
void Consume()
{
	int data;
	while (true)
	{
		PopResult res = g_queue.pop(data);
		if (res == POP_STOP) // �߳�Ӧ��ֹͣ
			break;
		if (res == POP_UNEXPECTED) // ���⻽��
			continue;

		// ��������
		std::cout << "Consume��" << data << std::endl;
	}
}

int testConsume()
{
	// �����������̺߳��������̣߳�Ҳ������������̣߳�
	std::thread produceThread(Produce);
	std::thread consumerThread(Consume);

	// �ȴ����ݴ�����
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
#ifdef _WIN32
	Sleep(1000);
#else
	usleep(1000 * 1000);
#endif // _WIN32

	produceThread.join();
	// ֹͣ�߳�
	g_queue.Stop();
	consumerThread.join();

	return 0;
}
