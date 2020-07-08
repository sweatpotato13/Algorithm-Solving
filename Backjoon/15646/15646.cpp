#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/15646
vector<vector<ll>> ft(5001,vector<ll>(5001));
ll LSB(ll x){
    return x & (-x);
}
ll query(ll x, ll y){
    ll sum = 0;
    for(ll x_ = x; x_ > 0; x_ = x_ - LSB(x_)){
        for(ll y_ = y; y_ > 0; y_ = y_ - LSB(y_)){
            sum = sum + ft[x_][y_];
        }
    }
    return sum;
}
ll query(ll x1, ll y1, ll x2, ll y2){
    return (query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
}
void update(ll x, ll y, ll value){
    for(ll x_ = x; x_ < ft.size(); x_ = x_ + LSB(x_)){
        for(ll y_ = y; y_ < ft[0].size(); y_ = y_ + LSB(y_)){
            ft[x_][y_] += value;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,q;
    cin >> n >> m >> q;
    for(int i = 0;i<q;i++){ 
        ll c;
        cin >> c;
        if(c == 1){
            ll x1,y1,x2,y2,d;
            cin >> x1 >> y1 >> x2 >> y2 >> d;
            update(x1, y1, d); 
            update(x1, y2+1, -d); 
            update(x2+1, y1, -d); 
            update(x2+1, y2+1, d); 
        }
        else{
            ll x,y;
            cin >> x >> y;
            cout << query(x,y) << "\n";
        }
    }

	return 0;
}
