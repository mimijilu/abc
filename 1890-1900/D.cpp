#include <stdio.h>
#include <stdlib.h>
struct py
{
	char name[25];
	int a1,a2,a3;
};
int main ()
{  
	struct py pya[101];
	int i,n,t,a,b,c,s;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d %s",&t,pya[i].name);
		pya[i].a1 = pya[i].a2 = pya[i].a3 = 0;
		while(t--)
		{
			scanf("%d-%d-%d",&a,&b,&c);
			if(a==b&&b==c&&c==a)
				pya[i].a1++;
			else if(a/10>a%10&&a%10>b/10&&b/10>b%10&&b%10>c/10&&c/10>c%10)
				pya[i].a2++;
			else
				pya[i].a3++;
		}
	}
	///////////////////////////////////
	a = pya[0].a1,b = pya[0].a2,c = pya[0].a3;
	for(i=1;i<n;++i)
	{
		if(a<pya[i].a1)
			a = pya[i].a1;
		if(b<pya[i].a2)
			b = pya[i].a2;
		if(c<pya[i].a3)
			c = pya[i].a3;
	}
	///////////////////////////////////
	printf("If you want to have a keyboard, you should call:");
	 		
		s = 0;
		for(i=0;i<n;i++)
		{			
			if(pya[i].a1 == a)
			{
				if(s==0)
				{
					printf(" %s",pya[i].name);
					s = 1;
				}
				else
					printf(", %s",pya[i].name);
			}
		}
	 
	printf(".\n");
	/////////////////////////////////
	printf("If you want to order a Watchdog2, you should call:");
	 	
		s = 0;
		for(i=0;i<n;i++)
		{			
			if(pya[i].a2 == b)
			{
				if(s==0)
				{
					printf(" %s",pya[i].name);
					s = 1;
				}
				else
					printf(", %s",pya[i].name);
			}
		}
	 
	printf(".\n");
	/////////////////////////////////
	printf("If you want to have a cup of coffee with a girl, you should call:");
	 		
		s = 0;
		for(i=0;i<n;i++)
		{			
			if(pya[i].a3 == c)
			{
				if(s==0)
				{
					printf(" %s",pya[i].name);
					s = 1;
				}
				else
					printf(", %s",pya[i].name);
			}
		}
	 
	printf(".\n");
	/////////////////////////////////
	
}
