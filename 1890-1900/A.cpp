#include <stdio.h>
int main ()
{
	int n,m,t;
	scanf("%d%d",&n,&m);
	while(n--)
	{
		scanf("%d",&t);
		m = m +t;
	}
	printf("%d\n",m);
}
