main()
{
	int a,b,c,e;
	scanf("%d%d%d",&a,&b,&c);
	e=a*a+b*b*b+c-(b-a)*(b-a);
	printf("%d",e*e*e);
}