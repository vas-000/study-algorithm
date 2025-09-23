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
#include <unordered_map>
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
        if(!UTIL::Input(count, 1, 100'000)){
            return false;
        }
        int nLength;
        if(!UTIL::Input(nLength, 1, 10)){
            return false;
        }
        
        for(int i{}; i< count; ++i){
            string word;
            if(!UTIL::Input<string>(word, "1", "10")){
                return false;
            }
            int len = word.length();
            if(len < nLength){
                continue;
            }

            m_cntByWord[word]++;
        }
       
        return true;
    }
    void Process(){
        for(auto iter: m_cntByWord){
            m_wordByCnt[iter.second].push_back(iter.first);
        }

        for(auto &iter: m_wordByCnt){
            if(iter.second.size()==1){
                continue;
            }
            auto &strList = iter.second;
            //문자의 길이가 긴것을 앞쪽에 오도록 정렬한다. 
            sort(strList.begin(), strList.end(), [](string& a, string& b){
                int aLen = a.size();
                int bLen = b.size();
                if(aLen > bLen){
                    return true;
                }
                else if(aLen==bLen){
                    if(a < b){
                        return true;
                    }
                }
                return false;
            });

        }

        
    }
    void Print(){
        for(auto iter=m_wordByCnt.rbegin(); iter!=m_wordByCnt.rend(); iter++){
            auto &strList = iter->second;
            for(auto str: strList){
                cout << str<<"\n";
            }
        }
    }
private:
    map<string, int> m_cntByWord;
    map<int, vector<string>> m_wordByCnt;
    vector<string> m_result;
    
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