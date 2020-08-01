#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(), (x).end()

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(auto k : arr){
        if(k % divisor == 0){
            answer.push_back(k);
        }
    }
    if(answer.size() == 0)
        answer.push_back(-1);
    sort(all(answer));
    return answer;
}
