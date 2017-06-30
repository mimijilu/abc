#include<stdio.h>
typedef long long ll;
int main()
{
	ll a,b,that;
	while(~scanf("%lld%lld",&a,&b)){
		ll ans=0;
		for(ll i=1;i<=a;i++){
			//ans=0;
			if(i%5==0){
				ans+=b/5;
			}else{
				that=i%5;
				ans+=(b+that)/5;
			}
			//printf("%lld:%lld\n",a,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}