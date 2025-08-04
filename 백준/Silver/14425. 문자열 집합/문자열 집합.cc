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

class CStringSet{
public:
    bool InputData(){
        int N, M;
        if(!UTIL::Input<int>(N, 1, 10'000)){
            return false;
        }
        if(!UTIL::Input<int>(M, 1, 10'000)){
            return false;
        }
        //N개의 줄에 집합 S에 포함되는 문자열 (중복 X)
        for(int i=0; i< N; ++i){
            string data;
            if(!UTIL::Input<string>(data, "1", "500")){
                return false;
            }
            m_stringSet.insert(data);
        }

        //M개의 줄에 검사할 문자열
        for(int i=0; i< M; ++i){
            string data;
            if(!UTIL::Input<string>(data, "1", "500")){
                return false;
            }
            m_target.push_back(data);
        }
        return true;
    }
    void Process(){
        //젤 간단한건 for(for());
        for( auto data: m_target){
            if( m_stringSet.find(data)== m_stringSet.end()){
                continue;
            }
            count++;
        }
    }
    void Print(){
        cout<< count<<'\n';
    }
private:
    int count=0;
    set<string> m_stringSet; 
    vector<string> m_target;
};

int main()
{
    //UTIL::StartTimer();
    ios::sync_with_stdio(false);
    cin.tie(0);

    CStringSet stringSet;
    if (!stringSet.InputData()){
        return -1;
    } 
    stringSet.Process(); 
    stringSet.Print();
    //UTIL::EndTimer();
    
    return 0;
}