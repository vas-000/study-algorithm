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

class CDecompositionSum{
public: 
    bool InputData(){
        if(!UTIL::Input<int>(m_targetNumber, 1, 100000000)){
            return false;
        }
        return true;
    }
    void Process(){  
        // 루프횟수가 m_targetNumber 보다는 작다 
        for(int i=1; i<=m_targetNumber; ++i){
            // 각자리수의 합 + 원본값
            int sum = getPositionSum(i);
            if( (i+sum) == m_targetNumber){
                m_retValue = i;
                return;
            }
        }
    }
    void Print(){
        cout<< m_retValue <<endl;
    }
private:
    int m_targetNumber=0;
    int m_retValue=0;

    int getPositionSum(int number){
        // 각 자리수 합
        int n=number;
        int sum=0;
        do{
            int remainder = n % 10;
            sum+= remainder;
        }while((n=n/10) != 0);
        return sum;
    }
};

int main()
{
    CDecompositionSum sum;
    if (!sum.InputData()){
        return -1;
    } 
    sum.Process(); 
    sum.Print();
    return 0;
}