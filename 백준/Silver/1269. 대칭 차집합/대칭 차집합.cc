#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <unordered_set>
#include <random>
#include <type_traits>

using namespace std;
using namespace std::chrono;

#define TESTCASE 0

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
    typedef enum{
        defA=1,
        defB=2,
        defAll=3
    }defType;
    bool InputData(){
        int nACount;
        if(!UTIL::Input(nACount, 1, 200'000)){
            return false;
        }
        int nBCount;
        if(!UTIL::Input(nBCount, 1, 200'000)){
            return false;
        }

        if(!numberSet(nACount, defA)){
            return false;
        }
        if(!numberSet(nBCount, defB)){
            return false;
        }
        return true;
    }
    void Process(){
        for(const auto& data: m_setData){
            if( (data.second==defA) || (data.second==defB)){
                m_total++;
            }
        }
        
    }
    void Print(){
        cout<<m_total<<"\n";
    }
private:
    bool numberSet(int aCount, defType type){
        int data;
        for( int i=0; i<aCount; ++i){
            if(!UTIL::Input<int>(data, 0, 100'000'000)){
                return false;
            }        
            if(m_setData.find(data)== m_setData.end()){
                m_setData[data]=type;
            }
            else{
                m_setData[data] += type;
            }
        }
        return true;
    }
    map<int, int> m_setData; // number, a or b
    int m_total=0;
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