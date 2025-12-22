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
        if(!UTIL::Input(m_nTestcase, 0,1000)){ // TESTCASE
            return false;
        }

        for(int i{}; i< m_nTestcase; ++i){
            int nValue;
            if(!UTIL::Input(nValue, 0, 11))
                return false;

            m_data.push_back(nValue);
        }
        return true;
    }
    void Process(){
        m_dp.assign(4, std::vector<int>(11,0));
        m_dp[1][1]=1;
        m_dp[1][2]=1;
        m_dp[1][3]=2;
        for(int i{1}; i<4; ++i){
            if(i==1){
                for(int j{4}; j<11;++j){
                    m_dp[i][j]= m_dp[i][j-1]+m_dp[i][j-2]+m_dp[1][j-3];
                }
            }
            else{
                for(int j{1};j<11;j++){
                    m_dp[i][j]=m_dp[i-1][j-1];
                }
            }
        }
        
        for(auto data: m_data){
            m_out.push_back(m_dp[1][data]+m_dp[2][data]+m_dp[3][data]);
        }
    }
    void Print(){
        for(auto val: m_out){
            cout << val <<"\n";
        }
    }
private:
    int m_nTestcase;
    std::vector<std::vector<int>> m_dp;
    std::vector<int> m_data;
    std::vector<int> m_out;
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