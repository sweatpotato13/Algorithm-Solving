#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/1644
ll che[4000001] ={0,};
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

    ll val = 0;
    ll l=0, r=0, res = 0;
    ll n;
    cin >> n;
    getChe(n);
    getPrime(n);
    while(r <= prime.size() && prime.size() != 0){
        if(val < n){
            val += prime[r];
            r++;
            continue;
        }
        else if(val == n) res++;
        val -= prime[l];
        l++;
    }
    cout << res;
    return 0;
}