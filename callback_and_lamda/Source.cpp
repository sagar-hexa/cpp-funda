#include <iostream>

using namespace std;


typedef int(*callbackPtr)(void *,int);
class caller
{
  private:
	callbackPtr m_cb;
	void * m_p;
  public:
	void registerCallBack (callbackPtr  cb,void *ptr)
	{
		m_cb = cb;
		m_p = ptr;
	}
	void test()
	{
		cout << "call back to callee" << endl;
		cout << "return value by multily of 10 by value given by callee's constructor is : " << m_cb(m_p,10);
	}
		
};

class callee
{
  private:
	int a;
  public:
	callee(int i)
	{
		cout << "callee's constructor vaslue is : " << i << endl;
		a = i;
	}
	static int staticCallBack(void *p, int a)
	{
		cout << "call staticCall back function" << endl;
		((callee*)p)->callbackFunction(a);
	}		
	int callbackFunction(int i)
	{
		cout << "call from caller" << endl;
		return a*i;
	}

};


int main()
{
	caller a;
	callee b(10);

	a.registerCallBack(callee::staticCallBack,&b);
	a.test();
	
	getchar();
	return 0;
}
