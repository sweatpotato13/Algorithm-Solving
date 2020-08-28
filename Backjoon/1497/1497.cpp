#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1497
ll ans = 0;
ll songCnt = 0;
ll n, m;
map<ll,ll> ma;
ll cntBit(ll n){
    ll val = 0;
    while(n){
        if(n%2==1) val++;
        n/=2;
    }
    return val;
}
void backtrack(ll idx, ll cnt, ll val){
    ll bits = cntBit(val);
    if(bits > songCnt){
        songCnt = bits;
        ans = cnt;
    }
    else if(bits == songCnt){
        ans = min(ans, cnt);
    }
    if(idx == n) return;
    backtrack(idx+1,cnt+1,val|ma[idx]);
    backtrack(idx+1,cnt,val);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0;i<n;i++){
        string s,info;
        cin >> s >> info;
        ll temp = 0;
        for(int j = 0;j<m;j++){
            if(info[j] == 'Y'){
                temp |= (1LL << ((m-1)-j));
            }
        }
        ma[i] = temp;
    }
    backtrack(0,0,0);
    if(songCnt == 0) ans = -1;
    cout << ans;
    return 0;
}


