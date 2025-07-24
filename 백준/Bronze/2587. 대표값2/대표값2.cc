#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

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

class CRepresentativeValue{
public: 
    bool InputData(){
        const int testCase=5;
        int val;
        for(int i=0; i< testCase; ++i){
            if( !UTIL::Input<int>(val, 0, 100)){
                return false;
            }
            if( val %10 != 0){
                // 입력된 수는 10의 배수이다.
                return false;
            }
            m_data.push_back(val);
        }
        return true;
    }
    void Process(){ 
        m_average = average();
        sort(m_data.begin(), m_data.end());
        m_center = m_data.at(2);
    }

    void Print(){
        cout<< m_average<<endl;
        cout<< m_center<<endl;
    }
private:
    vector<int> m_data;
    int m_average;
    int m_center;
    int average(){
        int sum=0;
        //for(auto data: m_data){
        //    sum+=data;
        //}
        sum = accumulate(m_data.begin(), m_data.end(), 0);
        return sum/m_data.size();
    }
};

int main()
{
    CRepresentativeValue representativeValue;
    if (!representativeValue.InputData()){
        return -1;
    } 
    representativeValue.Process(); 
    representativeValue.Print();
    return 0;
}