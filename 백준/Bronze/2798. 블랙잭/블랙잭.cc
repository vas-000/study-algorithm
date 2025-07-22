#include <cctype>
#include <cstdio>
#include <chrono>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

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

class CGame{
public: 
    bool InputData(){
        if(!UTIL::Input<int>(m_cardCount, 3, 100)){
            return false;
        }
        if(!UTIL::Input<int>(m_targetValue, 10, 300000)){
            return false;
        }
        if(!getCard(m_cardCount)){
            return false;
        }
        return true;
    }
    void Process(){
        //m_targetValue을 넘지 않으면서 m_targetValue에 최대한 가까운 카드3장의 합
        vector<int> sums;
        for(int i=0; i<m_cardCount; ++i){
            for(int j=i+1, x=0; x<m_cardCount-(i+1); ++j,++x){
                for(int k=j+1,y=0;y<m_cardCount-(j+1);++k,++y){
                    int data=m_card[i]+m_card[j]+m_card[k];
                    //cout<< data<< ": "<<m_card[i]<<", "<<m_card[j]<<", "<<m_card[k]<<endl;
                    sums.push_back(data);
                }
            }
        }

        m_cardSum = findCloseNumber(sums);
    }
    void Print(){
        cout<< m_cardSum <<endl;
    }
private:
    int m_cardCount=0;
    int m_targetValue=0;
    int m_cardSum=0;
    vector<int> m_card;

    bool getCard(int count){
        for(int i=0; i< count; ++i){
            int data;
            if(!UTIL::Input<int>(data, 0, 100000)){
                return false;
            }
            m_card.push_back(data);
        }
        return true;
    }

    int findCloseNumber(vector<int>& numbers){
        int diff=m_targetValue, closeNumber;
        for(auto data:numbers){
            int calc= m_targetValue-data;
            if(calc < 0){
                //세수의 합이 m_targetValue 값과 같거나 작아야 한다. 
                continue;
            }
            if(calc<diff){
                closeNumber=data;
                diff = calc;
            }
        }
        return closeNumber;
    }
};

int main()
{
    CGame game;
    if (!game.InputData()){
        return -1;
    } 
    game.Process(); 
    game.Print();
    return 0;
}