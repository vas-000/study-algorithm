#include <cctype>
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>

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

class CBaseTransfomation{
public:
    CBaseTransfomation(){
        for(int i=0; i<36; ++i){
            if(i<10){
                m_data[i]=i+'0';
            }
            else{
                m_data[i]='A'+i-10;
            }
        }
    }
    bool InputData(){
        cin>>m_number>>m_base;
        if( !UTIL::RangeCheck(m_base, 1, 37)){
            return false;
        }
       return true;
    }

    void Process(){
        transfomation(m_number);
        reverse(m_total.begin(), m_total.end());
    }
    void Print(){
        cout<<m_total<<endl;
    }
    
private:
    int m_base;
    string m_total;
    int m_number;
    map<int, char> m_data;

    void transfomation(int val){
        if(val==0){
            return;
        }
        int tmp=val%m_base;
        m_total.push_back(m_data[tmp]);
        transfomation(val/m_base);
    }
};

int main()
{
    CBaseTransfomation base;
    if(!base.InputData()){
        return -1;
    }
    base.Process();
    base.Print();
    return 0;
}