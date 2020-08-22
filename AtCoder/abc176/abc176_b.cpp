#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://atcoder.jp/contests/abc176/tasks/abc176_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans[2] = {"No","Yes"};
    bool isAnswer = false;
    string s;
    cin >> s;
    ll temp = 0;
    for(auto k : s){
        temp += (k-'0');
    }
    if(temp % 9 == 0) isAnswer = true;
    cout << ans[isAnswer];


    return 0;
}

