#include <iostream>
#include <Windows.h>

using namespace std;

int testdouble(void){
	double value=12.3456789;

	//默认情况下,cout输出6位有效数字
	cout <<value<<endl;

	//可以修改输出精度
	cout.precision(4); //修改cout的输出精度为4
	cout <<value<<endl;

	//想要这个精度,表示小数点后面的位数
	cout.flags(cout.fixed); //定点法:精度,用来表示小数点后面的位数
	cout <<value<<endl;

	cout<<3.1415926<<endl;

	cout.unsetf(cout.fixed);//取消定点法
	cout<<3.1415926<<endl;
	system("pause");
	return 0;
}