#include <iostream>
#include <functional>
using namespace std;

typedef std::function<int(int)> CallbackFunction;
class Caller
{
	private:
		CallbackFunction m_cb;
	public:
		void connectCallBack(CallbackFunction cb)
		{
			m_cb = cb;
		}		
		void test()
		{
			cout << "test call back" << endl;
			int i = m_cb(10);
			cout << "return value from call back" << i << endl;
		}
};


class Callee
{
	private:
		int m_i;
	public:
		Callee(int a)
		{	
			m_i = a;
		}
		int callbackFun(int i)
		{
			cout  << "call back function called by caller" << endl;
			return m_i*i;
		}
		
			

};
int main()
{
	Caller caller;
	Callee callee(5);
	// lamda fucntion generaly used for local function call and exicute you work(like print).
	// so no need to write function in class and just implement lamda fuction which execute when call form one of the function of class and its scope terminate in that function once it used.
	// so when compile class than unncessary function (for small use) not required to compile every time , better you implement lamda fuctoin which is used in perticuler call in fucntion only.
	// advantage is no required to write function in class.avoid compiler load , easy to use.
	caller.connectCallBack([&callee](int i) { return callee.callbackFun(i); });  // lamda function
	caller.test();
	getchar();
	return 0;
}
