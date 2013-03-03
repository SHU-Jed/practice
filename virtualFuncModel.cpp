/*虚函数的内存模型test
	reference:http://blog.csdn.net/haoel/article/details/1948051
	date:2013/3/3
*/
#include <iostream>
using namespace std;

class Base{
public:
	virtual void f(){cout<<"Base::f"<<endl;}
	virtual void g(){cout<<"Base::g"<<endl;}
	virtual void h(){cout<<"Base::h"<<endl;}

};

typedef void (*Fun)();

int main(){

	Base b;
	cout<<"虚函数表的地址"<<(int *)&b<<endl;
	cout<<"虚函数表中第一个函数的地址"<<(int *)(*( (int*) &b))<<endl;
  
	Fun pFirstFun =(Fun)*(int *)(*( (int*) &b));
	
	pFirstFun();

	return 0;
}