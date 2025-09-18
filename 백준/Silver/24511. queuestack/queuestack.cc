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
        int count;
        if(!UTIL::Input(count, 1, 100'000)){
            return false;
        }

        //type
        for(int i{}; i< count; ++i){
            int type;
            if(!UTIL::Input(type, 0, 1)){
                return false;
            }
            m_data.push_back({type,0});
        }
        
        // initalize val
        for(int i{}; i< count; ++i){
            int val;
            if(!UTIL::Input(val, 0, 1'000'000'000)){
                return false;
            }
            m_data[i].second=val;
        }

        //insert size
        if(!UTIL::Input(count, 1, 100'000)){
            return false;
        }

        //insert val
        for(int i{}; i< count; ++i){
            int val;
            if(!UTIL::Input(val, 0, 1'000'000'000)){
                return false;
            }
            m_insert.push_back(val);
        }
        return true;
    }
    void Process(){
        for(auto data: m_data){
            if(data.first == 1){
                //스택은 변화가 없음. 
                continue;
            }
            //큐는 기존 데이터를 최상위에 넣고 최하위 데이터가 초기값에 들어감.
            m_insert.push_front(data.second);
            m_insert.pop_back();   
        }

    }
    void Print(){
        for(auto res: m_insert){
            cout<< res << ' ';
        }
        cout<<'\n';
    }
private:
    vector<int> m_result;
    vector<pair<int,int>> m_data;
    list<int> m_insert;
   
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