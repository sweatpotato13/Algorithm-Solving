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
// https://atcoder.jp/contests/abc177/tasks/abc177_a
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ans[2] ={"No", "Yes"};
    ll d,t,s;
    cin >> d >> t >> s;
    bool isAnswer = false;
    if(t*s >= d) isAnswer = true;
    cout << ans[isAnswer];

    return 0;
}


