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

class CBigO{
public: 
    bool InputData(){
        if(!UTIL::Input<int>(m_a1, -100, 100)){
            return false;
        }
        if(!UTIL::Input<int>(m_a0, -100, 100)){
            return false;
        }
        if(!UTIL::Input<int>(m_c, 1, 100)){
            return false;
        }
        if(!UTIL::Input<int>(m_n0, 1, 100)){
            return false;
        }
        return true;
    }
    void Process(){
        // f(x) = a1n+a0;
        // g(x) = n // bigO 정의에 따라 n의 최고차항이 됨.
        // O(n)을 맍족하기 위해서는 a1n+a0 <= cn 이 되어야 함.
        // n의 값은 n>=n0
        if( m_c==m_a1){
            if(m_a0<=0){//O(n) 무조건 만족한다.
                m_ret=1;
            }
            else{
                if( m_a0<=m_n0){
                    m_ret=1;
                }
                else{
                    m_ret=0;
                }
            }
        }
        else if(m_a1<m_c){
            int n0=m_a0/(m_c-m_a1);
            if(m_n0>=n0){
                m_ret =1;
            }
            else{
                m_ret =0;
            }
        }
        else{
            if(m_a0>=0){
                
                m_ret=0;
            }
            else{
                int n0=m_a0/(m_c-m_a1);
                if(n0<=0){
                    m_ret=1;
                }
                else{
                    m_ret=0;
                }
            }
        }
               
    }
    void Print(){
        cout<< m_ret<<endl;
    }
private:
    int m_a1, m_a0;
    int m_c;
    int m_n0;
    int m_ret=0;
    int func_F(int n){
        
        return (m_a1 * n)+m_a0;
    }
    
};

int main()
{
    CBigO bigO;
    if (!bigO.InputData()){
        return -1;
    } 
    bigO.Process(); 
    bigO.Print();
    return 0;
}