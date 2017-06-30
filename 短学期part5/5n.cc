#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
string a,b;
char tmp[10];
int lmp;
priority_queue<string> q;

void dfs(int ia,int ib){

	if(ia==a.length() && ib==b.length()){
		
		tmp[lmp]='\0';
		string s(tmp);
		q.push(s);
		return;
	}
	if(ia<a.length()){
		tmp[lmp++]=a[ia];
		dfs(ia+1,ib);
		lmp--;
	}
	if(ib<b.length()){
		tmp[lmp++]=b[ib];
		dfs(ia,ib+1);
		lmp--;
	}
}
int main(){
	stack<string> st;

	int t;
	cin>>t;
	int ia,ib;
	while(t--){
		cin>>a>>b;
		lmp=0;
		dfs(0,0);
		string prev="!!";
		
		while(!q.empty()){
			if(prev!=q.top()){
				st.push(q.top());
				prev=q.top();
			}
			q.pop();
		}
		while(!st.empty()){
			cout<<st.top()<<endl;
			st.pop();
		}
		cout<<endl;
	}
}