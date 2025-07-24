#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <map>
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

class CSorting{
public: 
    bool InputData(){
        int testCase;
        if(!UTIL::Input<int>(testCase, 1, 1000)){
            return false;
        }
        int val;
        for(int i=0; i< testCase; ++i){
            if( !UTIL::Input<int>(val, -1000, 1000)){
                return false;
            }
            m_data.push_back(val);
        }
        return true;
    }
    void Process(){ 
        sort(m_data.begin(), m_data.end());
    }

    void Print(){
        for(auto data: m_data){
            cout<< data << endl;
        }    
    }
private:
    vector<int> m_data;
    
};

int main()
{
    CSorting sorting;
    if (!sorting.InputData()){
        return -1;
    } 
    sorting.Process(); 
    sorting.Print();
    return 0;
}