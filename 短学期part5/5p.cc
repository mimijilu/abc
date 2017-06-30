#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;
typedef long long ll;

const int maxn = 1e4+7;
int arr[maxn],mtx[10007][107];

bool cmp(int x,int y)
{
    return x > y;
}

int main()
{
    int t,N,n,m,i=0;
    scanf("%d",&t);
    while(t--)
    {
        i = 0;
        scanf("%d",&N);
        n = sqrt(N*1.0);
        while(N%n) n--;
        m = N/n;
        for(int i=0;i<N;i++) scanf("%d",&arr[i]);
        sort(arr,arr+N,cmp);
        arr[N] = 0;
        for(int cot=0;i<N;cot++)
        {
            for(int j=cot;j<n-cot && i<N;j++)
                mtx[cot][j] = arr[i++];
            for(int j=cot+1;j<m-cot && i<N;j++)
                mtx[j][n-1-cot] = arr[i++];
            for(int j=n-2-cot;j>=cot && i<N;j--)
                mtx[m-1-cot][j] = arr[i++];
            for(int j=m-2-cot;j>cot && i<N;j--)
                mtx[j][cot] = arr[i++];
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                j == n-1 ? printf("%d\n",mtx[i][j]) : printf("%d ",mtx[i][j]);
        printf("\n");
    }
}