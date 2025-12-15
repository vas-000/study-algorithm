#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
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
        if(!UTIL::Input(m_value, 0, 1'000)){ // N
            return false;
        }
        m_dp.resize(m_value);
        return true;
    }

    int f(int n){
       // m_dp[n-1] // 마지막에 2*1이 추가 되는 경우 
       // m_dp[n-2] // 마지막에 2*2, 1*2가 추가 되는 경우 
       // 10007의 나눈 나머지는 계산 오버플로우
        return (m_dp[n-1]+ 2*m_dp[n-2])% 10'007;
    }
    void Process(){
         m_dp[0]=1; // 2*1인경우
         m_dp[1]=3; // 2*2인 경우

         //n>3인 경우
         for(int i{2}; i< m_value; ++i){
            m_dp[i]=f(i);
         }
        
    }
    void Print(){
        cout<<m_dp[m_value-1]<<'\n';
    }
private:
    int m_value;
    int m_res=0;
    std::vector<int> m_dp;
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