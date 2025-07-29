#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <random>
#include <type_traits>

using namespace std;
using namespace std::chrono;

namespace UTIL{
    template<typename T>
    bool RangeCheck(T& val, T min, T max){
        if constexpr (std::is_same_v<T, string>){
            int nMin = stoi(min);
            int nMax = stoi(max);
            int nlength = val.length();
            if( (nlength<nMin)||(nlength>nMax)){
                return false;
            }
        }
        else{
            if( (val<min)||(val>max)){
                return false;
            }
        }
        return true;
    }

    bool IsAlpha(const std::string& str){
        for (char ch : str) {
            if (!std::isalpha(static_cast<unsigned char>(ch))) {
                return false;
            }
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

class CSortInSide{
public: 
    bool InputData(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if(!UTIL::Input<int>(m_number, 0, 1'000'000'000)){
            return false;
        }

        return true;
    }
    void Process(){ 
        int data=m_number;
        while( data != 0 ){
            int re = data%10;
            m_data.push_back(re);
            data= data/10;
        }

        sort(m_data.begin(), m_data.end(),greater<>());

    }

    void Print(){
        for(auto data:m_data){
            cout<< data;
        } 
        cout <<endl;
    }

private:
    int m_number;
    vector<int> m_data;
};

int main()
{
    CSortInSide sortInSide;
    if (!sortInSide.InputData()){
        return -1;
    } 
    sortInSide.Process(); 
    sortInSide.Print();
    return 0;
}