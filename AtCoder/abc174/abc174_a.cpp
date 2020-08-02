#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc174/tasks/abc174_a
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    cin >> x;
    bool isAnswer = false;
    if(x >= 30)
        isAnswer = true;
    if(isAnswer)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
