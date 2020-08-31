#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/3908
ll dp[1121][15] = {0,};
ll che[2222] ={0,};
vector<ll> prime;
void getChe(ll num) {
    for (int i = 2; i <= num; i++) {
        che[i] = i;
    }
    for (int i = 2; i <= num; i++) { 
        if (che[i] == 0) 
            continue;
        for (int j = i + i; j <= num; j += i) {
            che[j] = 0;
        }
    }
}
void getPrime(ll num){
    for(int i = 2;i<=num;i++){
        if(che[i])
            prime.push_back(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getChe(2000);
    getPrime(2000);
    dp[0][0] = 1;
    for(int i = 0;i<prime.size();i++){
        for(int j=1120;j>=prime[i];j--){
            for(int k = 1;k<=14;k++){
                dp[j][k] += dp[j-prime[i]][k-1];
            }
        }
    }
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        cout << dp[n][k] << "\n";
    }


    return 0;
}
