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
        if( !UTIL::RangeCheck(m_cmdCount, 1, 1'000'000))
            return false;

        for(int i{0};i< m_cmdCount; ++i){
            string cmd;
            getline(cin, cmd);
            int length = cmd.length();
            int nCmd, nData;
            if(length == 1){
                nCmd = cmd.at(0)-'0';
                nData = 0;
            }
            else if( length > 1){
                nCmd = cmd.at(0)-'0';
                nData = stoi(cmd.substr(2, length-2 ));
                if(!UTIL::RangeCheck(nData, 1, 1'000'000)){
                    return false;
                }
            }
            else{
                return false;
            }
            if(!chkCmd( nCmd, nData)){
                return false;
            }
            m_cmdList.push_back(pair<int,int>(nCmd, nData));
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
    vector<pair<int, int>> m_cmdList;
    vector<int> m_result;
    list<int> m_data;
    bool chkCmd(int cmd, int data){
        //명령어는 1~5 범위
        if( (cmd<1) || (cmd>5)){
            return false;
        }

        // 명령어의 값은 0에서 100,000
        if( (data<0)|| (data > 100'000)){
            return false;
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
        int nData = m_data.back();
        m_data.pop_back();
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
    int at(int aData){
        if(m_data.empty())
            return -1;
        return m_data.back();
    }

    map<int, int(CQuest::*)(int)> m_funcTable={
        {1, &CQuest::push},
        {2, &CQuest::pop},
        {3, &CQuest::size},
        {4, &CQuest::isEmpty},
        {5, &CQuest::at}
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