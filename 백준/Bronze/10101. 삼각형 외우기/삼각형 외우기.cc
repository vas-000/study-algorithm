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

enum class defTriangleString{
    Error=-1,
    Equilateral,
    Isosceles,
    Scalene,
};

class CTriagle{
public: 
    bool InputData(){
        for( int i=0;i<3; ++i ){
            if(!getAngle()){
                cout<< "ttt"<<endl;
                return false;
            }
        }
        return true;
    }
    void Process(){
        if(!isTriangle()){
            m_type=defTriangleString::Error;
            return;
        }
        
        if(isEquilateral()){
            m_type=defTriangleString::Equilateral;
            return;
        }
        
        if(isScalene()){
            m_type=defTriangleString::Scalene;
            return;
        }

        m_type=defTriangleString::Isosceles;
    }
    void Print(){
        switch(m_type){
            case defTriangleString::Equilateral:
                cout <<"Equilateral"<<endl;
                break;
            case defTriangleString::Isosceles:
                cout <<"Isosceles"<<endl;
                break;
            case defTriangleString::Scalene:
                cout<< "Scalene"<<endl;
                break;
            case defTriangleString::Error:
            default:
                cout<< "Error"<<endl;
        }
    }
private:
    vector<int> m_angle;// x, y coordination
    defTriangleString m_type=defTriangleString::Error;

    bool getAngle(){
        int angle;
        if(!UTIL::Input<int>(angle, 0, 180) ){
            return false;
        }
        m_angle.push_back(angle);
        return true;
    }
    bool isTriangle(){
        // 입력된 세각의 합이 180이 아니면 삼각형이 아니다.
        if( (m_angle[0]+m_angle[1]+m_angle[2]) != 180)
            return false;
        return true;
    }
    bool isEquilateral(){
        // 입력된 세각이 모두 60이면 정삼각형
        const int nAngle=60;
        if( (m_angle[0] == nAngle) && 
            (m_angle[1] == nAngle) && 
            (m_angle[2] == nAngle)){
                return true;
        }
        return false;
    }

    bool isScalene(){
        // 입력된 세각이 모두 같지 않으면 Scalene
        if( (m_angle[0] != m_angle[1]) && 
            (m_angle[0] != m_angle[2]) && 
            (m_angle[1] != m_angle[2])){
                return true;
        }
        return false;
    }

};
int main()
{
    CTriagle triangle;
    if (!triangle.InputData()){
        return -1;
    } 
    triangle.Process(); 
    triangle.Print();
    return 0;
}