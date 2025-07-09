#include <cctype>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

namespace UTIL{
    bool RangeCheck(int& val, int min, int max){
        if( (val<min)||(val>max)){
            return false;
        }
        return true;
    }

    bool Input(int& val, int min, int max){
        cin>>val;
        return RangeCheck(val, min, max);
    }
}
class CHexagon
{
private:
    int m_layer;
    int m_min;
    int m_max;
public:
    void SetLayer(int layer, int preLast){
        m_layer=layer;
        m_min=preLast+1;
    }
    void CalcAssignId(){
        int side = m_layer*2-1;
        int left = m_layer-2;
        if( left<0){
            left=0;
        }
        if( m_min == 1){
            m_max=m_min;
        }
        else{
            m_max = m_min + side*2 + left*2-1;
        }
    }
    int GetLastId(){
        return m_max;
    }
    bool IsAssign(int id){
        if( (m_min<=id) && (id <= m_max)){
            return true;
        }
        return false;
    }
    int GetLayerNum(){
        return m_layer;
    }
};
class CHoneycomb{
public:
    bool InputData(){
        if(!UTIL::Input(m_findId, 1, m_totalHoneyComb)){
            return false;
        }
       return true;
    }

    void Process(){
        createHoneyComb();
        for(auto honeycomb:m_honeyComb){
            if(honeycomb.IsAssign(m_findId)==true){
                m_step = honeycomb.GetLayerNum();
                return;
            }
        }
    }
    void Print(){
        cout<<m_step<<endl;
    }
    
private:
    const int m_totalHoneyComb=1000000000;
    int m_findId;
    int m_step=0;
    vector<CHexagon> m_honeyComb;
    void create(int layer, int last){
        if( last > m_totalHoneyComb){
            return;
        }
        CHexagon hexagon;
        hexagon.SetLayer(layer, last);
        hexagon.CalcAssignId();
        m_honeyComb.push_back(hexagon);
        create(layer+1, hexagon.GetLastId());
    }
    void createHoneyComb(){
        create(1, 0);
    }
};

int main()
{
    CHoneycomb honeycomb;
    if(!honeycomb.InputData()){
        return -1;
    }
    honeycomb.Process();
    honeycomb.Print();
    return 0;
}