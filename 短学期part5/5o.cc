#include <iostream>

using namespace std;
int main(void) {
	int i=0,n;
	cin>>n;
	string a[n];
	for(int i=0;i<n;++i)
	cin>>a[i];
	cout<<a[n-1]<<endl;
	for(int i=n-2;i>=0;--i){
		int f=1;
		for(int j=i+1;j<=n-1;++j){
			if(a[i]==a[j]){
				f=0;
				break;
			}
		}
		if(f)
		cout<<a[i]<<endl;
	}
	return 0;
}