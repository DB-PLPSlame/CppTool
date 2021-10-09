#pragma once
#include <iostream> // std::cout, std::endl
#include <thread>   // std::thread
#include <string>   // std::string
#include <future>   // std::promise, std::future
#include <chrono>   // seconds

namespace cpp11 {
	using namespace std;
	using namespace std::chrono;

	// https://www.jianshu.com/p/7945428c220e
	void read(std::future<std::string> *future) {
		// future��һֱ������ֱ����ֵ����
		std::cout << future->get() << std::endl;
	}

	void test_promise() {
		// promise �൱��������
		std::promise<std::string> promise;
		// future �൱��������, ��ֵ����
		std::future<std::string> future = promise.get_future();
		// ��һ�߳���ͨ��future����ȡpromise��ֵ
		std::thread thread(read, &future);
		// ��read��һ���:)
		std::this_thread::sleep_for(seconds(1));
		
		promise.set_value("hello future");
		// �ȴ��߳�ִ�����
		thread.join();
	}

	/****************************************/
	// https://www.jianshu.com/p/72601d82f3df
	int sum(int a, int b) {
		return a + b;
	}

	void test_packaged_task() {
		std::packaged_task<int(int, int)> task(sum);
		std::future<int> future = task.get_future();

		// std::promiseһ����std::packaged_task֧��move������֧�ֿ���
		// std::thread�ĵ�һ��������ֹ�Ǻ�������������һ���ɵ��ö��󣬼�֧��operator()(Args...)����
		std::thread t(std::move(task), 1, 2);
		// �ȴ��첽������
		std::cout << "1 + 2 => " << future.get() << std::endl;

		t.join();
	}

	/****************************************/
	// https://www.jianshu.com/p/58dea28d1a95
	void test_async()
	{
		auto print = [](char c) {
			for (int i = 0; i < 10; i++) {
				std::cout << c;
				std::cout.flush();
				std::this_thread::sleep_for(milliseconds(1));
			}
		};
		// ��ͬlaunch���Ե�Ч��
		std::launch policies[] = { std::launch::async, std::launch::deferred };
		const char *names[] = { "async   ", "deferred" };
		for (int i = 0; i < sizeof(policies) / sizeof(policies[0]); i++) {
			std::cout << names[i] << ": ";
			std::cout.flush();
			auto f1 = std::async(policies[i], print, '+');
			auto f2 = std::async(policies[i], print, '-');
			f1.get();
			f2.get();
			std::cout << std::endl;
		}
	}
};
