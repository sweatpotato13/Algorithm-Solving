#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1342
bool IsLucky(string s)
{
    for (int i = 0; i < s.size() - 1; i++){
        if (s[i] == s[i + 1]) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    sort(all(s));
    ll cnt = 0;
    do{
        if(IsLucky(s)) cnt++;
    }while(next_permutation(all(s)));
    cout << cnt;
    return 0;
}
