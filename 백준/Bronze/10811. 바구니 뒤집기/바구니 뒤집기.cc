#include <iostream>
#include <vector>
#include <map>

using namespace std;
class CBasket
{
private:
    int m_id;
    int m_ballNum=0;
public:
    void PushBall(int number){
        m_ballNum=number;
    }
    int GetBall(){
        return m_ballNum;
    }
    void Print(){
        cout<<m_ballNum;
    }
};

typedef struct ST_DATA{
    int from;
    int to;
}st_Data;

class CBasketBall
{
private:
    int nPushCount, nBasketCount;
    map<int, CBasket> m_baskets;
    vector<st_Data> m_Act;
    bool rangeCheck(int& val, int min, int max){
        if( (val<min)||(val>max)){
            return false;
        }
        return true;
    }
    bool input(int& val, int min, int max){
        cin>>val;
        return rangeCheck(val, min, max);
    }
    void createBasket(){
        for(int i=1; i<=nBasketCount; ++i){
            CBasket basket;
            basket.PushBall(i);
            m_baskets[i]=basket;
        }
    }
    void reverse(int start, int end){
        if( start >= end ){
            return;
        }
        CBasket temp = m_baskets[start];
        m_baskets[start]=m_baskets[end];
        m_baskets[end]= temp;  
        reverse(start+1, end-1);          
    }
public:
    bool InputData(){
        cin >> nBasketCount >> nPushCount;
        if( !rangeCheck(nBasketCount, 1, 100)||
            !rangeCheck(nPushCount, 1, 100)){
                return false;
        }
        
        int i, j;
        for( int cnt=0; cnt< nPushCount; ++cnt){
            cin >> i>>j;
            if( !rangeCheck(i, 1, j)||
                !rangeCheck(j, 1, nBasketCount)){
                return false;
            }
            st_Data data;
            data.from=i;
            data.to=j;
            m_Act.push_back(data);
        }
        return true;
    }

    void Process(){
        createBasket();

        for( auto act:m_Act){
            reverse(act.from, act.to);
        }
    }
    void Print(){
        for(auto basket:m_baskets){
            basket.second.Print();
            cout<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    CBasketBall basketball;
    if(!basketball.InputData()){
        return -1;
    }
    basketball.Process();
    basketball.Print();
    return 0;
}