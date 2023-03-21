#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1517
ll ans = 0;
vector<ll> v;
vector<ll> v2;
void merge(ll s, ll e){
    ll m = (s+e)/2;
    ll i = s;
    ll j = m+1;
    ll cnt = 0;
    ll idx = s;
    while(i<= m || j <= e){
		if(i > m){
			v2[idx++] = v[j++]; cnt++;
		}else if(j > e){
			v2[idx++] = v[i++]; ans += cnt;
		}else if(v[i] <= v[j]){
			v2[idx++] = v[i++]; ans += cnt;
		}else{
			v2[idx++] = v[j++]; cnt++;
		}
    }
	for(i=s; i<=e; i++){
        v[i] = v2[i];
    }
}
void mergeSort(ll s, ll e){
    ll m;
    if(s < e){
        m = (s + e) / 2;
        mergeSort(s, m);
        mergeSort(m + 1, e);
        merge(s, e);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    v.resize(n);
    v2.resize(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    mergeSort(0,n-1);
    cout << ans;


	return 0;
}
