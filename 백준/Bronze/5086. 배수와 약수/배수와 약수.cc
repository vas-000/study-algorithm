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
class CData{
public:
    void SetData(int aVal1, int aVal2){
        m_first = aVal1;
        m_second = aVal2;
    }
    void Process(){
        if(calc(m_first, m_second)==true){
            m_ret = "multiple";
        }
        else if(calc(m_second, m_first)==true){
            m_ret = "factor";
        }
        else{
            m_ret = "neither";
        }
    }
    void Print(){
        cout<< m_ret<<endl;
    }
private:
    int m_first;
    int m_second;
    string m_ret;

    bool calc(int first, int second){
        if( (first / second)!= 0){
            if( (first%second) ==0){
                return true;
            }
        }   
        return false;
    }
};
class CFindType{
public:
    bool InputData(){
        int a=0, b=0;
        do{
            cin>> a>>b;
            if(!UTIL::RangeCheck(a, 0, 10000)
            || !UTIL::RangeCheck(b, 0, 10000)){
                return false;
            }
            if( a==0 && b==0){
                break;
            }
            CData data;
            data.SetData(a, b);
            m_datas.push_back(data);

        }while(a!=0 && b!=0);
       return true;
    }

    void Process(){
 //       UTIL::StartTimer();
        for(auto& data:m_datas){
            data.Process();
        }
 //       UTIL::EndTimer();

    }
    void Print(){
        for(auto data:m_datas){
            data.Print();
        }
    }
    
private:
    vector<CData> m_datas;

    
};

int main()
{
    CFindType findType;
    if(!findType.InputData()){
        return -1;
    }
    findType.Process();
    findType.Print();
    return 0;
}