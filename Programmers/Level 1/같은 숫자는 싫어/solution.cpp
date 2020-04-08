#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    answer.resize(arr.size());
    copy(arr.begin(), arr.end(), answer.begin());


    return answer;
}