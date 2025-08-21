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
        if(!UTIL::Input(nTestcase, 0, 100)){
            return false;
        }
        for(int i{};i<nTestcase; ++i){
            int data;
            if(!UTIL::Input(data, 2, 1'000'000)){
                return false;
            }
            if( data%2 !=0){
                return false;
            }
            m_data.push_back(data);
        }

        return true;
    }
    void Process(){
        //cout<< "start Process"<<endl;
        //UTIL::StartTimer();
        char minorityTbl[1'000'001]={0,};
        getMinority(1'000'000, minorityTbl);
        for(auto data: m_data){
            char unit[1'000'001]={0,};
            memcpy( unit, minorityTbl, data);
            m_ret.push_back(getGoldbachCount(data, unit));    
        }
        //UTIL::EndTimer();
    }
    void Print(){
        for(auto data: m_ret){
            cout<< data <<"\n";
        }   
    }
private:
    vector<int> m_data;
    vector<int> m_ret;
    int m_total=0;

    int getGoldbachCount(const int& data, const char* unit){
        int count=0,self=0;
        for( int i{}; i<= data; ++i){
            if( unit[i]==0){
                // 0~data 사이에 존재하는 소수가 아님
                continue;
            }
            if( data-i==i){
                // 자기 자신을 더 할경우
                self++;
                continue;
            }
            if( unit[data-i]==0){
                // data - 소수 를 했을경우 뺀값이 소수가 아닌경우.
                continue;
            }
            count++;
        }
        return count/2+self;
    }
    void getMinority(const int& data, char* p)
    {   // 범위내 소수를 구한다.
        for(int i{2}; i<=data; ++i ){
            if(!chkMinority(i)){
                continue;
            }
            p[i]=1;
        }
    }
    bool chkMinority(const int& num){
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
            //int N = round(sqrt(num));
            int N = sqrt(num);
            //num의 약수는 N의 범위에 있음. 
            for( int i{3}; i<=N; i=i+2){
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