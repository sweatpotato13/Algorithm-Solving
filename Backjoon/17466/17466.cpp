#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// https://www.acmicpc.net/problem/17466
ll solve(ll n, ll p){
    ll res = 1;
    for(int i = 2;i<=n;i++){
        res = (res * i) % p;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, p;
    cin >> n >> p;

    cout << solve(n, p);

    return 0;
}