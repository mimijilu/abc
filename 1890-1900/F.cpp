#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
int comp(const void *p, const void *q)
{
	return *(char *)q - *(char *)p;
}
int main ()
{
	char a[110],b[110];
	int t,i,s;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(a);
		gets(b);
		s = 0;
		qsort(a,strlen(a),sizeof(char),comp);
		qsort(b,strlen(b),sizeof(char),comp);
		for(i=0;i<strlen(a);i++)
		{
				if(a[i]!=b[i])
				{
					s = 1;
					break;
				}
				if(a[i]==' ' && b[i] == ' ' || a[i]==' ' && b[i] == '\0' || a[i]=='\0' && b[i] == ' '  )
				{
					break;
				}
		}		
		if(s==0)
			printf("Yes\n");
		else
			printf("No\n");
	}	 
}
