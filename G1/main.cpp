#include <graphics.h>
#include <Windows.h>
/*
int main(void){
	//初始化图像界面640*480
	initgraph(640,480);

	//构建需要的图形 -画一个圆,在(320,240)位置画一个圆,半径200像素
	circle(340,240,200);

	system("pause");

	//关闭图形界面

	closegraph();

}
*/
/*
int main(void){
	initgraph(640,480);

	setbkcolor(RGB(64,128,128));
	cleardevice();

	//设置画笔的颜色
	setlinecolor(RGB(255,0,0));
	//设置画笔的样式,PS_SOLID表示实线,10表现线的宽度
	setlinestyle(PS_SOLID,10);
	circle(320,240,200);
	 
	//设置字体的颜色
	settextcolor(RGB(255,255,0));
	//设置字体
	settextstyle(100, //字体的高度
		0, //字体的宽度,为0,表示不指定宽度
		"微软雅黑"); //字体名称
	// 在坐标(170,190)的位置打印指定文本
	outtextxy(170,190,"无码高清");

	//画笔,从坐标位置(180,380)到坐标(460,100)画一条线
	line(180,380,460,100);




	system("pause");
	closegraph();
	return 0;
}
*/

int main(void){
	initgraph(600,340);
	
	//加载图片
	loadimage(0,"bg.jpg");

	//画一个空心矩形,左上角坐标(300,40),右下角坐标(550,80)
	rectangle(300,40,550,80);
	//设置文本字体颜色
	settextcolor(YELLOW);
	//设置文本字体样式
	settextstyle(30, //字体高度
		0, //不指定高度
		"微软雅黑");
	outtextxy(310,45,"1-网站404攻击");

	rectangle(300,100,550,140);
	outtextxy(310,105,"2-网站篡改攻击");

	rectangle(300,160,550,200);
	outtextxy(310,165,"3-网站攻击修复");
	
	rectangle(300,220,550,260);
	outtextxy(310,225,"4-查看攻击记录");

	rectangle(300,280,550,320);
	outtextxy(310,285,"5-退出");




	system("pause");
	closegraph();
	return 0;

}