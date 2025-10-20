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
        for(int i{};i<5; i++){
            char color;
            cin>>color;

            if(defColors.find(color)==string::npos){
                cout<<"-----"<<endl;
                return false;
            }
            int nVal;
            if(!UTIL::Input(nVal, 1, 9))
                return false;

            m_data[color].insert(nVal);
        }
        return true;
    }
    void Process(){
        // 색깔과 숫자순으로 정렬되어 있음. 
        // 1. 카드 5장이 모두 같은색 && 숫자가 연속 => 가장높은수 +900
        // 2. 4장의 숫자가 같을 때 => 같은 숫자 + 800
        // 3. 3장의 숫자가 같고 && 나머지 2장의 숫자가 같을때 => (3장 숫자* 10 + 2장 숫자)+700
        // 4. 카드의 색상이 모두 같을때 => 가장 높은숫자 +600
        // 5. 숫자가 연속적일 때 => 가장 높은 숫자 +500
        // 6. 3장의 숫자가 같을때 => 3장 숫자 +400
        // 7. 2장의 숫자가 같고 && 다른 2장의 숫자가 같을때 => (같은 숫자 중 큰수*10 + 작은수 ) +300
        // 8. 2장의 숫자가 같을때 => 같은 숫자 + 200
        // 9. 위 어떤 경우도 해당 하지 않을 때 => 가장 큰수 +100
        //---------------------------------------------------------------------------------------       
        if( m_data.size()==1){
            // 모든 색상이 같은 경우 : 1, 4
            sameColor();
            return;
        }

        map<int, int> mapDeck; // Number, count;
        for(auto data: m_data){
            auto numbers= data.second;
            for(auto iter:numbers){
                mapDeck[iter]++;
            }
        }

        if( same4Card(mapDeck)){
            return;
        }
        
        if( same3Card(mapDeck)){
            return;
        }

        if( same2Card(mapDeck)){
            return;
        }

        if( isContinue(mapDeck) ){
            return;
        }

        // 9. 위 어떤 경우도 해당 하지 않을 때 => 가장 큰수 +100
        m_ret = mapDeck.rbegin()->first+m_mapScore.at(9);
    } 
    void Print(){
        cout << m_ret <<'\n';
    }
private:
    const map<int, int> m_mapScore={{1, 900}, {2,800}, {3,700}, {4, 600},
                                    {5, 500}, {6, 400}, {7, 300}, {8, 200}, {9, 100}};
    const string defColors="RBYG";
    map<char, set<int>> m_data;
    int m_number;
    int m_ret =0;

    void sameColor(){
        // Same Color
        auto deck = m_data.begin()->second;
        auto iter = deck.begin();
        int nCur=*iter;
        bool bContinue=true;
        for( auto iter=deck.begin(); iter != deck.end(); ++iter){
            if( nCur != *iter){
                bContinue = false;
                break;
            } 
            nCur++;
        }
        if( bContinue){
            // 1. 카드 5장이 모두 같은색 && 숫자가 연속 => 가장높은수 +900
            m_ret = *deck.rbegin() + m_mapScore.at(1); 
        }
        else{
            // 4. 카드의 색상이 모두 같을때 => 가장 높은숫자 +600
            m_ret = *deck.rbegin() + m_mapScore.at(4);
        }
    }

    bool same4Card( map<int, int>& deck){
        auto it = find_if(deck.begin(), deck.end(), [](const auto& data){ return data.second == 4;});
        if(it != deck.end()){
            // 2. 4장의 숫자가 같을 때 => 같은 숫자 + 800
            m_ret = it->first +m_mapScore.at(2);
            return true;
        }
        return false;
    }

    bool same3Card(map<int, int>& deck){
        auto it = find_if(deck.begin(), deck.end(), [](const auto& data){ return data.second == 3;});
        if( it == deck.end()){
            return false;
        }

        if( deck.size()==2){
            // 3. 3장의 숫자가 같고 && 나머지 2장의 숫자가 같을때 => (3장 숫자* 10 + 2장 숫자)+700    
            m_ret=0;
            for(auto const&[num, count]: deck){
                if( count == 2){
                    m_ret = m_ret + num;
                }
                else if( count == 3){
                    m_ret = m_ret + num*10;
                }
            }
            m_ret=m_ret+m_mapScore.at(3);
            return true;
        }
        else{
            // 6. 3장의 숫자가 같을때 => 3장 숫자 +400
            m_ret = it->first+m_mapScore.at(6);
            return true;
        }
        return false;
    }

    bool same2Card(map<int, int>& deck){
        auto it = find_if(deck.begin(), deck.end(), [](const auto& data){ return data.second == 2;});
        if( it == deck.end()){
            return false;
        }

        if( deck.size()==3){
            // 7. 2장의 숫자가 같고 && 다른 2장의 숫자가 같을때 => (같은 숫자 중 큰수*10 + 작은수 ) +300
            m_ret=0;
            int big=0, small=10;
            for(auto const&[num, count]: deck){
                if( count == 2){
                    if( big < num){
                        big=num;
                    }        
                    if( small > num){
                        small=num;
                    }
                }
            }

            m_ret = big*10 + small + m_mapScore.at(7);
        }
        else{
            // 8. 2장의 숫자가 같을때 => 같은 숫자 + 200
            m_ret = it->first+m_mapScore.at(8);
        }
        return true;
    }
    bool isContinue(map<int, int>& deck){
        // 5. 숫자가 연속적일 때 => 가장 높은 숫자 +500
        auto it = deck.begin();
        int start= it->first;
        it++;
        while( it != deck.end()){
            if(start+1 ==it->first){
                start = it->first;
                it++;
                continue;
            }
            return false;
        }
        m_ret = deck.rbegin()->first+m_mapScore.at(5);
        return true;
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