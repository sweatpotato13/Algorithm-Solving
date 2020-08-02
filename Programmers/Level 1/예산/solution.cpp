#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(all(d));
    for(auto k : d){
        if(budget >= k){
            budget -= k;
            answer++;
        }
    }
    return answer;
}
