#include <iostream>

using namespace std;

#include <mutex>
#include <atomic>

//C++ 11版本之后的跨平台实现
/**
class singleton {
private:
	singleton() {}

	static mutex lock_;
	static atomic<singleton *> p;
public:
	singleton *instance();
};

mutex singleton::lock_;
atomic<singleton *> singleton::p;

/*
* std::atomic_thread_fence(std::memory_order_acquire);
* std::atomic_thread_fence(std::memory_order_release);
* 这两句话可以保证他们之间的语句不会发生乱序执行。
*/
/**
singleton *singleton::instance() {
	singleton *tmp = p.load(memory_order_relaxed);
	atomic_thread_fence(memory_order_acquire);

	if (tmp == nullptr) {
		lock_guard<mutex> guard(lock_);
		tmp = p.load(memory_order_relaxed);

		if (tmp == nullptr) {
			tmp = new singleton();
			/**
			  按照指示order，建立非原子和宽松原子访问的内存同步排序，
			而无需关联的原子操作。例如，memory_order_release在线程A 
			的围栏之前发生的所有非原子和宽松的原子存储都将与线程B在memory_order_acquire
			围栅之后制作的相同位置的非原子和放宽的原子加载同步。
			*/
	/**
			atomic_thread_fence(memory_order_release);
			p.store(tmp, memory_order_relaxed);
		}
	}
	return p;
}*/