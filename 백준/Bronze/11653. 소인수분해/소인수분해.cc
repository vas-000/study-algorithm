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

class CPrimeFactorization{
public: 
    bool InputData(){
        if(!UTIL::Input(m_number, 0, 10000000)){
            return false;
        }
        return true;
    }
    void Process(){
       factorization(m_number);
    }
    void Print(){
        for(auto data:m_data){
            cout<<data<<endl;
        }
    }
private:
    vector<int> m_data;
    int m_number;

    void factorization(int data){
        int mod;
        for(mod=2;mod<data;++mod){
            if((data%mod)==0){
                break;
            }
        }
        if(data>=mod){
            m_data.push_back(mod);
            factorization(data/mod);
        }
        else
            return;
    } 
};
int main()
{
    CPrimeFactorization primeFactorization;
    if(!primeFactorization.InputData()){
        return -1;
    }
    primeFactorization.Process();
    primeFactorization.Print();
    return 0;
}