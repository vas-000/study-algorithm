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
        int count;
        if(!UTIL::Input(count, 1, 500'000)){
            return false;
        }
        if( count%2 == 0){
            return false;
        }

        // 정수
        for(int i{}; i< count; ++i){
            int num;
            if(!UTIL::Input(num, -4000, 4000)){
                return false;
            }
            m_data.push_back(num);
        }
       
        return true;
    }
    void Process(){
        //평균값
        getAverage();
        getCenter();
        getFrequentValue();
        getValueRange();

    }
    void Print(){
        for(auto res: m_result){
            cout<< res << '\n';
        }
    }
private:
    vector<int> m_result;
    vector<int> m_data;
   
    void getAverage(){
        int sum=0;
        for(int i:m_data){
            sum+=i;
        }
        int nSize=m_data.size();
        float calc= ((float)sum)/nSize;

        sum = round(calc);
 
        m_result.push_back(sum);
    }

    void getCenter(){
        sort(m_data.begin(), m_data.end());
        int nCenterId = m_data.size()/2;
        m_result.push_back(m_data.at(nCenterId));
    }

    void getFrequentValue(){
        map<int, int> frequent;
        for(const int& i:m_data){
            frequent[i]++;
        }

        // 최빈값이 여러개 존재할때 두번째 작은 값을 출력한다. 
        int nMax=0;
        set<int> valList;
        for(auto data: frequent){
            if(nMax < data.second){
                nMax = data.second;
                valList.clear();
                valList.insert(data.first);
            }
            else if(nMax == data.second){
                valList.insert(data.first);
            }
        }

        auto iter = valList.begin();
        if(valList.size()>1){    
            iter++;
            m_result.push_back(*iter);
        }
        else{
            m_result.push_back(*iter);
        }
    }

    void getValueRange(){
        int nMin = m_data.at(0);
        int nMax = m_data.at(m_data.size()-1);
        int nRange = nMax - nMin;
        m_result.push_back(nRange);
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