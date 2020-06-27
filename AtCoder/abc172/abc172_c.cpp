#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc172/tasks/abc172_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> A(n);
    vector<ll> B(m);
    vector<ll> sA(n+1);
    vector<ll> sB(m+1);
    for(int i = 0;i<n;i++){
        cin >> A[i];
        sA[i+1] = sA[i] + A[i];
    }
    for(int i = 0;i<m;i++){
        cin >> B[i];
        sB[i+1] = sB[i] + B[i];
    }
    ll ans = 0;
    ll j = m;
    for(int i = 0;i<n+1;i++){
        ll temp = sA[i];
        ll t = k - temp;
        if(t < 0) continue;
        while(temp + sB[j] > k)
            j--;
        ans = max(ans, i+j);
    }

    cout << ans;

	return 0;
}