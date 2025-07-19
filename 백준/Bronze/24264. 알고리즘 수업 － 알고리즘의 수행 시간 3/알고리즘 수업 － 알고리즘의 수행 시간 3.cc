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

class CAlgorithmTime{
public: 
    bool InputData(){
        if(!UTIL::Input<int>(m_number, 0, 500000)){
            return false;
        }
        return true;
    }
    void Process(){
        menOfPassion(m_number); 
    }
    void Print(){
        cout<< m_count<<endl;
        cout<<"2"<<endl; // 다항식은 n * n = n^2
    }

private:
    int m_number;
    int64_t m_count=0;

    int menOfPassion(int n ){
        int sum=0;
        /*
        // 이중 for문 이므로 실행횟수는 
        // n * n 입
        for(int i=0; i<n; ++i){
            for(int j=0; j<n ++j)
                sum =sum+ A[i]*A[j] //#코드1
        }
        */
         m_count= (int64_t)n * (int64_t)n; //코드1의 수행횟수 
        return sum;
    }
};

int main()
{
    CAlgorithmTime algorithmTime;
    if (!algorithmTime.InputData()){
        return -1;
    } 
    algorithmTime.Process(); 
    algorithmTime.Print();
    return 0;
}