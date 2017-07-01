#include <stdio.h>

int main()
{
	int a, b, c, d, e, v, v1, v2, v3;
	while(scanf("%d%d%d%d%d", &a, &b, &c, &d, &e)!=EOF)
	{
		if(d<e)
			v = a*b*c-2*(a-2*e)*(b-2*e)*d-2*(a-2*e)*(c-2*e)*d-2*(c-2*e)*(b-2*e)*d;
		else if(d>=e)
		{
			if(d==e)
			{
				v1 = a*b*c-2*(a-2*e)*(b-2*e)*d-2*(a-2*e)*(c-2*e)*d-2*(c-2*e)*(b-2*e)*d;
				v2 = (a-2*e)*(b-2*e)*(c-2*e);
				v3 = v1 - v2;
				if(v2>v3)
					v = v2;
				else
					v = v3;
			}
			else
			{
				v1 = (a-2*d)*(b-2*d)*(c-2*d);
				v2 = 4*(e*e*(a-2*e)+e*e*(b-2*e)+e*e*(c-2*e))+8*e*e*e;
				if(v2>v1)
					v = v2;
				else
					v = v1;
			}
		}
		printf("%d\n", v);
	}
}
