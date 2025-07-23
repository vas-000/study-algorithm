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

class CMovieName{
public: 
    bool InputData(){
        if(!UTIL::Input<int>(m_count, 0, 10000)){
            return false;
        }
        return true;
    }
    void Process(){ 
        // 666, 1666, 2666, 3666,4666, 5666, 6666, 7666, 8666, 9666,10666, 11666,
        // 12666, 13666,14666,15666,16660,16661, 16662,...
        for(int i=0; i< 10000000; ++i){
            //문자열로 변경한 다음 "666" 문자가 있는지 확인 한다.
            string a = to_string(i);
            if( a.find(defaultName)==string::npos){
                continue;
            }

            m_count--;
            if(m_count==0){
                m_ret = i;
                return;
            }
        }

    }
    void Print(){
        cout<< m_ret <<endl;
    }
private:
    int m_count;
    int m_ret=-1;
    string defaultName = "666";
};

int main()
{
    CMovieName movieName;
    if (!movieName.InputData()){
        return -1;
    } 
    movieName.Process(); 
    movieName.Print();
    return 0;
}