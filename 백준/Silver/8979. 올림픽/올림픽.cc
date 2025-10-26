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

typedef struct ST_MEDAL{
    int gold;
    int silver;
    int bronze;
    bool isSame(ST_MEDAL other){
        if( gold != other.gold)
            return false;
        if( silver != other.silver)
            return false;
        if( bronze != other.bronze)
            return false;
        return true;
    }
}stMedal;

class CNation{
private:
    int code;
    stMedal m_medal;
    int ranking;
public:
    CNation(int aC, int aG, int aS, int aB)
    :code(aC){
        m_medal.gold=aG;
        m_medal.silver=aS;
        m_medal.bronze=aB;
    }
    stMedal GetMedal() {return m_medal;}
    int GetCode(){return code;}
    int GetRank(){return ranking;}
    void SetRanking(int rank){
        ranking = rank;
    }

};
class CQuest{
public:
    bool InputData(){
        
        if(!UTIL::Input(m_count, 1, 1'000))
            return false;

        if(!UTIL::Input(m_nation, 1, m_count))
            return false;

        int totalMedal=0;
        for(int i{}; i< m_count; ++i){
            //전체 메달의 수는 1'000'000 이하 이다.
            int code, gold, silver, bronze;
            if(!UTIL::Input(code, 1, 1'000)){
                return false;
            }

            if(!UTIL::Input(gold, 0, 1'000'000)){
                return false;
            }

            if(!UTIL::Input(silver, 0, 1'000'000)){
                return false;
            }

            if(!UTIL::Input(bronze, 0, 1'000'000)){
                return false;
            }

    
            totalMedal = totalMedal+gold+silver+bronze;
            if( totalMedal > 1'000'000){
                return false;
            }

            CNation nation(code, gold, silver, bronze);
            m_data.push_back(nation);
        }
    
        return true;
    }
    void Process(){
        // 금, 은, 동 순으로 나라를 정렬한다. 
        sort(m_data.begin(), m_data.end(), []( CNation& first, CNation& second){
           stMedal nation1 = first.GetMedal();
           stMedal nation2 = second.GetMedal();
           if( nation1.gold < nation2.gold){
                return false;
           }
           else if( nation1.gold == nation2.gold){
                if(nation1.silver < nation2.silver){
                    return false;
                }
                else if( nation1.silver == nation2.silver){
                    if( nation1.bronze < nation2. bronze){
                        return false;
                    }
                }
           }
           return true;
        });

        //정렬된 나라순으로 Ranking을 계산한다. 
        int ranking=1;
        int inc=0;
        stMedal pre = m_data.begin()->GetMedal();
        for(auto &nation: m_data){
            stMedal cur = nation.GetMedal();
            if(!pre.isSame(cur)){
                ranking=ranking+inc;
                inc=0;
                pre=cur;    
            }
            nation.SetRanking(ranking);
            inc++;
        }

    } 
    void Print(){
        for(auto nation: m_data){
            if( nation.GetCode()==m_nation){
                cout<< nation.GetRank()<<"\n";
                return;
            }
        }
    }
private:
    int m_count=0;
    int m_nation=0;
    vector<CNation> m_data;
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