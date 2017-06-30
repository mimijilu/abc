#include <iostream>
#include<cstdlib>
#include<cstring>
#include<cctype> 
using namespace std;

int main(void) {
	char a[10086];
	int i,ok;
	while(gets(a)!=0){
		ok=1;
		for(i=0;a[i]!='@'&&a[i]!='\0';++i){
			if(isalnum(a[i])||a[i]=='_'){;}
			else ok=0;
		}
		if(a[i]=='\0') ok=0;
		if(i<1||i>16) ok=0;
		//cout<<i<<endl;
		
		int j=0,k;
		for(k=i+1;a[k]!='/'&&a[k]!='\0';++k){
			if(isalnum(a[k])||a[k]=='_'){++j;}
			else if(a[k]=='.' &&(isalnum(a[k+1])||a[k+1]=='_') ) j=0;
			else ok=0;	
			if(j>16) ok=0;	
		}
		if(k-i-1<1||k-i-1>32) ok=0;
		//cout<<k-i-1<<endl;
		
		if(a[k]=='/'){
			int kk;
			for(kk=k+1;a[kk]!='\0';++kk){
				if(isalnum(a[kk])||a[i]=='_'){;}
				else ok=0;
			}
			if(kk-k-1<1||kk-k-1>16) ok=0;
			//cout<<kk-k-1<<endl;	
		}
		
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	} 
}