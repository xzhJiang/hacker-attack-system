#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include "hacker.h"

 /*
 1.网站404攻击
 2.网站篡改攻击
 3.网站攻击记录
 4.DNS攻击
 5.服务器重启攻击
 */

using namespace std;
#define WIDTH	40
#define HEIGHT	15
#define MAXSIZE 4096

void inputPwd(char pwd[],int size){
	char c;
	int i=0;
	//请输入密码:123456
	//保存到字符数组pwd:'1','2','3','4','5','6'
	//加'\0',转化为字符串
	while(1){
		c=getch(); //不会回显
		
		//如果读到回车符,返回'\r'
		if(c=='\r'){
			pwd[i]=0; //'\0'
			break;
		}
		pwd[i++]=c;
		cout<<'*';
		
	}
	cout<<endl;
}




void login(void){
	string name;
	char pwd[32];
	while(1){
		system("cls");
		std::cout << "请输入账号:";
		std::cin >> name;  //让用户输入账号,保存在name
	
		std::cout << "请输入密码:";
		//std::cin >> pwd;  //让用户输入密码,保存在pwd  

		//实现密码输入
		inputPwd(pwd,sizeof(pwd));

		if(name=="54hk"&& !strcmp(pwd,"123456")){
			break;
		}else{
			std::cout<<"输入的账号或密码有误，请重新输入。"<<endl;
			system("pause");
		}
	}
}

void printInMiddle(string msg){
	int leftSpace=(WIDTH-msg.length())/2;
		for(int i=0;i<leftSpace;i++){
			cout<<" ";

		}
		cout<<msg<<endl;
	}



void menuShow(void){
	/*
	system("cls");
	std::cout <<"1.网站404攻击" << std::endl;
	std::cout << "2.网站篡改攻击" << std::endl;
	std::cout << "3.查看攻击记录" << std::endl;
	std::cout << "4.攻击修复" << std::endl;
	std::cout << "5.退出" << std::endl;
	*/
	string menu[]={
		"1.网站404攻击",
		"2.网站篡改攻击",
		"3.网站攻击修复",
		"4.查看攻击记录",
		"5.退出"
	};
	//计算菜单项最大长度
	int max =0;
	int menuCount=sizeof(menu)/sizeof(menu[0]);
	for(int i=0;i<menuCount;i++){
		if(menu[i].length()>max){
			max=menu[i].length();

		}

	}
	system("cls");
	//打印标题
	printInMiddle("---黑客攻击系统---");

	int leftSpace=(WIDTH-max)/2;
	for(int i=0;i<menuCount;i++){
		for(int i=0;i<leftSpace;i++){
			cout<<" ";

		}
		cout<<menu[i]<<endl;
	}

}

int menuChoise(void){
	int n=0;
	while(1){
	cin>>n;
	if(cin.fail()){
		cin.clear();
		cin.sync();
		cout<<"无效输入,请重新输入."<<endl;
		system("pause");

	}else{
		break;
	}
	}
	return n;
}
//网站404攻击
void attack404(void){
	char id[64];//网站id
	char response[MAXSIZE];//攻击后,从服务器返回结果
	system("cls");
	//cout<<"404攻击..."<<endl;
	//int hk_404(char *id, char *response) ;
	printInMiddle("---网站404攻击---");
	cout<<"请输入准备攻击的网站的ID:";
	scanf_s("%s",id,sizeof(id));

	cout<<"正在执行404攻击...\n";

	hk_404(id,response);
	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;
	system("pause");
}

//网页篡改攻击，para表示填充内容
//int hk_tamper(char *id, char *para, char *response);
void siteEdit(void){
	system("cls");
	char id[64];//网站id
	char response[MAXSIZE];//攻击后,从服务器返回结果
	string attackText;
	printInMiddle("---网站篡改攻击---");
	cout<<"请输入准备攻击的网站的ID:";
	scanf_s("%s",id,sizeof(id));

	cout<<"请输入你要写入的内容:";
	cin>>attackText;
	//把本地的gbk编码转换为UTF-8编码
	GBKToUTF8(attackText);
	cout<<"正在执行网站篡改攻击...\n";
	hk_tamper(id,(char *)attackText.c_str(),response);

	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;
	system("pause");
}

//查看攻击记录
void attackRecord(void){
	system("cls");
	char id[64];//网站id
	char response[MAXSIZE];//攻击后,从服务器返回结果
	
	printInMiddle("---查看攻击记录---");
	cout<<"请输入准备查看的网站的ID:";
	scanf_s("%s",id,sizeof(id));

	cout<<"正在查看攻击记录...\n";
	hk_record(id, response);
	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;
	system("pause");
}


//网站攻击修复
//int hk_restore(char *id, char *response);

void attackRepair(void){
	system("cls");
	char id[64];//网站id
	char response[MAXSIZE];//攻击后,从服务器返回结果
	
	printInMiddle("---网站攻击修复---");
	cout<<"请输入准备修复的网站的ID:";
	scanf_s("%s",id,sizeof(id));

	cout<<"正在修复网站...\n";
	hk_restore(id, response);
	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;
	system("pause");
}

void init(void){
	//设置终端窗口的大小
	char cmd[128];
	sprintf(cmd,"mode con cols=%d lines=%d",WIDTH,HEIGHT);//打印到字符串
	system(cmd);
}
int main(void){
	init();
	login();//实现登录功能
	while(1){
	menuShow();
	cout<<"请输入:";
	int n=menuChoise();
	
	switch(n){
	case 1:
		attack404();
		break;
	case 2:
		siteEdit();
		break;
	case 3:
		
		attackRepair();
		break;
	case 4:
		attackRecord();
		break;
	case 5:
		return 0;
	default:
		cout<<"无效输入,请重新输入."<<endl;
		system("pause");
		break;
	}

	}

	
	//system("pause");
	return 0;
}
