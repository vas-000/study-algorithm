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

class CSortNumber{
public:
    bool InputData(){
        if(!cardSetting(m_sang)){
            return false;
        }
        if(!cardSetting(m_total)){
            return false;
        }
        return true;
    }
    void Process(){
        for(auto data: m_total){
           if(m_sang.find(data)!=m_sang.end() ){
            cout<< "1 ";
           }
           else{
            cout<< "0 ";
           }
        }
    }
    void Print(){
        cout<< '\n';
    }
private:
    bool cardSetting(set<int>& card){
        int nCard;
        if(!UTIL::Input(nCard, 1, 500'000)){
            return false;
        }
        int data;
        for( int i=0; i<nCard; ++i){
            if(!UTIL::Input(data, -10'000'000, 10'000'000)){
                return false;
            }
            card.insert(data);
        }
        return true;
    }
    bool cardSetting(vector<int>& card){
        int nCard;
        if(!UTIL::Input(nCard, 1, 500'000)){
            return false;
        }
        int data;
        for( int i=0; i<nCard; ++i){
            if(!UTIL::Input(data, -10'000'000, 10'000'000)){
                return false;
            }
            card.push_back(data);
        }
        return true;
    }
   
    set<int> m_sang; // 중복이 안됨.
    vector<int> m_total;

};

int main()
{
    //UTIL::StartTimer();
    ios::sync_with_stdio(false);
    cin.tie(0);

    CSortNumber sortNumber;
    if (!sortNumber.InputData()){
        return -1;
    } 
    sortNumber.Process(); 
    sortNumber.Print();
    //UTIL::EndTimer();
    
    return 0;
}