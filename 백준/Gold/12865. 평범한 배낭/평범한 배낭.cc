#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <unordered_set>
#include <random>
#include <type_traits>
#include <utility>

using namespace std;
using namespace std::chrono;

typedef long long _INT64;
typedef unsigned long long _UINT64;

namespace UTIL{
    template<typename T>
    bool RangeCheck(T& val, T min, T max){
        if constexpr (std::is_same_v<T, string>){
            int nMin = stoi(min);
            int nMax = stoi(max);
            int nlength = val.length();
            if( (nlength<nMin)||(nlength>nMax)){
                return false;
            }
        }
        else{
            if( (val<min)||(val>max)){
                return false;
            }
        }
        return true;
    }

    bool IsAlpha(const std::string& str){
        for (char ch : str) {
            if (!std::isalpha(static_cast<unsigned char>(ch))) {
                return false;
            }
        }
        return true;
    }  

    template<typename T>
    bool Input(T& val, T min, T max){
        cin>>val;
        return RangeCheck(val, min, max);
    }
    std::chrono::high_resolution_clock::time_point g_startTime, g_endTime;

    void StartTimer(){
        g_startTime = high_resolution_clock::now();
    }
    void EndTimer(){
        g_endTime = high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<milliseconds>(g_endTime-g_startTime);
        cout<< "Elapsed: "<< time_span.count()<<"ms"<<endl;
    }
}

class CQuest{
public:
    bool InputData(){
        if(!UTIL::Input(m_count, 0, 1'00)){
            return false;
        }
        
        if(!UTIL::Input(m_weight, 0, 100'000)){
            return false;
        }
        for(int i{}; i<m_count; ++i){
            //무게, 가치 맵을 생성한다. 
            int weight, value;
            if(!UTIL::Input(weight, 0, 100'000)){
                return false;
            }

            if(!UTIL::Input(value, 0, 1'000)){
                return false;
            }
            // 동일 무게에 다른 가치를 가지는 제품은 없나?
            // 문제 조건에서 빠져 있음. 
            auto data = pair<int, int>(weight, value);
            m_data.push_back(data);            
        }
        return true;
    }
    void Process(){
        m_count++;
        m_weight++;
        int dp[m_count][m_weight];

        int idx=0;
        for(int i{0}; i< m_count; i++){
            auto data = m_data[idx];
            for(int j{0}; j< m_weight; j++){
                if( i==0){
                    dp[i][j]=0;
                    continue;
                }
                if(data.first > j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], data.second+dp[i-1][j-data.first]);
                }
            }
            if(i!=0)
                idx++;
        }
        m_ret = dp[m_count-1][m_weight-1];
    }
    void Print(){
        cout<<m_ret<<'\n';
    }
private:
    int m_count;  // 총 물건의 수
    int m_weight; // 버틸수 있는 무게
    vector<pair<int, int>> m_data;
    int m_ret=0;
};

int main()
{
    //UTIL::StartTimer();
    ios::sync_with_stdio(false);
    cin.tie(0);

    CQuest quest;
    if (!quest.InputData()){
        return -1;
    } 
    quest.Process(); 
    quest.Print();
    //UTIL::EndTimer();
    
    return 0;
}