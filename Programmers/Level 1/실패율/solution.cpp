#include <string>
#include <vector>
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
bool cmp(pair<double,int> a, pair<double,int> b){
    if(a.first > b.first)
        return true;
    else if(a.first < b.first){
        return false;
    }
    else{
        if(a.second < b.second)
            return true;
        else
            return false;
    }
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int len = stages.size();
    map<int,int> m;
    for(int i = 0;i<len;i++){
        m[stages[i]]++;
    }
    vector<pair<double,int>> v;
    int rest = len;
    for(int i = 1;i<=N;i++){
        double rate = (double)m[i]/rest;
        v.push_back({rate,i});
        rest -= m[i];
    }
    sort(all(v),cmp);
    for(int i = 0;i<N;i++){
        answer.push_back(v[i].second);
    }
    return answer;
}