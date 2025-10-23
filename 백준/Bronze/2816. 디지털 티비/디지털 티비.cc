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
        int nCnt=0;
        if(!UTIL::Input(nCnt, 2, 100))
            return false;

        for(int i{}; i< nCnt; ++i){
            string name;
            if(!UTIL::Input<string>(name, "0", "10")){
                return false;
            }
            m_data.push_back(name);
        }
        return true;
    }
    void Process(){
        // 1: 화살표를 한 칸 아래로 내린다. 
        // 2: 화살표를 위로 한칸 올린다. 
        // 3: 선택한 채널을 한 칸 아래로 내린다. 
        // 4: 선택한 채널을 한칸 올린다. 
        
        // KBS1 또는 KBS2의 위치를 찾는다. 
        m_cursor = m_data.begin();
        int Idx=0;
        auto data = findCh("KBS1", m_cursor, Idx);
        moveDownPrint(0,Idx);
        moveCh(data, Idx*-1);

        m_data.pop_front();
        moveDownPrint(0,1);
        m_cursor= m_data.begin();

        data = findCh("KBS2", m_cursor, Idx);
        moveDownPrint(0,Idx);
        moveCh(data, Idx*-1);

    } 
    void Print(){
        cout<<m_move<<'\n';
    }
private:
    list<string> m_data;
    list<string>::iterator m_cursor;
    string m_move;

    void moveDownPrint(int type, int aMove){
        for(int i{}; i< aMove; ++i){
            if( type ==0){
                m_move.append("1");
                m_cursor++;
            }
            else if( type == 1)
                m_move.append("3");
            
        }
    }

    void moveUpPrint(int type, int aMove){
        for(int i{}; i< aMove; ++i){
            if( type == 0 ){
                m_move.append("2");
                m_cursor--;
            }
            else if( type == 1)
                m_move.append("4");
            
        }
    }

    void moveCh(list<string>::iterator aSel, int aMove){
        auto target = aSel;
        advance(target, aMove);
        m_data.splice(target, m_data, aSel);
        m_cursor = aSel;
        if(aMove>0){
            moveDownPrint(1, aMove);
        }
        else{
            moveUpPrint(1, abs(aMove));
        }
    }

    list<string>::iterator findCh(string aCH, list<string>::iterator curCursor, int& idx){
        auto data = find(m_data.begin(), m_data.end(), aCH);
        idx = distance(curCursor, data);
        return data;
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