#include <iostream>
#include<cstdlib>
using namespace std;
int n;double x[10086];
int isr(int key){
    int i;
    for(i=0;i<key;++i)
        if(x[i]>=x[key]) return 0;
    for(i=key+1;i<n;++i)
        if(x[i]<=x[key]) return 0;
    return 1;
}
int comp(const void*a,const void*b){
return *(double*)a-*(double*)b;}
int main()
{   int i,t;cin>>t;while(t--){

cin>>n;
for(i=0;i<n;++i){
    cin>>x[i];
}
int ok=0;double p[10086];
for(i=0;i<n;++i){
    if(isr(i)){
        p[ok++]=x[i];
    }
}
cout<<ok<<endl;
qsort(p,ok,sizeof(double),comp);
if(ok)cout<<p[0];
for(i=1;i<ok;++i){
    cout<<' '<<p[i];
}
cout<<endl;
}
    return 0;
}