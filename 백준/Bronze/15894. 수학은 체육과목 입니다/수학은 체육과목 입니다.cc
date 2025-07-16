#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <map>
#include <cmath>

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

class CRectArea{
public: 
    bool InputData(){
        if(!UTIL::Input<unsigned int>(m_lastLine, 0, 1000000000)){
            return false;
        }
        return true;
    }
    void Process(){
        //결국 밑변의 길이와 같은 사각형의 둘레
        m_circumference= m_lastLine*4;    
    }
    void Print(){
        cout<< m_circumference <<endl;
    
    }
private:
    unsigned int m_lastLine;
    unsigned int m_circumference=0;
    
};
int main()
{
    CRectArea area;
    if(!area.InputData()){
        return -1;
    }
    area.Process();
    area.Print();
    return 0;
}