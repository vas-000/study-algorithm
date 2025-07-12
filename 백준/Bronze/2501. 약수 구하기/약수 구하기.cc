#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

namespace UTIL{
    bool RangeCheck(int& val, int min, int max){
        if( (val<min)||(val>max)){
            return false;
        }
        return true;
    }

    bool Input(int& val, int min, int max){
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

class CFactor{
public:
    bool InputData(){
        cin>> m_number>>m_count;
        if(!UTIL::RangeCheck(m_number, 0, 10000)
        || !UTIL::RangeCheck(m_count, 1, m_number)){
            return false;
        }
        
       return true;
    }

    void Process(){
 //       UTIL::StartTimer();
        getFactor(1);
 //       UTIL::EndTimer();

    }
    void Print(){
        if( m_factors.size()< m_count){
            cout<< "0"<<endl;
            return;
        }
        cout<< m_factors[m_count-1]<<endl;
    }
    
private:
    vector<int> m_factors;
    int m_number;
    int m_count;
    void getFactor(int aDiv){
        if( m_number == aDiv){
            m_factors.push_back(aDiv);
            return;
        }
        if((m_number % aDiv) == 0){
            m_factors.push_back(aDiv);
        }
        aDiv+=1;
        getFactor(aDiv);
    }
};

int main()
{
    CFactor factor;
    if(!factor.InputData()){
        return -1;
    }
    factor.Process();
    factor.Print();
    return 0;
}