#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <vector>
#include <cmath>

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

class CRetangleArea{
public: 
    bool InputData(){
        if(!UTIL::Input(m_height, 0, 100)){
            return false;
        }
        if(!UTIL::Input(m_width, 0, 100)){
            return false;
        }
        return true;
    }
    void Process(){
       m_area=m_height* m_width;
    }
    void Print(){
        cout<< m_area<<endl;
    }
private:
    vector<int> m_data;
    int m_height=0;
    int m_width=0;
    int m_area=0;
};
int main()
{
    CRetangleArea area;
    if(!area.InputData()){
        return -1;
    }
    area.Process();
    area.Print();
    return 0;
}