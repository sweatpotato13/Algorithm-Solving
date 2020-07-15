#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/aising2020/tasks/aising2020_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll dp[100000]={0,};
    for(int x = 1;x<=100;x++){
        for(int y = 1;y<=100;y++){
            for(int z = 1;z<=100;z++){
                dp[x*x+y*y+z*z+x*y+y*z+z*x]++;
            }   
        }   
    }
    for(int i = 1;i<=n;i++){
        cout << dp[i] << "\n";
    }

	return 0;
}
