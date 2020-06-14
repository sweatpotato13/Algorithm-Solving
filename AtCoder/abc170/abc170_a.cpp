#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc170/tasks/abc170_a
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll x[5] = {0,};
    for(int i = 0 ;i<5;i++){
        cin >> x[i];
        if(x[i] == 0)
            ans = i+1;
    }
    cout << ans;

	return 0;
}