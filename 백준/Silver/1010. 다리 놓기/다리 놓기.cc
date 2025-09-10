#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <unordered_set>
#include <random>
#include <type_traits>
#include <utility>

using namespace std;
using namespace std::chrono;

typedef long long _INT64;
typedef unsigned long long _UINT64;

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

class CQuest{
public:
    bool InputData(){
        int nTestcase;
        cin>>nTestcase;
        for(int i{}; i<nTestcase; ++i){
            int nWest, nEast;
            if(!UTIL::Input(nWest, 0, 30)){
                return false;
            }
            if(!UTIL::Input(nEast, nWest-1, 30)){
                return false;
            }
            m_data.push_back({nWest, nEast});
        }

        return true;
    }
    void Process(){
        for( auto data: m_data){
        // nCr -> n!/((n-r)!*r!)
            int nEast= data.second;
            int nWest = data.first;
            int nDiff = nEast-nWest;
            //double total= nFactorial(nEast)/(nFactorial(nEast-nWest)* nFactorial(nWest));
            double total;
            if(nDiff > nWest){
                total = nFactorial(nEast, nDiff);
                total/=nFactorial(nWest);
            }
            else{
                total = nFactorial(nEast, nWest);
                total/=nFactorial(nDiff);
            }
            m_total.push_back(total);
        }

    }
    void Print(){
        for(auto data: m_total)
            cout<<data<<'\n';
    }
private:
    vector<_UINT64> m_total;
    vector<pair<int, int>> m_data;
    int m_nWest, m_nEast;  
    
    double nFactorial(int n, int last=0){
        if(n==last){
            return 1;
        }
        return n*nFactorial(n-1, last);
    }
   
};

int main()
{
    //UTIL::StartTimer();
    ios::sync_with_stdio(false);
    cin.tie(0);

    CQuest quest;
    if (!quest.InputData()){
        return -1;
    } 
    quest.Process(); 
    quest.Print();
    //UTIL::EndTimer();
    
    return 0;
}