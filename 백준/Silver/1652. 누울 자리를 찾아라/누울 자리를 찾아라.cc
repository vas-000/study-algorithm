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
        if(!UTIL::Input(m_number, 0, 1'000'000)){
            return false;
        }
        for(int i{};i<m_number; i++){
            string row;
            cin>>row;
            if(row.size()>m_number){
                return false;
            }
            if( row.find_first_not_of(".X")!=string::npos){
                return false;
            }
            m_data.push_back(row);      
        }
        return true;
    }
    void Process(){
        // 가로 연속 2개 이상인 경우
        findPlace(m_data, m_row);

        //string vector을 90도로 회전한다.
        for(int i{}; i<m_number; ++i){
            string str;
            m_rotateData.push_back(str);
        }
        for(int i{}; i<m_number; ++i){
            auto data=m_data[i];
            for(int j{}; j<m_number; ++j){
                m_rotateData[j].push_back(data.at(j));
            }
        }

        findPlace(m_rotateData, m_col);

    } 
    void Print(){
        cout<<m_row<<" "<<m_col<<'\n';
    }
private:
    int m_number;
    int m_ret=0;
    vector<string> m_data;
    vector<string> m_rotateData;
    int m_row=0;
    int m_col=0;

    void findPlace(const vector<string>& map, int &count){
        int nCount=0;
        vector<int> table;
        for(int i{}; i< m_number; ++i){
            auto row = map.at(i);
            //연속된 "."이 2곳 이상일경우 
            for(int j{}; j< row.length(); j++){
                if(row.at(j)=='.'){
                    nCount++;
                }
                else{
                    if(nCount>=2){
                        table.push_back(nCount);
                    }
                    nCount=0;
                }
            }
            if(nCount>=2){
                table.push_back(nCount);
            }
            nCount=0;
        }
        count = table.size();
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