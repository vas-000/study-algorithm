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

class CRectangleExit{
public: 
    bool InputData(){
        // 1<= w,h <=1000
        // 1<= x <= w-1
        // 1<= y <= h-1
        if(!UTIL::Input(m_x, 0, 1000)){
            return false;
        }
        if(!UTIL::Input(m_y, 0, 1000)){
            return false;
        }
        if(!UTIL::Input(m_width, 0, 1000)){
            return false;
        }
        if(!UTIL::Input(m_height, 0, 1000)){
            return false;
        }

        //X,Y 예외처리
        if( !UTIL::RangeCheck(m_x, 0, m_width) ||
            !UTIL::RangeCheck(m_y, 0, m_height)){
                return false;
        }
        return true;
    }
    void Process(){
        int directX = minDistance(m_x, m_width-m_x);
        int directY = minDistance(m_y, m_height-m_y);
        m_minDistance = minDistance(directX, directY);
    }
    void Print(){
        cout<< m_minDistance<<endl;
    }
private:
    vector<int> m_data;
    int m_x=0, m_y=0;
    int m_height=0, m_width=0;
    int m_minDistance=0;
    int minDistance(int a, int b){
        if( a > b){
            return b;
        }
        return a;
    }
};
int main()
{
    CRectangleExit rectExit;
    if(!rectExit.InputData()){
        return -1;
    }
    rectExit.Process();
    rectExit.Print();
    return 0;
}