#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/11689
ll pi(ll n){
    // Eluer pi function
    // pi(n) = n과 서로소인 1-n까지 정수의 갯수
    // pi(n) = nPI(1-1/p) (p|n)
    double ans = n;
    for(ll i = 2;i*i<=n;i++){
        if(n%i == 0){
            while(n%i == 0) n/=i;
            ans *= (1.0-(1.0/i));
        }
    }
    if(n>1)
        ans *= (1.0-(1.0/n));
    return (ll)ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    cout << pi(n) << "\n";

    return 0;
}