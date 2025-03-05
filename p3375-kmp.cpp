#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

constexpr int MAXN = 1000005;
char str[MAXN], pat[MAXN]; // match pat in str
int kmp[MAXN],j=0;

int main() {
    memset(str,0,sizeof str);memset(pat,0,sizeof pat);memset(kmp,0,sizeof kmp);
    scanf("%s%s",str+1,pat+1);
    int l_str = strlen(str+1);
    int l_pat = strlen(pat+1);
    for (int i=2;i<=l_pat;++i) {
        while (j && pat[i] != pat[j+1]) j = kmp[j];
        if (pat[i] == pat[j+1])         j++;
        kmp[i] = j;
    }
    j = 0;
    for (int i=1;i<=l_str;++i) {
        while (j && str[i] != pat[j+1]) j = kmp[j];
        if (str[i] == pat[j+1])         j++;
        if (j == l_pat) {
            cout << i - l_pat + 1 << endl;
            j = kmp[j];
        }
    }
    for (int i=1;i<=l_pat;++i)
        printf("%d ",kmp[i]);
    return 0;
}