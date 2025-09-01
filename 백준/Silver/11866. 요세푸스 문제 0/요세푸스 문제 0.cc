#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <map>
#include <list>
#include <queue>
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
        cin>>m_total >>m_space;
        if( m_space > m_total || m_total >1'000){
            return false;
        }
        if( m_space<1){
            return false;
        }
        return true;
    }
    void Process(){
        //데이터 생성
        for(int i{1}; i<=m_total; ++i){
            m_data.push_back(i);
        }

        auto iter = m_data.begin();
        int nCnt=m_space-1; // begin()이 1부터 시작이기 때문에 
        while(!m_data.empty()){
            if(nCnt == 0){
                m_ret.push_back(*iter);
                auto delIter = iter;
                iter--;
                m_data.erase(delIter);
                nCnt=m_space;
                continue;
            }
            iter++;
            if( iter == m_data.end())    
                iter = m_data.begin();
            nCnt--;
        }
        
    }
    void Print(){
        string msg;
        msg ="<";
        int nSize = m_ret.size();
        int nCmpSize =nSize-1;
        for(int i{}; i<nSize; ++i){
            msg += to_string(m_ret[i]);
            if(nCmpSize != i)
                msg +=", ";
            else
                msg +=">";
        }
        cout<<msg<<endl;
    }
private:
    int m_total;
    int m_space;
    vector<int> m_ret;
    list<int> m_data;
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