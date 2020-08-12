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

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    ll size = clothes.size();
    map<string,ll> m;
    for(int i = 0;i<size;i++){
        m[clothes[i][1]]++;
    }
    for(auto k : m){
        answer *= (k.second+1);
    }
    answer -= 1;
    return answer;
}
