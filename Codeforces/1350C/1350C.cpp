#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
using namespace std;
// http://codeforces.com/contest/1350/problem/C
ll pre[100001] ={0,};
ll suf[100001] ={0,};
ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll ans = 1;
    ll n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i = 1;i<=n;i++){
        cin >> v[i];
    }
    pre[1] = v[1];
    suf[n] = v[n];
    for(int i = 2;i<=n;i++){
        pre[i] = gcd(pre[i-1],v[i]);
    }
    for(int i = n-1;i>=1;i--){
        suf[i] = gcd(suf[i+1],v[i]);
    }
	for(int i=0;i<=n-1;i++)
	{
		if(i==0)
			ans=suf[2];
		else if(i==n-1)
			ans=ans*pre[n-1]/gcd(pre[n-1],ans);
		else
			ans=ans*gcd(pre[i],suf[i+2])/gcd(gcd(pre[i],suf[i+2]),ans);
	}
    cout << ans;

	return 0;
}