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

class CDelivery{
public: 
    bool InputData(){
        if(!UTIL::Input<int>(m_sugar, 3, 5000)){
            return false;
        }
        return true;
    }
    void Process(){ 
        //5의 배수이면 5kg 주머니로 모두 가져감.
        if(multiplies5kg()){
            return;
        }

        int count = m_sugar/m_5kg+1;
        int remaind;
        vector<int> bag;
        for(int i=0; i< count; ++i){
            remaind = m_sugar-(m_5kg*i);
            if( remaind < 0){
                continue;
            }
            if( (remaind % m_3kg) == 0 ){
                int data = (i+ remaind/m_3kg);
                bag.push_back(data);
            }
        }
        if( bag.empty()){
            m_ret = -1;
            return;
        }
        m_ret = *min_element(bag.begin(), bag.end());
    }

    void Print(){
        cout<< m_ret <<endl;
    }
private:
    int m_sugar;
    int m_ret=0;
    const int m_5kg=5, m_3kg=3;

    bool multiplies5kg(){
        if( m_sugar%m_5kg!=0){
            return false;
        }
        m_ret = m_sugar / m_5kg;
        return true;
    }
};

int main()
{
    CDelivery delivery;
    if (!delivery.InputData()){
        return -1;
    } 
    delivery.Process(); 
    delivery.Print();
    return 0;
}