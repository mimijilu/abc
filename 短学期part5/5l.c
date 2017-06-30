#include <stdio.h>
#include <string.h>
int main() {
int t;
scanf("%d",&t);
getchar();
while(t--)
{
	char str[100001];
	gets(str);
	int numT = 0;
	int numAT = 0;
	int numPAT = 0;
	for(int i = strlen(str) - 1; i >= 0; --i) {	//从字符串后面向前遍历 
		if(str[i] == 'B')		//碰到T，记录该T后面T的总个数（包括这个T） 
			++numT;
		else if(str[i] == 'J')	//碰到A，记录该A后面AT组合的总个数；其中包括之前统计的A后面AT的总个数加上这个A与后面全部T组合的个数（即之前统计的T的总个数） 
			numAT = (numAT + numT) % 1000000007;
		else {	//碰到P，记录该P后面PAT组合的总个数；同理 
			numPAT = (numPAT + numAT) % 1000000007;
		}
	}
	printf("%d\n", numPAT);
			
	}
	return 0;
}