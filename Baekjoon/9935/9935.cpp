#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/9935
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<char> stk;
	string s,b;
    cin >> s >> b;
    for(int i = 0;i<s.length();i++){
        stk.push(s[i]);
        if(s[i] == b[b.length()-1]){
            stack<char> bmb;
            for(int j = 0;j<b.length();j++){
                if(!stk.empty() && stk.top() == b[b.length()-1-j]){
                    bmb.push(stk.top());
                    stk.pop();
                }
            }
            if(bmb.size() != b.length()){
                while(!bmb.empty()){
                    stk.push(bmb.top());
                    bmb.pop();
                }
            }
        }
    }
    ll len = stk.size();
    string ans = "";
    for(int i = 0;i<len;i++){
        ans += stk.top();
        stk.pop();
    }
    reverse(all(ans));
    if(!ans.compare("")) ans = "FRULA";
    cout << ans << "\n";
    return 0;
}
