#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc172/tasks/abc172_f
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll a,b,c;
    cin >> a >> b;
    ll N = a+b;
    c = 0;
    for(int i = 3;i<=n;i++){
        ll x;
        cin >> x;
        c^= x;
    }
	if(c>N){
        cout << -1;
        return 0;
    }
	if((N-c)%2){
        cout << -1;
        return 0;
    }
	ll W=(N-c)/2,A=W;
	if(W>a){
        cout << -1;
        return 0;
    }
	if(W&c){
        cout << -1;
        return 0;
    }
	for(int i=56;i>=0;i--)
		if((1ll<<i)&c)
			if(A+(1ll<<i)<=a)A+=(1ll<<i);
	if(A==0){
        cout << -1;
        return 0;
    }
	cout<<a-A; 


	return 0;
}