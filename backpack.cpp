#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=200;

int num, vol;
int n[MAXN],v[MAXN];
int dp[MAXN][MAXN]; // dp[i][j] means the solution to putting the first i stuffs in the backpack of volume j

int main() {
    ios::sync_with_stdio;cin.tie(0);cout.tie(0);
    memset(n,0,sizeof(n));memset(v,0,sizeof(v));memset(dp,0,sizeof(dp));
    cin >> num >> vol;
    for (int i=0;i<num;++i) cin >> n[i];
    for (int i=0;i<num;++i) cin >> v[i];

    for (int i=1;i<=num;++i) {
        for (int j=1;j<=vol;++j) {
            if (v[i]>j)   dp[i][j]=dp[i-1][j];
            else    dp[i][j]=max(dp[i-1][j-v[i]]+n[i],dp[i-1][j]);
        }
    }
    cout << dp[num][vol] << endl;
    return 0;
}