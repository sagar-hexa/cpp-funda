#include <iostream>
#include <thread>

using namespace std;
//This function will be called from a thread

void call_from_thread() {
    std::cout << "Hello, World" << std::endl;
}

void fun(int x)
{
	cout << x << endl;
}


int main() {


	std::thread t(fun, 10);
    //Launch a thread
    std::thread t1(call_from_thread);

	t.join();
    //Join the thread with the main thread
    t1.join();

	getchar();
    return 0;
}