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
        if(!UTIL::Input(m_nBalloon, 1, 1'000)){
            return false;
        }

        for(int i{1}; i<= m_nBalloon; ++i){
            int move;
            if(!UTIL::Input(move, m_nBalloon*-1, m_nBalloon)){
                return false;
            }
            if(move == 0){
                return false;
            }
            m_data.push_back({i,move});
        }
        return true;
    }
    void Process(){
        //cout<< "start Process"<<endl;
        auto iter=m_data.end();
        while(m_result.size()!=m_nBalloon){
            if(iter == m_data.end()){
                iter=m_data.begin();
                continue;
            }

            m_result.push_back(iter->first);
            int mov = iter->second;
            auto delIter = iter;

            if(m_data.size()==1){
                break;
            }
            //회전
            moveIter(iter, delIter, mov);
            m_data.erase(delIter);
        }


    }
    void Print(){
        for(auto res: m_result){
            cout<< res << ' ';
        }
        cout<<'\n';
    }
private:
    vector<int> m_result;
    list<pair<int, int>> m_data;
    int m_nBalloon;
    void moveForward(list<pair<int,int>>::iterator& idx){
        idx++;
        if(idx==m_data.end()){
            idx=m_data.begin();
        }
    }
    void moveBackward(list<pair<int,int>>::iterator& idx){
        idx--;
        if(idx==m_data.end()){
            idx=prev(m_data.end());
        }
    }
    void moveIter(list<pair<int,int>>::iterator& idx, list<pair<int,int>>::iterator& del, int move){
        int init, dest;
        if(move >0){
            init=0;
            dest=move;
        }
        else{
            init=move;
            dest=0;
        }

        for(int i{init};i<dest; ++i){
            if(move>0){
                moveForward(idx);
            }
            else{
                moveBackward(idx);
            }

            if(del == idx){
                --i;
            }
        }
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