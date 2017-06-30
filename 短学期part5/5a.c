#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int gcd(int x,int y){
	int i,j;
	i = x;
	while (x %i !=0|| y%i != 0)
		i = i - 1;
	return i;
}
struct stu{
	int m,n;
};
int main(){
	int t,i,x,y,g,sgn;
	struct stu a[111];
	struct stu s={0,1};
	scanf("%d",&t);
	for(i=0;i<t;++i)
		scanf("%d/%d",&a[i].m,&a[i].n);
	for(i=0;i<t;++i){
		x= s.m * a[i].n + a[i].m * s.n;
		y=s.n*a[i].n;
		s.m=x;
		s.n=y;
	}
	sgn=0;
	if(s.m==0){
		printf("0\n");
		return 0;
	}
	else if(s.m>0&&s.n<0){
		s.n=-s.n;sgn=-1;
	}
	else if(s.m<0&&s.n>0){
		s.m=-s.m;sgn=-1;
	}
	else if(s.m<0&&s.n<0) 
		s.m=-s.m,
		s.n=-s.n;
	g=gcd(s.m,s.n);
	s.m/=g;s.n/=g;
	int zz=s.m/s.n;
	s.m%=s.n;
	if(sgn==-1) printf("-");
	if(zz) printf("%d",zz);

	if(s.m) {if(zz)printf(" ");}
	else {
	    printf("\n");
	    return 0;
    }
	if(s.n==1) printf("%d\n",s.m);
	else printf("%d/%d\n",s.m,s.n);
	return 0;
}