#include <string>
#include <vector>
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;

long long solution(long long n) {
    long long answer = 0;
    vector<ll> v;
    while(n){
        ll temp = n%10;
        v.push_back(temp);
        n /= 10;
    }
    sort(all(v),greater<ll>());
    for(auto k : v){
        answer = answer * 10 + k;
    }
    return answer;
}
