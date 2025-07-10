#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <vector>

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

class CSnail{
public:
    bool InputData(){
        cin>>m_day>>m_night>>m_tree;
        if(!UTIL::RangeCheck(m_night, 1, m_day)
        ||!UTIL::RangeCheck(m_day, m_night, m_tree)
        ||!UTIL::RangeCheck(m_tree, m_day, 1000000001)){
            return false;
        }
       return true;
    }

    void Process(){
 //       UTIL::StartTimer();
        int diff = m_day-m_night;
        m_date = ((m_tree-m_day)/diff);
        if( (m_tree-m_day) %diff!=0){
            m_date+=2;
        }
        else{
            m_date+=1;
        }
 //       UTIL::EndTimer();

    }
    void Print(){
        cout<< m_date <<endl;
    }
    
private:
    const int m_total=1000000000;
    int m_day=0, m_night=0, m_tree=0;
    int m_climb=0, m_date=0; 

    bool climb(int& date){
        m_date=0;
        for(;;){
            m_date++;
            m_climb+=m_day;
            if(m_climb>=m_tree){
                break;
            }
            m_climb-=m_night;
        }
        return true;
    }
    
};

int main()
{
    CSnail snail;
    if(!snail.InputData()){
        return -1;
    }
    snail.Process();
    snail.Print();
    return 0;
}