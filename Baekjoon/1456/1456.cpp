#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1456
ll che[10000001] ={0,};
vector<ll> p;
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
    for(int i = 2;i<=num;i++){
        if(che[i] != 0)
            p.push_back(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    ll a,b;
    cin >> a >> b;
    getChe(10000000);
    for(ll i = 0;i<p.size();i++){
        ll prime = p[i];
        ll cur,next;
        cur = prime * prime;
        while(1){
            if(cur > b) break;
            if(cur >= a && cur <= b){
                ans++;
            }
            next = cur * prime;
            if(next % cur != 0) break;
            cur = next;
        }
    }
    cout << ans;

	return 0;
}