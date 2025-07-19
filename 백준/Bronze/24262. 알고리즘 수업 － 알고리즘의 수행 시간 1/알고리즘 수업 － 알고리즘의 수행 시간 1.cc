#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace std::chrono;

namespace UTIL{
    template<typename T>
    bool RangeCheck(T& val, T min, T max){
        if( (val<min)||(val>max)){
            return false;
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

class CAlgorithmTime{
public: 
    bool InputData(){
        if(!UTIL::Input<int>(m_number, 0, 500000)){
            return false;
        }
        return true;
    }
    void Process(){
        m_count = divNumber(m_number); 
    }
    void Print(){
        cout<< m_count<<endl;
        int tmp=m_count-1; // 2진법의 최고차항
        if(tmp >3 ){
            cout<< "4"<<endl;
        }
        else{
            cout<< tmp <<endl;
        }
    }

private:
    int m_number;
    int m_count=0;

    int divNumber(int n ){
        n = n/2;
        return 1;
    }
};

int main()
{
    CAlgorithmTime algorithmTime;
    if (!algorithmTime.InputData()){
        return -1;
    } 
    algorithmTime.Process(); 
    algorithmTime.Print();
    return 0;
}