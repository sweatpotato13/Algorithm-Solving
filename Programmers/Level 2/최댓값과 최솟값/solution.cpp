#include <string>
#include <vector>
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
string solution(string s) {
    string ans = "";
    string token = " ";
    vector<ll> v;
    for(stringstream sts(s);sts>>token;){
        v.push_back(stoi(token));
    }
    sort(all(v));
    ll ax = v[v.size()-1];
    ll in = v[0];
    ans = to_string(in) + " " + to_string(ax);
    return ans;
}