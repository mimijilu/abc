import math
T=int(input())
for t in range(T):
	n,k=map(int,raw_input().split())
	l=input()
	s=0;
	for i in range(0,k+1):
		if(i==k): s+= l*(n-1.0)
		else:
			s+= l*(n-0.5)
		l=math.sin(math.pi*(n-2.0)/(2*n))*l
	print s