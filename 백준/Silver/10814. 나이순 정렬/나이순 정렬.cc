#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <random>
#include <type_traits>

using namespace std;
using namespace std::chrono;

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

typedef struct STMEMBER{
    int age;
    string name;
}stMember;

class CMember{
public: 
    bool InputData(){
        int testCase;
        if(!UTIL::Input<int>(testCase, 1, 100'000)){
            return false;
        }
        int val;
        for(int i=0; i< testCase; ++i){
            stMember member;
            cin>>member.age >> member.name;
            if(!UTIL::RangeCheck<int>(member.age, 1, 200)){
                return false;
            }
            if( !UTIL::IsAlpha(member.name)){
                return false;
            }
            if( !UTIL::RangeCheck<string>(member.name, "1", "200")){
                return false;
            }
            if(m_data.find(member.age)==m_data.end()){
                vector<stMember> data;
                data.push_back(member);
                m_data[member.age]=data;
            }
            else{
                m_data[member.age].push_back(member);
            }
        }
    
        return true;
    }
    void Process(){ 
        //키를 백터로 복사하여 정렬한다.
        for(auto data: m_data){
            m_key.push_back(data.first);
        }

        sort(m_key.begin(), m_key.end());
    }

    void Print(){
        for(auto key: m_key){
            auto datas = m_data[key];
            for(auto data: datas){
                cout<< data.age << " "<< data.name<<endl;
            }
        }    
    }
private:
    std::vector<int> m_key;
    map<int, vector<stMember>> m_data;
    
};

int main()
{
    CMember member;
    if (!member.InputData()){
        return -1;
    } 
    member.Process(); 
    member.Print();
    return 0;
}