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

int solution(vector<int> citations) {
    int answer = 0;
    sort(all(citations));
    reverse(all(citations));
    for(int i = 1;i<=citations.size();i++){
        if(citations[i-1] >= i)
            answer = i;
    }
    return answer;
}
