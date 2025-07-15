#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <map>
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

class CFindPoint{
public: 
    bool InputData(){
        const int nCount=3;
        for(int i=0; i<nCount; ++i ){
            if(!InputCoordinates()){
                return false;
            }
        }
        return true;
    }
    void Process(){
        //직사각형이 될려면 각 x, y의 좌표가 2개씩있어야 한다.  
        m_findX = findPoint(m_xData);
        m_findY = findPoint(m_yData);
        if( (m_findX<0) || (m_findY<0)){
            //TODO. error
        }    
    }
    void Print(){
        cout<< m_findX<< " "<<m_findY<<endl;
        //for(auto data: m_xData){
        //    cout << data.first<<", "<<data.second<<endl;
        //}
        //cout<<"=================="<<endl;
        //for(auto data: m_yData){
        //    cout << data.first<<", "<<data.second<<endl;
        //}
    }
private:
    map<int, int> m_xData;
    map<int, int> m_yData;
    int m_findX, m_findY;
    bool InputCoordinates(){
        // 좌표는 1보다 크거나 같고 1000보다 작거나 같은 정수
        int x, y;
        if(!UTIL::Input(x, 0, 1000)){
            return false;
        }
        if(!UTIL::Input(y, 0, 1000)){
            return false;
        }
        setData(x, m_xData);
        setData(y, m_yData);
        return true;
    }
    void setData(int key, map<int, int>& mapData){
        if(mapData.find(key)== mapData.end()){
            mapData.insert(std::pair<int, int>(key, 1));
        }
        else{
            mapData[key]++;
        }
    }
    int findPoint(map<int, int>& mapData){
        for( auto data: mapData){
            if( data.second == 1){  
                return data.first;
            }
        }
        return -1;
    }
};
int main()
{
    CFindPoint point;
    if(!point.InputData()){
        return -1;
    }
    point.Process();
    point.Print();
    return 0;
}