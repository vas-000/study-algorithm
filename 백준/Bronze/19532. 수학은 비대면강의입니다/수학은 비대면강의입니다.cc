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

class CEquation{
public: 
    bool InputData(){
        const int factorCnt=6;
        for(int i=0; i<factorCnt; ++i){
            if(!UTIL::Input<int>(m_factor[i], -999, 999)){
                return false;
            }
        }
        return true;
    }
    void Process(){  
        // ax + by = c
        // dx + ey = f
        // y=(dc-af)/(db-ae)
        // db-ae == 0일때 
        stFactor *factor=reinterpret_cast<stFactor*>(m_factor);
        int a= factor->d*factor->c - factor->a*factor->f;
        int b = factor->d*factor->b - factor->a*factor->e;
        if( b != 0){
            m_y = (a/b);
            //x = (c-by)/a
            if( factor->a != 0)
                m_x = (factor->c-factor->b*m_y)/factor->a;
            else
                m_x = (factor->f-factor->e*m_y)/factor->d;
        }
        else{
            // c == f
            for( int x=-999; x<=999; ++x){
                for(int y=-999; y<=999; ++y){
                    if( (factor->a*x+factor->b*y)==factor->c){
                        m_x = x;
                        m_y = y;
                        return;
                    }
                }
            }
        }
    }
    void Print(){
        cout<< m_x<<" "<<m_y <<endl;
    }
private:
    typedef struct{
        int a;
        int b;
        int c;
        int d;
        int e;
        int f;
    }stFactor;
    int m_factor[6];
    int m_x, m_y;
    

};

int main()
{
    CEquation equation;
    if (!equation.InputData()){
        return -1;
    } 
    equation.Process(); 
    equation.Print();
    return 0;
}