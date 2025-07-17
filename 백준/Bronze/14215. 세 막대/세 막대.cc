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
        getMaxTriangle();
    }
    void Print(){
        cout<< m_circumference<< endl;
    }

private:
    vector<int> m_side;// x, y coordination
    int m_circumference;
    bool getSide(){
        int nSide;
        if(!UTIL::Input<int>(nSide, 1, 100) ){
            return false;
        }
        m_side.push_back(nSide);
        return true;
    }
    bool getMaxTriangle(){
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
        if( nSum <= nMax ){
            //가장 긴변의 길이를 나머지 두변의 합보다 1작게해서 삼각형을 만들수 있도록한다.
            nMax= nSum-1;
        }

        m_circumference = nSum+nMax;
        return true;
    }
};

int main()
{
    CTriagle triagle;
    if (!triagle.InputData()){
        return -1;
    } 
    triagle.Process(); 
    triagle.Print();
    return 0;
}