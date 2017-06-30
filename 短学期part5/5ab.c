#include<stdio.h>
int dr(int n);
int main(){
	int t;scanf("%d",&t);
	int n,x,s;
	while(t--){
		scanf("%d",&n);s=0;
		while(n--){
			scanf("%d",&x);
			s+=x;
		}
		s=dr(s);
		printf("%d\n",s);
	}
}
int dr(int n){
	int s=0;
	while(n>=10){
		while(n){
			s=s+n%10;
			n=n/10;
		}
		n=s;s=0;
	}
	return n;
}