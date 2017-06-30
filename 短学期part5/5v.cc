#include <iostream>

using namespace std;

int main()
{
    long t,a,b,x,r,k,i;cin>>t;
    while(t--){
    cin>>a>>b>>k;
    x=a+b;i=1;r=0;
        while(x!=0){
        r+=i*(x%k);
        i*=10;
        x/=k;
        }
    cout<<r<<endl;
    }
    return 0;
}