#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/11658
class Seg2D{
public:
  ll n;
  vector<vector<ll>> a;
  Seg2D(ll n) : n(n), a(2*n,vector<ll>(2*n)){}

  void init(vector<vector<ll>>& val){
    for(ll i = 0; i < n; i++){
      for(ll j = 0; j < n; j++)
        a[i+n][j+n] = val[i][j];
    }

    for(ll i = n; i < 2*n; i++){
      for(ll j = n-1; j > 0; j--) a[i][j] = a[i][j<<1]+a[i][j<<1|1];
    }

    for(ll i = n-1; i > 0; i--){
      for(ll j = 1; j < 2*n; j++){
        a[i][j] = a[i<<1][j] + a[i<<1|1][j];
      }
    }
  }

  void update(ll x, ll y, ll val) {
    a[x+n][y+n] = val;

    for(ll i = y+n; i > 1; i >>= 1)  a[x+n][i>>1] = a[x+n][i] + a[x+n][i^1];

    for(x = x+n; x > 1; x >>= 1){
      for(ll i = y+n; i >= 1; i >>= 1){
        a[x>>1][i] = a[x][i]+a[x^1][i];        
      }
    }
  }
  ll query1D(ll x, ll y1, ll y2){
    ll ret = 0;
    for(y1 += n, y2 += n+1; y1 < y2; y1 >>= 1, y2 >>= 1){
      if(y1 & 1) ret += a[x][y1++];
      if(y2 & 1) ret += a[x][--y2];
    }    
    return ret;
  }

  ll query(ll x1, ll y1, ll x2, ll y2) {
    ll ret = 0;
    for(x1 += n, x2 += n+1; x1 < x2; x1 >>= 1, x2 >>= 1){
      if(x1&1) ret += query1D(x1++, y1, y2);
      if(x2&1) ret += query1D(--x2, y1, y2);
    }
    return ret;
  }  
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    Seg2D tree(n);
    vector<vector<ll>> v(n,vector<ll>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> v[i][j];
        }
    }
    tree.init(v);
    for(int i = 0;i<m;i++){
        ll w,x,y,c,x1,y1,x2,y2;
        cin >> w;
        if(w == 0){
            cin >> x >> y >> c;
            tree.update(x-1,y-1,c);
        }
        else{
            cin >> x1 >> y1 >> x2 >> y2;
            cout << tree.query(x1-1,y1-1,x2-1,y2-1) << "\n";
        }
    }




	return 0;
}
