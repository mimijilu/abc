#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int n,m,d;
	char c[2];
	cin>>n>>m;
	int p=0;
	while(n--){
		scanf("%s%d",c,&d);
	//	cout<<c[0]<<endl;
		if(c[0]=='+') m+=d;
		else if(c[0]=='-' &&m<d) p++;
		else m-=d;

	}
			cout<<m<<' '<<p<<endl; 
	return 0;
}
