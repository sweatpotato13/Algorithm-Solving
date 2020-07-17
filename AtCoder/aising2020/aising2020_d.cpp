#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/aising2020/tasks/aising2020_d
ll powmod(ll a, ll n, ll mod) {
  ll ret = 1;
  while (n > 0) {
    if (n % 2 == 1) { ret = ret * a % mod; }
    a = a * a % mod;
    n /= 2;
  }
  return ret;
}
 
ll calc(ll num, ll depth)
{
  if (num == 0LL) return depth;
 
  ll p_count = __builtin_popcount(num);
  return calc(ll(num % p_count), depth + 1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    string x;
    cin >> n >> x;

    ll bitCount = 0;
    for(int i = 0;i<n;i++){
        if(x[i] == '1')
            bitCount++;
    }
    ll rem_p1 = 0;
    ll rem_m1 = 0;
    for(int i = 1;i<=n;i++){
        if(x[n-i] == '1'){
            rem_p1 += powmod(2,i-1,bitCount+1);
            rem_p1 %= (bitCount+1);
            if(bitCount > 1){
                rem_m1 += powmod(2,i-1,bitCount-1);
                rem_m1 %= (bitCount-1);
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (x[i] == '1'){
            if (bitCount == 1){
                cout << 0 << endl;
                continue;
            }
            ll rem = rem_m1 - powmod(2, n - i - 1, bitCount - 1);
            rem = (rem + (bitCount - 1)) % (bitCount - 1);
            cout << calc(rem, 1) << endl;
        }
        else if (x[i] == '0'){
            if (bitCount == 0){
                cout << 1 << endl;
            }
            else{
                ll rem = rem_p1 + powmod(2, n - i - 1, bitCount + 1);
                rem = rem % (bitCount + 1);
                cout << calc(rem, 1) << endl;
            }
        }
    }

    return 0;
}
