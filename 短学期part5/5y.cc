#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
struct stu{
	int num,iq,yz,lv;//num:准考证号 iq:智商 yz:颜值 lv:等级
};
bool comp(stu x ,stu y){
	if(x.lv<y.lv)
		return 1;//先比等级
	else if(x.lv==y.lv)
	{
		if(x.iq+x.yz>y.iq+y.yz)
			return 1;//学生的排名按智商和颜值的总分排序
		else if(x.iq+x.yz==y.iq+y.yz){//如果同一类学生总分相同
			if(x.iq>y.iq)//就根据智商从大到小排序
				return 1;
			else if(x.iq==y.iq){//如果智商也相同
				if(x.num<y.num)//就按照准考证号从小到大排序。
					return 1;
			}
		}
	}
	return 0;
}
	struct stu x[1000086];
int main(){
	int i,n,l,h;

	scanf("%d%d%d" ,&n,&l,&h);
	for(i=0;i<n;i++){
		scanf("%d%d%d" ,&x[i].num,&x[i].iq,&x[i].yz);
		if(x[i].iq>=l&&x[i].yz>=l){//只有智商和颜值都不小于L才能被录取
			if(x[i].iq>=h&&x[i].yz>=h)
				x[i].lv=1;//当智商和颜值都不小于H为一类学生
			else if(x[i].iq>=h&&x[i].yz<h)
				x[i].lv=2;//智商不小于H但是颜值小于H的为二类学生
			else if(x[i].iq<h&&x[i].yz<h&&x[i].iq>=x[i].yz)
				x[i].lv=3;//智商和颜值都小于H但是智商不小于颜值的的为第三类
			else x[i].lv=4;
		}
		else x[i].lv=5;	//五级学生不被录取
	}
	sort(x ,x+n ,comp);//排序
	int adm=0;//计算录取人数
	for(i=0;i<n;i++){
		if(x[i].lv<5) adm++;
	}
	cout<<adm<<endl;//第一行输出录取的考生数M
	for(i=0;i<adm;i++){//按顺序打印录取学生信息
		printf("%d %d %d\n" ,x[i].num ,x[i].iq ,x[i].yz);
	}
	return 0;
}