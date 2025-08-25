#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
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
        while(true){
            string data;
            getline(cin, data, '.');
            if(data.empty()){
                break;
            }
            if( data.length()>=100){
                //"." 포함 100글자 인지 모르겠네..ㅋㅋ
                cout<<"dddd"<<endl;
                return false;
            }
            m_data.push_back(data);
            cin.ignore();
        }
        return true;
    }
    void Process(){
        //cout<< "start Process"<<endl;
        for(auto data: m_data){
            vector<char> store;
            for(int i{};i< data.length(); ++i){
                char ch = data.at(i);
                if( ch=='(' || ch =='['){
                    store.push_back(ch);
                }
                else if(ch == ')'){
                    if(pop(store, '(')){
                        continue;
                    }
                    store.push_back(ch);
                }
                else if(ch ==']'){
                    if(pop(store, '[')){
                        continue;
                    }
                    store.push_back(ch);
                }

            }

            if( store.empty()){
                m_result.push_back("yes");
            }
            else {
                m_result.push_back("no");
            }
        }
    }
    void Print(){
        for(auto data:m_result){
            cout<< data<<'\n';
        }
        
    }
private:
    vector<string> m_data;
    vector<string> m_result;
    
    bool pop(vector<char>& store, char ch){
        if(store.empty()){
            return false;
        }
        if(store.back()==ch){
            store.pop_back();
            return true;
        }
        return false;
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