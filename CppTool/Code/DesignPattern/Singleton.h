#pragma once
#include <mutex>

/// @brief �̰߳�ȫ������ģʽ
class Singleton
{
public:
	static Singleton* getInstance();
	static void releaseInstance();

private:
	Singleton() = default;
	Singleton(const Singleton&) = delete;
	Singleton(const Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(const Singleton&&) = delete;

	static Singleton* s_pSingleton;
	static std::mutex s_mutex;
};
