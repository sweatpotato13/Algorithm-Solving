#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://www.acmicpc.net/problem/2491
ll n;
vll num;
ll two_pointer() {
    ll left = 0;
    ll right = 0;
    ll last_value = 0;
    ll ret = 0;

    while (true) {
        if (left == right) { 
            last_value = num[right];
            right++;
            ret = max(ret, right - left); 
        }
        else if (right == n) break; 
        else if (num[right] >= last_value) {
            last_value = num[right]; 
            right++;
            ret= max(ret, right - left);
        }
        else left++;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    num = vll(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    ll answer = two_pointer();
    reverse(num.begin(), num.end());
    answer = max(answer, two_pointer());
    cout << answer;
    return 0;
}