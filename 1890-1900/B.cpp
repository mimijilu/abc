#include<stdio.h>
#include<stdlib.h>
int comp(const void *p,const void *q)
{
	return *(int *)p-*(int *)q;
}
int main()
{
	int t,n,m,i,a[110],sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;++i)
		{
			scanf("%d",&a[i]);
		}		 
		qsort(a,m,sizeof(int),comp);
		sum = 0;
		for(i=0;i<m;++i)
		{
			sum += a[i];
			if(sum > n)
				break;
		}
		printf("%d\n",i);
	}
	return 0;
}
