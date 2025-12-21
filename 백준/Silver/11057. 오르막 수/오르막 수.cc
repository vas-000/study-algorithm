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
        if(!UTIL::Input(m_value, 1, 1'000)){ // N
            return false;
        }
        //1로 초기화 한다.
        m_dp.assign(m_value+1, std::vector<int>(11, 0));
        return true;
    }

    void Process(){
        for(int i{1};i<11; ++i){
            //1자리일때 값을 넣어 준다. 
            m_dp[1][i]=1;
        }
        if(m_value==1){
            return;
        }

        int loop=m_value+1;
        for(int i{2}; i<loop; i++){
            for(int j{1}; j<11; j++){
                m_dp[i][j]= (m_dp[i-1][j]+m_dp[i][j-1])%10007;
            }
        }

        
        
    }
    void Print(){
        int sum=0;
        for(int i{1}; i<11; ++i){
            sum = (sum+m_dp[m_value][i])%10007;
        }
        cout<<sum<<'\n';
    }
private:
    int m_value;
    int m_res=0;
    std::vector<std::vector<int>> m_dp;
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