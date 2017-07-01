#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dx8[] = { -1, 0, 1, 0 , -1 , -1 , 1 , 1 };
const int dy8[] = { 0, 1, 0, -1 , -1 , 1 , -1 , 1 };

#ifdef _MSC_VER
#define gets gets_s
#endif // _MSC_VER
int solve();

#define InRange(x, y)  ((x) < 0 || (x) >= H || (y) < 0 || (y) >= W)

int main()
{
    return solve();
}

int solve()
{
    int H, W;
    scanf("%d %d", &H, &W);
    short dp[3001] = {};
    char S[3001];
    short m = 0;
    for(int i = 0; i < H; ++i)
    {
        scanf("%s", S);
        short prevx = 0, prevt = 0;
        for(int j = 0; j < W; ++j)
        {
            short x = 0;
            short t = dp[j];
            if (S[j] == '#')
            {
                x = min(min(t, prevt), prevx) + 1;
                m = max(x, m);
            }
            dp[j] = prevx = x;
            prevt = t;
        }
    }
    printf("%d\n", (m + 1) / 2);
    return 0;
}
