#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)

int solution(vector<int> money) {
    int answer = 0;
    vll dp(money.size());
    vll dp2(money.size());
    dp[0] = money[0];
    dp[1] = money[0];
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i=2;i<money.size()-1;i++){
        dp[i]=max(dp[i-2]+money[i],dp[i-1]);
    }
    for(int i=2;i<money.size();i++){
        dp2[i]=max(dp2[i-2]+money[i],dp2[i-1]);
    }
    answer = max(dp[money.size()-2], dp2[money.size()-1]);
    return answer;
}
