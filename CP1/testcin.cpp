#include <iostream>
#include <Windows.h>

using namespace std;

int testcin(void){
	int a;
	int b;
	int c;
	cout<<"请输入三个整数:"<<endl;
	cin>>a>>b>>c;
	cout << "a="<<a<<endl;
	cout<< "b="<<b<<endl;
	cout<< "c="<<c<<endl;
	 

	while(cin.fail()){
	cout << "输入失败,应该输入三个整数"<< endl;
	cin.clear();//清除cin的错误标志
	cin.sync();//清除缓冲区


	cin>>a>>b>>c;
	cout << "a="<<a<<endl;
	cout<< "b="<<b<<endl;
	cout<< "c="<<c<<endl;

	}



	system("pause");
	return 0;
}