#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
ll che[10001] ={0,};
void getChe(ll num) {
    for (int i = 2; i <= num; i++) {
        che[i] = i;
    }
    for (int i = 2; i <= num; i++) { 
        if (che[i] == 0) 
            continue;
        for (int j = i + i; j <= num; j += i) {
            che[j] = 0;
        }
    }
}
int solution(vector<int> nums) {
    int answer = 0;
    vector<ll> v(nums.size());
    for(int i = 0;i<3;i++){
        v[i] = 1;
    }
    getChe(10000);
    sort(all(v));
    do{
        ll temp = 0;
		for(int i=0; i<v.size(); i++){
            if(v[i] == 1){
				temp += nums[i];
			}
		}
        if(che[temp]) answer++;
	}while(next_permutation(v.begin(), v.end()));
    return answer;
}