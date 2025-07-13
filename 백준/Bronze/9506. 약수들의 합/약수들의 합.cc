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

class CFactor{
public:
   void SetData(int data){
        m_number =data;
   }

    void Process(){
 //       UTIL::StartTimer();
        getFactor(1);

 //       UTIL::EndTimer();
        for(auto data: m_factors){
            m_sum+=data;
        }
    }
    void Print(){
        if( m_number == m_sum){
            printFactor();
        }
        else{
            cout<< m_number<<" is NOT perfect."<<endl;
        }
    }
    
private:
    vector<int> m_factors;
    int m_number;
    int m_sum=0;
    void getFactor(int aDiv){
        if( m_number == aDiv){
            return;
        }
        if((m_number % aDiv) == 0){
            m_factors.push_back(aDiv);
        }
        aDiv+=1;
        getFactor(aDiv);
    }
    void printFactor(){
        cout << m_number<<" = ";
        for( int i=0; i< m_factors.size(); ++i){
            cout<< m_factors.at(i);
            if( (i+1) != m_factors.size())
                cout<< " + ";
            else
             cout<< endl;
        }
    }
};

class CTestCase{
public: 
    bool InputData(){
        while(true){
            int m_value; 
            if(!UTIL::Input(m_value, 2, 100000)){
                if( m_value==-1){
                    break;
                }
                return false;
            }

            CFactor factor;
            factor.SetData(m_value);
            m_data.push_back(factor);
        }
        return true;
    }
    void Process(){
        for(auto& factor: m_data){
            factor.Process();
        }
    }
    void Print(){
        for(auto factor: m_data){
            factor.Print();
        }
    }
private:
    vector<CFactor> m_data;
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