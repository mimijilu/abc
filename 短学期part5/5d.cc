#include<iostream>
#include<cstdio>
using namespace std;

    int main(int argc,char **argv)
    {
	int t;cin>>t;
	int n;double l,s;
	char dw[5];
	while(t--){
	cin>>n;	
	s=0;
		while(n--){
		scanf("%lf%s",&l,dw);
		if(dw[0]=='k') s=s+l*1000;
		else if(dw[0]=='m'&&dw[1]=='\0') s=s+l*1;
		else if(dw[0]=='d') s=s+l*0.1;
		else if(dw[0]=='c') s=s+l*0.01;
		else if(dw[0]=='m'&&dw[1]=='m') s=s+l*0.001;
		
		}
		printf("%.3fm\n",s);
	}

}