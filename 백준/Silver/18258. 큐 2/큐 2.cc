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

        string strCount;
        getline(cin, strCount);
        m_cmdCount = stoi(strCount);
        if( !UTIL::RangeCheck(m_cmdCount, 1, 2'000'000))
            return false;

        const size_t arraySize=10;
        for(int i{0};i< m_cmdCount; ++i){
            string cmd;
            int value=0;
            cin>>cmd;
            if(cmd.compare("push")==0){
                cin>>value;
            }
            
            if(!chkCmd(cmd, value)){
                return false;
            }

            m_cmdList.push_back(pair<string,int>(cmd, value));
        }
        return true;
    }
    void Process(){
        //cout<< "start Process"<<endl;
        for(auto cmd: m_cmdList){
            int res = (this->*(m_funcTable[cmd.first]))(cmd.second);
            if(res >=-1)
                m_result.push_back(res);
        }
        
    }
    void Print(){
        for(auto res: m_result){
            cout<< res << '\n';
        }
        
    }
private:
    int m_cmdCount;
    vector<pair<string, int>> m_cmdList;
    vector<int> m_result;
    list<int> m_data;
    bool chkCmd(string cmd, int value){
        if(m_funcTable.find(cmd) == m_funcTable.end()){
            return false;
        }

        // 명령어의 값은 1에서 100,000
        if( value!=0){
            if(!UTIL::RangeCheck(value, 1, 100'000)){
                return false;
            }
        }
        return true;
    }
    int push(int aData){ 
        m_data.push_back(aData);
        return -3;
    }

    int pop(int aData){
        if(m_data.empty())
            return -1;
        int nData = m_data.front();
        m_data.pop_front();
        return nData;
    }
    int size(int aData){
        return m_data.size();
    }
    int isEmpty(int aData){
        if( m_data.empty())
            return 1;
        return 0;
    }
    int front(int aData){
        if(m_data.empty())
            return -1;
        return m_data.front();
    }
    int back(int aData){
        if(m_data.empty())
            return -1;
        return m_data.back();
    }
    map<string, int(CQuest::*)(int)> m_funcTable={
        {"push", &CQuest::push},
        {"pop", &CQuest::pop},
        {"size", &CQuest::size},
        {"empty", &CQuest::isEmpty},
        {"front", &CQuest::front},
        {"back", &CQuest::back},
    };

    
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