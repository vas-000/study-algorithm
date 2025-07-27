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

class CDictionary{
public: 
    bool InputData(){
        int testCase;
        if(!UTIL::Input<int>(testCase, 1, 1000000)){
            return false;
        }
        int val;
        for(int i=0; i< testCase; ++i){
            string data;
            cin>>data;
            m_inData.insert(data);
        }
    
        return true;
    }
    void Process(){ 
        m_data.insert(m_data.end(),m_inData.begin(),m_inData.end());
        sort(m_data.begin(), m_data.end(), cmp);
    }

    void Print(){
        for(auto data: m_data){
            cout<< data << endl;
        }    
    }
    static bool cmp(string a, string b){
        int length_a = a.length();
        int length_b = b.length();

        if( length_a == length_b){
            for(int i=0; i< length_a; ++i){
                if(a.at(i) == b.at(i))
                    continue;
                else if ((a.at(i)<b.at(i))) {
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        else if( length_a < length_b){
            return true;
        }
        else if( length_a > length_b){
            return false;
        }
        return false;
    }
private:
    unordered_set<string> m_inData;
    vector<string> m_data;
    
};

int main()
{
    CDictionary dictionary;
    if (!dictionary.InputData()){
        return -1;
    } 
    dictionary.Process(); 
    dictionary.Print();
    return 0;
}