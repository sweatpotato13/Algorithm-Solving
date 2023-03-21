#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
// https://www.acmicpc.net/problem/18891
#define DEBUG 0
struct elect{
    string name;    // 당명
    bool isVaild;   //의석할당정당 여부
    int votes;  // 득표수
    int ri; // 지역구 의원수
    int si; // 연동형 비례의원수
    int ti; // 병립형 비례의원수
    int total; // 총 의원수 = ri + si + ti
    double pi; // 비례 득표율
};
elect arr[60];
vector<pair<int,string>> ans;
bool cmp(const pair<int,string> &p1, const pair<int,string> &p2){
    if(p1.first > p2.first){
        return true;
    }
    else if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    else{
        return false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p,v;
    cin >> p >> v;
    ans.resize(p);
    int noPartyMember = 253; //무소속 지역구 의원수
    int noVaildVotes = v; // 무효표 수
    int vaildVote = 0; // 의석할당정당의 총 득표수
    int R = 0; // 의석할당정당이 아닌 정당의 지역구 당선인수 + 무소속수;
    for(int i = 0;i<p;i++){
        cin >> arr[i].name >> arr[i].ri >> arr[i].votes;
        arr[i].si = 0;
        arr[i].ti = 0;
        noPartyMember -= arr[i].ri;
        noVaildVotes -= arr[i].votes;
        //double rate = round(10000.0 * arr[i].votes / v) / 10000;
		double rate = 1.0 * arr[i].votes / v;
        if(arr[i].ri >= 5 || rate >= 0.03){
            arr[i].isVaild = true;
            vaildVote += arr[i].votes;
        }
        else{
            arr[i].isVaild = false;
        }
    }
    R = noPartyMember;
    // 의석할당정당 제외한 비례득표율 계산
    for(int i = 0;i<p;i++){
        if(arr[i].isVaild){
            //arr[i].pi = round(10000.0 * arr[i].votes / vaildVote)/10000;
			arr[i].pi = 1.0 * arr[i].votes / vaildVote;
        }
        else{
            R += arr[i].ri;
        }
    }
#if DEBUG
    cout << "비례득표율===================================\n";
    for(int i = 0;i<p;i++){
        if(arr[i].isVaild){
            cout << arr[i].name << " " << arr[i].pi << "\n";
        }
    }
#endif

    int propSum = 0;    // 연동배분의석수 합
    //Step 1 : 30석에 대해 전국단위 준연동 방식으로 각 정당별 연동배분의석수 산정
    for(int i = 0;i<p;i++){
        if(arr[i].isVaild){
            double s = (double)((300 - R)*arr[i].pi - arr[i].ri)/ 2;
            if(s < 0) arr[i].si = 0;
            else arr[i].si = round(s);
            propSum += arr[i].si;
        }
    }   

#if DEBUG
    cout << "연동배분의석===================================\n";
    for(int i = 0;i<p;i++){
        if(arr[i].isVaild){
            cout << arr[i].name << " " << arr[i].si << "\n";
        }
    }
#endif
    int rePropSum = 0;  // 비례대표 의석 재 분배후 총 의석
    vector<double> leftProp(p, -1.0);   // 소수점 나머지 저장용
    //Step 2-1 각 정당별 연동배분의석수의 합계 < 30석일 경우 
    //              ☞ 잔여의석에 대해 기존 의석배분방식(병립형) 적용 배분
    if(propSum < 30){
        int leftPropSum = 30 - propSum;
        for(int i = 0;i<p;i++){
            if(arr[i].isVaild){
                double d = (1.0 * leftPropSum * arr[i].pi);
                int s = floor(d);
                leftProp[i] = d - s;
                arr[i].si += s;
                rePropSum += s;
            }
        }
        while(rePropSum != leftPropSum){
            double best = -1;
            int idx = 0;
            for(int i = 0;i<p;i++){
                if(best < leftProp[i]){
                    best = leftProp[i];
                    idx = i;
                }
            }
            leftProp[idx] = -1;
            arr[idx].si++;
            rePropSum++;
        }
    }

    //Step 2-2 각 정당별 연동배분의석수의 합계 > 30석 
    //              ☞ 각 정당별 연동배분의석수비율대로 배분 
    else if(propSum > 30){
        for(int i = 0;i<p;i++){
            if(arr[i].isVaild){
                double d = (1.0 * 30 * arr[i].si / propSum);
                int s = floor(d);
                leftProp[i] = d - s;
                arr[i].si = s;
                rePropSum += s;
            }
        }
        while(rePropSum != 30){
            double best = -1;
            int idx = 0;
            for(int i = 0;i<p;i++){
                if(best < leftProp[i]){
                    best = leftProp[i];
                    idx = i;
                }
            }
            leftProp[idx] = -1;
            arr[idx].si++;
            rePropSum++;
        }
    }

#if DEBUG
    cout << "재배분==================================\n";
    for(int i = 0;i<p;i++){
        if(arr[i].isVaild){
            cout << arr[i].name << " " << arr[i].si << "\n";
        }
    }
#endif

    //Step 3 : 17석에 대해 기존 의석배분방식(병립형) 적용 배분
    leftProp.clear();
    rePropSum = 0;
    for(int i = 0;i<p;i++){
        if(arr[i].isVaild){
            double d = (1.0 * 17 * arr[i].pi);
            int s = floor(d);
            leftProp[i] = d - s;
            arr[i].ti = s;
            rePropSum += s;
        }
    }
    while(rePropSum != 17){
        double best = -1;
        int idx = 0;
        for(int i = 0;i<p;i++){
            if(best < leftProp[i]){
                best = leftProp[i];
                idx = i;
            }
        }
        leftProp[idx] = -1;
        arr[idx].ti++;
        rePropSum++;
    }
#if DEBUG
    cout << "병립형==================================\n";
    for(int i = 0;i<p;i++){
        if(arr[i].isVaild){
            cout << arr[i].name << " " << arr[i].ti << "\n";
        }
    }

    cout << "결과=================================\n";
#endif
    for(int i = 0;i<p;i++){
        arr[i].total = arr[i].ri + arr[i].si + arr[i].ti;
        ans[i].second = arr[i].name;
        ans[i].first = arr[i].total;
    }

    sort(all(ans),cmp);
    for(int i = 0;i<p;i++){
        cout << ans[i].second << " " << ans[i].first << "\n";
    }
    return 0;
}
