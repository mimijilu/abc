#include<stdio.h>
int main(){
	int m,n,i,j,t,a;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		j=n-7;
		if(j>7) printf("%d\n",j);
		else printf("-1\n");
	}
	return 0;
}
