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

class CTestCase{
public: 
    bool InputData(){
        int m_count; 
        if(!UTIL::Input(m_count, 0, 100)){
            return false;
        }

        for(int i=0; i< m_count; ++i){
            int data;
            if(!UTIL::Input(data, 0, 1000)){
                return false;
            }
            m_data.push_back(data);
        }
        return true;
    }
    void Process(){
        for( auto data: m_data){
            if( (data %2) ==0){
                if( data == 2){ // 2 는 소수임. 
                    m_count++;
                    continue;
                }
                // 그외 2로 나누어 떨어지는 수(짝수)
                continue;
            }
            else{
                if( data == 1){//1은 소수가 아님
                    continue;
                }
                if( !isMinority(data)){
                    continue;
                }
                m_count++;
            }
            
        }
    }
    void Print(){
        cout << m_count<< endl;
    }
private:
    vector<int> m_data;
    int m_count=0;

    bool isMinority(int data){
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
};
int main()
{
    CTestCase testCase;
    if(!testCase.InputData()){
        return -1;
    }
    testCase.Process();
    testCase.Print();
    return 0;
}