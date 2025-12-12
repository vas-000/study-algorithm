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
        if(!UTIL::Input(m_value, 1, 1'000'000)){ // N
            return false;
        }
        return true;
    }
    void Process(){
        m_dp.resize(m_value+1);
        m_dp[0]=0; // m_dp[0] = 0 

        int nCalc = m_value;
        for(int i{1}; i<= m_value; ++i ){
            if( i == 1){
                m_dp[1]=0; // 1일때 연산 횟수는 0이다.
                continue;
            }
            else if( i == 2){
                m_dp[2] = 1;
                continue;
            }
            else if( i == 3){
                m_dp[3] = 1;
                continue;
            }

            std::vector<int> branch;
            if( (i % 3) ==0){
                branch.push_back(1+m_dp[i/3]);
            }
            if( (i % 2) ==0){
                branch.push_back(1 + m_dp[i/2]);
            }
            
            branch.push_back(1+ m_dp[i-1]);
            
            //branch의 최소값을 m_dp[i]에 넣는다. 
            m_dp[i] =  *min_element(branch.begin(), branch.end());
        }
        m_res = m_dp[m_value]; 
        
    }
    void Print(){
        cout<<m_res<<'\n';
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