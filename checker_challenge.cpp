#include <iostream>
#include <cstring>
using namespace std;
const int N=30;
int n,ans,opt[N];
bool column[N],diag1[N],diag2[N];

void dfs(int k) { // putting the k-th queen on k-th row
    if (k>n) {
        for (int i=1;i<=n;++i)   cout << opt[i];
        cout << endl;ans ++;
        return;
    }
    for (int i=1;i<=n;++i) {
        if (column[i] || diag2[i+k-1] || diag1[n+i-k])    continue; // i-th column is occupied
        column[i]=true;diag2[i+k-1]=true;diag1[n+i-k]=true;
        opt[k]=i;  // put the k-th queen 
        dfs(k+1);
        column[i]=false;diag2[i+k-1]=false;diag1[n+i-k]=false;
    }
}

int main() {
    cin >> n;
    memset(column,0,sizeof(column));
    dfs(1);
    cout << ans << endl;
    return 0;
}