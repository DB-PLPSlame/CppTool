#pragma once
#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

namespace std
{
#define  MIN_THREAD_NUM 1
#define  MAX_THREAD_NUM 16

	//�̳߳�,�����ύ��κ�����lambda���ʽ����������ִ��,���Ի�ȡִ�з���ֵ
	//��֧�����Ա����, ֧���ྲ̬��Ա������ȫ�ֺ���,Opteron()������
	class ThreadPool
	{
		using Task = std::function<void()>;
		// �̳߳�
		std::vector<std::thread> _pool;
		// �������
		std::queue<Task> _tasks;
		// ͬ��
		std::mutex _lock;
		// ��������
		std::condition_variable _cv;
		// �Ƿ�ر��ύ
		std::atomic<bool> _run{ true };
		//�����߳�����
		std::atomic<int> _idlThrNum{ 0 };

	public:
		ThreadPool(unsigned char size = 4)
		{
			_idlThrNum = size < MIN_THREAD_NUM ? MIN_THREAD_NUM : size;
			_idlThrNum = size > MAX_THREAD_NUM ? MAX_THREAD_NUM : size;

			for (size = 0; size < _idlThrNum; ++size)
			{
				_pool.emplace_back(
					[this]
				{ // �����̺߳���
					while (_run)
					{
						Task task;
						{   // ��ȡһ����ִ�е� task
							std::unique_lock<std::mutex> lock{ _lock };// unique_lock ��� lock_guard �ĺô��ǣ�������ʱ unlock() �� lock()
							_cv.wait(lock, [this] { return !_run.load() || !_tasks.empty(); }); // wait ֱ���� task
							if (!_run && _tasks.empty())
								return;
							task = std::move(_tasks.front()); // ȡһ�� task
							_tasks.pop();
						}
						_idlThrNum--;
						task();
						_idlThrNum++;
					}
				}
				);
			}
		}
		~ThreadPool()
		{
			_run.store(false);
			_cv.notify_all(); // ���������߳�ִ��
			for (auto& thread : _pool) {
				//thread.detach(); // ���̡߳���������
				if (thread.joinable())
					thread.join(); // �ȴ���������� ǰ�᣺�߳�һ����ִ����
			}
		}

	public:
		// �ύһ������
		// ����.get()��ȡ����ֵ��ȴ�����ִ����,��ȡ����ֵ
		// �����ַ�������ʵ�ֵ������Ա������
		// һ����ʹ�� bind�� .commit(std::bind(&Dog::sayHello, &dog));
		// һ����ʹ�� mem_fn�� .commit(std::mem_fn(&Dog::sayHello), &dog)
		template<class F, class... Args>
		auto commit(F&& f, Args&&... args) ->std::future<decltype(f(args...))>
		{
			if (!_run.load())
				throw std::runtime_error("commit on ThreadPool is stopped.");

			using FunctionType = decltype(f(args...)); // typename std::result_of<F(Args...)>::type, ���� f �ķ���ֵ����
			auto task = std::make_shared<std::packaged_task<FunctionType()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));    // wtf !
			std::future<FunctionType> retType = task->get_future();
			{
				std::lock_guard<std::mutex> lock{ _lock };//�Ե�ǰ���������  lock_guard �� mutex �� stack ��װ�࣬�����ʱ�� lock()��������ʱ�� unlock()
				_tasks.emplace([task]() {(*task)(); });
			}
			_cv.notify_one(); // ����һ���߳�ִ��
			return retType;
		}

		//�����߳�����
		int idlCount() { return _idlThrNum.load(); }
	};
}

#endif