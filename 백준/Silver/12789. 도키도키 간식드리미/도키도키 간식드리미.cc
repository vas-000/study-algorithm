#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
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
        if(!UTIL::Input(m_total, 1, 1000)){
            return false;
        }
        for(int i{}; i<m_total; ++i){
            int nNum;
            if(!UTIL::Input(nNum, 1, 1000)){
                return false;
            }
            //중복 처리를 하지 않는다. 
            m_line.push_back(nNum);
        }
        return true;
    }
    void Process(){
        //cout<< "start Process"<<endl;
        for(int i{1}; i< m_total; ++i){
            if(!nextPerson(i)){
                m_res = "Sad";
                return;
            }   
        }
        m_res = "Nice";

    }
    void Print(){
        cout<< m_res<<'\n';
    }
private:
    int m_total;
    list<int> m_line;
    vector<int> m_wait; // 
    vector<int> m_result;
    string m_res;
    
    bool nextPerson(int no){
        if( !m_wait.empty()){
            int nNo = m_wait.back();
            if( nNo == no){
                m_wait.pop_back();
                m_result.push_back(nNo);
                return true;
            }
        }
        while(!m_line.empty()){
            int nNo = m_line.front();
            m_line.pop_front();
            if( nNo == no){
                m_result.push_back(nNo);
                return true;
            }
            m_wait.push_back(nNo);
        }
        return false;
    }
    
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