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

typedef long long int _INT64;

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
        if( !getData()){
            return false;
        }
        return true;
    }
    void Process(){
        // 최대 공배수 = a * b / 최소공약수
        for(const auto& data: m_data){
            _INT64 gcd = getCommonDivisor(data);
            _INT64 val = (data.first*data.second)/ gcd;
            m_ret.push_back(val);
        }
    }
    void Print(){
        for(auto data: m_ret){
            cout<< data<<'\n';
        }
        
    }
private:
    vector<pair<_INT64, _INT64>> m_data;
    vector<_INT64> m_ret;
    bool getData(){
        _INT64 a, b;
        if(!UTIL::Input<_INT64>(a, 1, 100'000'000)){
            return false;
        }
        if(!UTIL::Input<_INT64>(b, 1, 100'000'000)){
            return false;
        }
        pair<_INT64, _INT64> data(a,b);
        m_data.push_back(data);
        return true;
    }

    int gcd(_INT64 a, _INT64 b){
        int c;
        if( a > b ){
            c= a%b;
            if( c == 0){
                return b;
            }
            a=b;
            b=c;
        }
        else{
            c= b%a;
            if(c == 0){
                return a;
            }
            b=c;
        }

        return gcd(a, b);
    }
    _INT64 getCommonDivisor(std::pair<_INT64, _INT64> data){
        _INT64 a = data.first, b=data.second;
        return gcd(a, b);
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