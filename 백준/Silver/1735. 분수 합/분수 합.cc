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

        if( !getData()){
            return false;
        }
        return true;
    }
    void Process(){
        m_denominator = getCommonMultiple(m_data[0].second,m_data[1].second);
        int numerator1 = m_data[0].first* (m_denominator / m_data[0].second);
        int numerator2 = m_data[1].first* (m_denominator / m_data[1].second);
        m_numerator = numerator1+numerator2;

        //분자와 분모의 최소 공약수를 구해 나눠줌. 
        int commonDivisor = getCommonDivisor(pair<int,int>(m_numerator, m_denominator));
        m_denominator = m_denominator/commonDivisor;
        m_numerator = m_numerator/commonDivisor;
    }
    void Print(){
        cout << m_numerator<<' '<<m_denominator<<'\n';
    }
private:
    vector<pair<int, int>> m_data;
    int m_denominator;
    int m_numerator;
    bool getData(){
        int a, b;
        if(!UTIL::Input<int>(a, 1, 30'000)){
            return false;
        }
        if(!UTIL::Input<int>(b, 1, 30'000)){
            return false;
        }
        pair<int, int> data(a,b); // a:분자, b:분모
        m_data.push_back(data);
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