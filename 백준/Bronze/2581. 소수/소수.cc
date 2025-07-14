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

class CFindFactor{
public: 
    bool InputData(){
         
        if(!UTIL::Input(m_start, 0, 10000)){
            return false;
        }
        
        if(!UTIL::Input(m_end, m_start, 10000)){
            return false;
        }

        return true;
    }
    void Process(){
        for( int i=m_start; i<= m_end; ++i){
            if(!isMinority(i)){
                continue;
            }        
            m_data.push_back(i);
        }
    }
    void Print(){
        if(m_data.empty()){
            cout<< "-1"<<endl;
            return;
        }
        int sum=0;
        for(auto data:m_data){
            sum+=data;
        }
        cout<< sum<<endl;
        cout<<m_data[0]<<endl;
    }
private:
    vector<int> m_data;
    int m_start; // M
    int m_end;   // N

    bool isMinority(int data){
        if( (data %2) ==0){
            if( data == 2){ // 2 는 소수임.        
                return true;
            }
            // 그외 2로 나누어 떨어지는 수(짝수)
            return false;
        }
        else{
            if( data == 1){//1은 소수가 아님
                return false;
            }
            int nCnt=0;
            for(int i=1; i<=data; ++i){
                if( (data%i)==0 ){
                    nCnt++;
                    if( nCnt > 2){
                        return false;
                    }
                }
            }
            return true;
        }
        return false;  
    } 
};
int main()
{
    CFindFactor findFactor;
    if(!findFactor.InputData()){
        return -1;
    }
    findFactor.Process();
    findFactor.Print();
    return 0;
}