#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    string s;
    int used;
};

constexpr int MAXN = 22;
vector<Node> str(MAXN);
priority_queue<int> ans;
int n,res=0;
string st;

int compatible(string a, string b) { // if a and b are connected
    priority_queue<int> com_ans;
    if (a == b) {
        for (int i=1;i<min(a.length(),b.length())-1;++i) {
            string s1 = a.substr(a.length()-i);
            string s2 = b.substr(0,i);
            // cout << s1 << endl << s2 << endl;
            if (s1 == s2)    com_ans.push(-i);
        }
        if (com_ans.empty())    return 0;
        else {
            if (-com_ans.top() == a.length() || -com_ans.top() == b.length())    return 0;
            else    return -com_ans.top();
        }
    }
    for (int i=1;i<min(a.length(),b.length());++i) {
        string s1 = a.substr(a.length()-i);
        string s2 = b.substr(0,i);
        // cout << s1 << endl << s2 << endl;
        if (s1 == s2)    com_ans.push(-i);
    }
    if (com_ans.empty())    return 0;
    else {
        if (-com_ans.top() == a.length() || -com_ans.top() == b.length())    return 0;
        else    return -com_ans.top();
    }
}

void dfs(string current) {
    bool status = true;
    for (auto iter = str.begin(); iter != str.end(); ++ iter) {
        int m = compatible(current, iter->s);
        if (iter->used < 2 && m > 0) {
            res += iter->s.length()-m;
            iter->used += 1;
            status = false;
            // cout << "MATCHED " << current << " " << iter->s << endl;
            // cout << "PLUS " << iter->s.length()-m << endl;
            dfs(iter->s);
            iter->used -= 1;
            res -= iter->s.length()-m;
        }
    }
    if (status) ans.push(res);
}

int main() {
    cin >> n;
    for (int i=0;i<n;++i)   cin >> str[i].s;
    cin >> st;
    st = "1" + st;
    dfs(st);
    cout << ans.top() + 1 << endl;
    // string s1,s2;
    // cin >> s1 >> s2;
    // cout << compatible(s1,s2) << endl;
    return 0;
}