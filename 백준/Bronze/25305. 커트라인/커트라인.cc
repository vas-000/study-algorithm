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
#include <functional>

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

class CCutLine{
public: 
    bool InputData(){
        if( !UTIL::Input<int>(m_candidate, 1, 1000)){
            return false;
        }

        if( !UTIL::Input<int>(m_winner, 1, m_candidate)){
            return false;
        }

        int val;
        for(int i=0; i< m_candidate; ++i){
            if( !UTIL::Input<int>(val, 0, 10000)){
                return false;
            }
            m_data.push_back(val);
        }
        return true;
    }
    void Process(){ 
        sort(m_data.begin(), m_data.end(), greater<int>()); // 내림 차순 정렬
        // 동점자는 어떻게 처리되나?
        m_cutline = m_data.at(m_winner-1);
    }

    void Print(){
        cout<< m_cutline << endl;
    }
private:
    vector<int> m_data;
    int m_candidate;
    int m_winner;
    int m_cutline;
};

int main()
{
    CCutLine cutline;
    if (!cutline.InputData()){
        return -1;
    } 
    cutline.Process(); 
    cutline.Print();
    return 0;
}