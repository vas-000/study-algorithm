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
            if(!getSide()){
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
                cout<< "Invalid"<<endl;
        }
    }
    bool IsInputEnd(){
        // 세변이 0이면 종료
        if( (m_side[0] +m_side[1]+m_side[2])== 0){
                return true;
        }
        return false;
    }

private:
    vector<int> m_side;// x, y coordination
    defTriangleString m_type=defTriangleString::Error;

    bool getSide(){
        int nSide;
        if(!UTIL::Input<int>(nSide, 0, 1000) ){
            return false;
        }
        m_side.push_back(nSide);
        return true;
    }
    bool isTriangle(){
        // 가장긴변의 길이보다 나머지 두변의 길이의 합이 길이 않으면 삼각형이 아니다.
        vector<int> tmp;
        tmp.insert(tmp.end(), m_side.begin(), m_side.end());

        auto MaxIter = max_element(tmp.begin(), tmp.end());
        int nMax = *MaxIter;
        tmp.erase(MaxIter);

        //남은 값의 합을 구한다.
        int nSum=0;
        for(auto data: tmp){
            nSum+=data;
        }
        // cout << nSum <<", "<< nMax<< endl;
        if( nSum <= nMax )
            return false;

        return true;
    }

    bool isEquilateral(){
        // 입력된 세변의 길이가 같으면 정삼각형
        if( (m_side[0] == m_side[1]) && 
            (m_side[0] == m_side[2]) && 
            (m_side[1] == m_side[2])){
                return true;
        }
        return false;
    }

    bool isScalene(){
        // 입력된 세변이 모두 같지 않으면 Scalene
        if( (m_side[0] != m_side[1]) && 
            (m_side[0] != m_side[2]) && 
            (m_side[1] != m_side[2])){
                return true;
        }
        return false;
    }
};

class CTestcase{
public:
    bool InputData(){
        while(true){
            CTriagle triagle;
            if(!triagle.InputData()){
                return false;
            }
            if( triagle.IsInputEnd()){
                break;
            }
            m_data.push_back(triagle);
        }
        return true;
    }
    void Process(){
        for(auto& data: m_data){
            data.Process();
        }
    }
    void Print(){
        for(auto data: m_data){
            data.Print();
        }
    }
private:
    vector<CTriagle> m_data;
};
int main()
{
    CTestcase tc;
    if (!tc.InputData()){
        return -1;
    } 
    tc.Process(); 
    tc.Print();
    return 0;
}