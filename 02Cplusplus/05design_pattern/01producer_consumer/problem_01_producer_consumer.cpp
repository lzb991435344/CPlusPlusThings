

#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <condition_variable>
//#include <unistd.h>
//#include <windows.h>

using namespace std;

const int MAX_NUM = 10000;

class BoundedBuffer
{
public:
	BoundedBuffer(size_t n) {
		array_.resize(n);
		start_pos_ = 0;
		end_pos_ = 0;
		pos_ = 0;
	}
	void Produce(int n) {
		{
			std::unique_lock<std::mutex> lock(mtx_);
			//wait for not full
			not_full_.wait(lock, [=] { return pos_ < array_.size(); });

			//usleep(1000 * 400);
			//Sleep(1000 * 400);
			array_[end_pos_] = n;
			end_pos_ = (end_pos_ + 1) % array_.size();
			++pos_;
			cout << "Produce pos:" << pos_ << endl;
		} //auto unlock

		not_empty_.notify_one();
	}

	int Consume() {
		std::unique_lock<std::mutex> lock(mtx_);
		//wait for not empty
		not_empty_.wait(lock, [=] { return pos_ > 0; });
		//usleep(1000 * 400);
		//Sleep(1000 * 400);
		int n = array_[start_pos_];
		start_pos_ = (start_pos_ + 1) % array_.size();
		--pos_;
		cout << "Consume pos:" << pos_ << endl;
		lock.unlock();

		not_full_.notify_one();

		return n;
	}
private:
	std::vector<int> array_;
	size_t start_pos_;
	size_t end_pos_;
	size_t pos_;
	std::mutex mtx_;
	std::condition_variable not_full_;
	std::condition_variable not_empty_;
};

BoundedBuffer bb(10);
std::mutex g_mtx;

void Producer()
{
	int n = 0;
	while (n < 100) {
		bb.Produce(n);
		cout << "Producer:" << n << endl;
		n++;
	}

	bb.Produce(-1);
}


void Consumer()
{
	std::thread::id thread_id = std::this_thread::get_id();
	int n = 0;
	do {
		n = bb.Consume();
		cout << "Consumer thread:" << thread_id << "=====> " << n << endl;
	} while (-1 != n);

	bb.Produce(-1);
}

/*
int main()
{
	//使用vector存thread
	std::vector<std::thread> t;
	t.push_back(std::thread(&Producer));
	t.push_back(std::thread(&Consumer));
	t.push_back(std::thread(&Consumer));
	t.push_back(std::thread(&Consumer));

	for (auto& one : t) {
		one.join();
	}

	return 0;
*/
/**
Produce pos:1
Consume pos:0
Producer:Consumer thread:17044=====> 0
Produce pos:01

Producer:1
Consume pos:0
Consumer thread:Produce pos:1
17044=====> 1
Consume pos:0
Producer:2Consumer thread:4460=====> 2

Produce pos:1
Consume pos:0
Producer:3
Consumer thread:4460=====> 3
Produce pos:1
Consume pos:0Producer:
4Consumer thread:4460
=====> 4
Produce pos:1
Producer:5
Consume pos:0
Consumer thread:4460=====> 5
Produce pos:1
Producer:6
Consume pos:0
Consumer thread:4460Produce pos:1
=====> 6
Consume pos:0
Producer:7
Consumer thread:4460=====> 7
Produce pos:1
Consume pos:0
Consumer thread:17044=====> 8
Producer:8
Produce pos:1
Producer:9
Consume pos:0
Consumer thread:Produce pos:17044=====> 9
1
Producer:10
Consume pos:0
Consumer thread:Produce pos:1
Producer:11
17044=====> 10
Consume pos:0
Produce pos:1
Consumer thread:Producer:12
Consume pos:7084=====> 11
0
Consumer thread:4460=====> 12
Produce pos:1
Producer:13
Consume pos:0
Consumer thread:7084=====> 13
Produce pos:1
Producer:14
Consume pos:0
Consumer thread:7084=====> 14
Produce pos:1
Producer:15
Consume pos:0
Produce pos:1
Consumer thread:7084=====> 15Consume pos:0
Producer:16
Produce pos:1
Consumer thread:4460=====> 16
Producer:17
Consume pos:0

Consumer thread:17044Produce pos:1
Producer:=====> 17
Consume pos:18
0
Consumer thread:Produce pos:1
Producer:7084=====> 18
19Consume pos:0

Consumer thread:4460=====> Produce pos:1
Producer:19
20
Consume pos:0
Produce pos:Consumer thread:170441=====>
20
Producer:21Consume pos:0

Consumer thread:7084Produce pos:1
=====> 21Producer:22
Consume pos:0
Consumer thread:4460Produce pos:
=====> 221

Producer:23Consume pos:0
Consumer thread:7084=====>
Produce pos:1
Producer:24Consume pos:0
Consumer thread:4460=====> 2423


Produce pos:1
Producer:25
Consume pos:0
Consumer thread:4460=====> 25
Produce pos:1
Producer:26Consume pos:0

Consumer thread:4460=====> 26
Produce pos:1
Producer:Consume pos:0
27
Consumer thread:Produce pos:1
Producer:4460Consume pos:0
28
Consumer thread:=====> 27
Produce pos:1
7084Producer:Consume pos:=====> 290
Consumer thread:28
4460=====> 29
Produce pos:1

Producer:30
Consume pos:0
Consumer thread:4460=====> 30
Produce pos:1
Producer:31Consume pos:0

Consumer thread:Produce pos:1
4460=====> 31
Consume pos:0
Producer:32Consumer thread:17044=====> 32

Produce pos:1
Producer:33
Consume pos:0
Consumer thread:7084=====> 33Produce pos:1

Consume pos:0
Producer:34
Consumer thread:4460=====> Produce pos:134

Producer:35
Consume pos:0
Produce pos:1
Producer:Consumer thread:4460Consume pos:0
Consumer thread:7084=====> 36
36=====> 35

Produce pos:1
Producer:Consume pos:0
Consumer thread:37
Produce pos:117044=====> 37

Consume pos:0
Consumer thread:Producer:38
Produce pos:117044=====> 38

Consume pos:0Producer:39

Produce pos:1
Consumer thread:17044Producer:40
=====> Consume pos:039

Consumer thread:4460Produce pos:1=====> 40

Producer:Consume pos:041

Consumer thread:4460Produce pos:1
=====> 41
Consume pos:0
Consumer thread:Producer:4217044
=====> 42Produce pos:
1
Producer:43
Consume pos:0
Consumer thread:17044=====> 43
Produce pos:1
Producer:44
Consume pos:0
Produce pos:1
Consumer thread:17044=====> 44
Producer:Consume pos:0
Consumer thread:7084=====> 4545
Produce pos:1

Producer:46
Consume pos:0
Consumer thread:4460Produce pos:1=====> 46

Producer:47
Consume pos:0
Consumer thread:Produce pos:1
Producer:48
Consume pos:04460
=====> 47
Produce pos:1
Producer:49
Consumer thread:7084=====> 48
Consume pos:0
Consumer thread:Produce pos:1
Producer:50Consume pos:0
17044=====>
Produce pos:49Consumer thread:
70841
Producer:=====> 50
Consume pos:51
0
Consumer thread:Produce pos:1
Producer:52Consume pos:0
17044=====>
Consumer thread:51
4460Produce pos:1
Producer:53
=====> 52
Consume pos:0
Produce pos:1
Consumer thread:7084=====> 53
Producer:54Consume pos:0

Produce pos:Consumer thread:17044=====> 541

Producer:55
Consume pos:0
Consumer thread:4460=====> 55
Produce pos:1
Producer:Consume pos:056

Produce pos:1
Consumer thread:4460=====> Consume pos:Producer:570

56
Produce pos:1
Consumer thread:17044=====> 57
Producer:58
Consume pos:0
Consumer thread:4460=====> 58
Produce pos:1
Producer:59
Consume pos:0
Consumer thread:4460=====> 59
Produce pos:1
Producer:60
Consume pos:0
Consumer thread:4460=====> 60Produce pos:1

Producer:61
Consume pos:0
Consumer thread:7084=====> 61
Produce pos:1
Producer:62
Consume pos:0
Consumer thread:Produce pos:14460
=====> Producer:63
Consume pos:0
62
Produce pos:1
Consumer thread:7084Producer:64
Consume pos:0=====> 63

Consumer thread:Produce pos:14460=====> 64

Producer:65Consume pos:0

Consumer thread:7084=====> 65
Produce pos:1
Producer:66Consume pos:0

Produce pos:Consumer thread:7084=====> 661

Producer:67Consume pos:0

Consumer thread:7084Produce pos:1
=====> 67
Consume pos:0
Producer:68
Consumer thread:4460=====> 68
Produce pos:1
Consume pos:0
Producer:69
Consumer thread:4460=====> 69Produce pos:1

Consume pos:0
Consumer thread:7084=====> 70
Producer:70
Produce pos:1
Producer:71Consume pos:0
Consumer thread:17044
=====> 71
Produce pos:1
Producer:Consume pos:072

Produce pos:1Consumer thread:17044=====> 72

Producer:73Consume pos:0

Consumer thread:17044=====> 73
Produce pos:1
Producer:74Consume pos:0

Consumer thread:17044=====> 74Produce pos:1

Consume pos:0
Producer:75Consumer thread:7084=====> 75

Produce pos:1
Producer:76
Consume pos:0
Consumer thread:4460Produce pos:1
Producer:=====> 76
77Consume pos:0
Consumer thread:
Produce pos:117044=====> 77

Consume pos:0
Producer:78Consumer thread:4460=====> 78

Produce pos:1
Producer:79Consume pos:0

Produce pos:Consumer thread:70841
Producer:=====> Consume pos:79
800

Consumer thread:Produce pos:117044
=====> 80
Producer:81
Consume pos:0
Consumer thread:Produce pos:1
4460=====> 81
Producer:82
Consume pos:0
Produce pos:1Consumer thread:7084=====> 82

Producer:83Consume pos:0

Consumer thread:4460=====> 83
Produce pos:1
Producer:84Consume pos:0

Consumer thread:7084=====> 84
Produce pos:1
Producer:85
Consume pos:0
Consumer thread:7084=====> 85
Produce pos:1
Producer:86
Consume pos:0
Consumer thread:7084=====> 86
Produce pos:1
Producer:87
Consume pos:0
Consumer thread:7084=====> 87Produce pos:1

Consume pos:Producer:88
0
Consumer thread:4460=====> 88Produce pos:1

Consume pos:0
Consumer thread:17044=====> 89Producer:89

Produce pos:1
Producer:90Consume pos:
0
Consumer thread:17044Produce pos:1
=====> 90Consume pos:0
Producer:91
Produce pos:1

Consumer thread:4460=====> 91
Consume pos:0
Producer:92
Consumer thread:7084=====> 92Produce pos:1

Producer:93
Consume pos:0
Consumer thread:17044=====> 93
Produce pos:1
Producer:94
Consume pos:0
Consumer thread:17044=====> 94
Produce pos:1
Producer:95
Consume pos:0
Consumer thread:17044=====> 95
Produce pos:1
Consume pos:0
Producer:96Consumer thread:4460=====>
Produce pos:96
1
Producer:97Consume pos:0

Consumer thread:4460=====> 97Produce pos:1

Consume pos:0
Producer:98Consumer thread:17044
=====> 98
Produce pos:1
Producer:Consume pos:0
99
Consumer thread:7084=====> 99Produce pos:1

Consume pos:0
Consumer thread:4460=====> -1
Produce pos:1
Consume pos:0
Consumer thread:17044=====> -1
Produce pos:1
Consume pos:0
Consumer thread:7084=====> -1
Produce pos:1
*/