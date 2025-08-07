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
        defListen=1,
        defSee=2,
        defAll=3,
    }defPersonType;

    bool InputData(){
        int nListenCount;
        if(!UTIL::Input(nListenCount, 1, 500'000)){
            return false;
        }
        int nSeeCount;
        if(!UTIL::Input(nSeeCount, 1, 500'000)){
            return false;
        }
        if(!personSet(nListenCount, defPersonType::defListen)){
            return false;
        }
        if(!personSet(nSeeCount, defPersonType::defSee)){
            return false;
        }
        return true;
    }
    void Process(){
        for(const auto& data: m_person){
            if(data.second==defAll){
                m_count++;
            }
        }
    }
    void Print(){
        cout << m_count<<'\n';
         for(auto data: m_person){
            if(data.second==defAll){
                cout<< data.first<<'\n';
            }
         }     
    }
private:
    bool personSet(int aCount, defPersonType type){
        string data;
        for( int i=0; i<aCount; ++i){
            if(!UTIL::Input<string>(data, "1", "20")){
                return false;
            }
            if( m_person.find(data)== m_person.end()){
                m_person[data] = type;
            }
            else{
                m_person[data] |= type;
            }        
        }
        return true;
    }

    map<string, int> m_person; // 사람이름, 타입(듣도 못한사람, 보도 못한사람)
    int m_count=0;
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