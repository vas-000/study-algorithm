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

class CGroundArea{
public: 
    bool InputData(){
        int nBeadCount=0;
        if(!UTIL::Input<int>(nBeadCount, 0, 100000)){
            return false;
        }

        for( int i=0;i<nBeadCount; ++i ){
            if(!getBeadPosition()){
                return false;
            }
        }
        return true;
    }
    void Process(){
        //X, Y의 최소값, 최대값
        //초기값 설정
        int minX=m_beadPosition[0].m_x, minY=m_beadPosition[0].m_y, maxX=m_beadPosition[0].m_x, maxY=m_beadPosition[0].m_y;
        
        for(auto beadPos: m_beadPosition){
            getMinMax(minX, maxX, beadPos.m_x);
            getMinMax(minY, maxY, beadPos.m_y);
        }

        //cout<< minX<<", "<<maxX<<", "<<minY<<", "<<maxY<<endl;
        m_area = (maxX-minX)*(maxY-minY);
        
    }
    void Print(){
        cout<< m_area <<endl;
    
    }
private:
    typedef struct ST_Bead{
        int m_x;
        int m_y;
    }stBead;
    vector<stBead> m_beadPosition;// x, y coordination
    int m_area;

    bool getBeadPosition(){
        int x, y;
        if(!UTIL::Input<int>(x, -10000, 10000)||
           !UTIL::Input<int>(y, -10000, 10000) ){
            return false;
        }

        //좌표계를 이동한다. 4분면상의 좌표계를 X, Y 0,0 좌표로 변환해서 생각함. 
        stBead bead;
        bead.m_x = x+10000;
        bead.m_y = y+10000;
        m_beadPosition.push_back(bead);
        return true;
    }
    
    void getMinMax(int& aMin, int& aMax, int& data){
        aMin = min(aMin, data);
        aMax = max(aMax, data);
    }
    
};
int main()
{
    CGroundArea area;
    if(!area.InputData()){
        return -1;
    }
    area.Process();
    area.Print();
    return 0;
}