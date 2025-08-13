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
        int nTestcase;
        if(!UTIL::Input(nTestcase, 1, 1'000'000)){
            return false;
        }

        if(!getData(nTestcase)){
            return false;
        }

        return true;
    }
    void Process(){
        for(auto data: m_data){
            _UINT64 nRet = data;
            while(!chkMinority(nRet)){
                nRet++;
            }
            m_ret.push_back(nRet);
        }
    }
    void Print(){
        for(auto data: m_ret){
            cout<< data<<'\n';
        }
    }
private:
    vector<_UINT64> m_data;
    vector<_UINT64> m_ret;
    int m_total=0;

    bool getData(int nCount){
        for(int i{}; i<nCount; ++i){
            _UINT64 nData=0;
            if(!UTIL::Input<_UINT64>(nData, 0, 4'000'000'000)){
                return false;
            }
            m_data.push_back(nData);
        }
        return true;
    }

    bool chkMinority(const _UINT64 num){
        if( num%2 ==0){
            if(num==2){
                return true;
            }
            //짝수는 소수가 아님
            return false;
        }
        else{
            if( num == 1){
                return false;
            }
            _UINT64 N = round(sqrt(num));
            //num의 약수는 N의 범위에 있음. 
            for( _UINT64 i{2}; i<=N; ++i){
                if( num%i == 0){
                    // 나눠떨어지는 수가 하나라도 있으면 소수가 아님.
                    return false;
                }
            }

        }
        return true;
    }

    //유클리드호제법
    int gcd(int a, int b){
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
    int getCommonDivisor(std::pair<int, int> data){
        //최소 공약수
        int a = data.first, b=data.second;
        return gcd(a, b);
    }

    int getCommonMultiple(int a, int b){
        // 최대 공배수 = a * b / 최소공약수
        pair data(a, b);
        int gcd = getCommonDivisor(data);
         return ((data.first*data.second)/ gcd);
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