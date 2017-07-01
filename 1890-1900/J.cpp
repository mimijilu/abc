#include<bits/stdc++.h>
using namespace std;
char ed[105][105];
int vis[105][105];
int c = 0 ,n,m;
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool judge(int x,int y){
	if(x<0||x>n+1||y<0||y>m+1||vis[x][y]!=0)return false;
	else return true;
}
void dfs(int x,int y){
	vis[x][y]=c;
	int fx,fy;
	for(int i=0;i<4;++i){
		fx=x+to[i][0],fy=y+to[i][1];
		if(judge(fx,fy)){
			dfs(fx,fy);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n+2;++i){
		ed[i][0]='.';
		ed[i][n+1]='.';
	}
	for(int i=0;i<m+2;++i){
		ed[n+1][i]='.';
		ed[0][i]='.';
	}
	for(int i=1;i<=n;++i){
		getchar();
		for(int j=1;j<=m;++j){
			scanf("%c",&ed[i][j]);
			if(ed[i][j]=='*')vis[i][j]=-1;
		}
	}
	for(int i=0;i<=n+1;++i){
		for(int j=0;j<=m+1;++j){
			if(vis[i][j]==0){
				c++;
				dfs(i,j);
			}
		}
	}
	printf("%d\n",c-1);
}
