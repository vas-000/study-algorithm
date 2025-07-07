#include <cctype>
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

#pragma pack(push, 1)
typedef struct ST_CHANGE{
    int quarter;
    int dime;
    int nickel;
    int penny;
}stChange;

class CCalcChange{
public:
    bool InputData(){
        cin>> m_case;
        
        for(int i=0; i<m_case; ++i){
            int data;
            if(!UTIL::Input(data, 0, 501)){
                return false;
            }
            m_change.push_back(data);
        }
        m_pChange = new int[m_case*4];
        //for( int i=0; i<500; ++i){
        //    m_change.push_back(i+1);
        //}
        //m_case = 500;
        //m_pChange=new int[500*4];
       return true;
    }

    void Process(){
        int *pIdx = m_pChange;
        for(auto data: m_change){
            //stChange change;
            //int tmp=calc(data, 25, change.quarter);
            //tmp=calc(tmp, 10, change.dime);
            //tmp=calc(tmp, 5, change.nickel);
            //calc(tmp,1, change.penny );
            //m_data.push_back(change);
            int tmp=data;
            for(int i=0; i<4; ++i){
                tmp=calc(tmp, m_unit[i], (pIdx+i));
            }
            pIdx+=4;
        }     
    }
    void Print(){
        //for(auto data: m_data){
        //    cout<< data.quarter<<" "<< data.dime<<" "<< data.nickel<<" "<< data.penny<<endl;
        //}
        stChange* pSt = reinterpret_cast<stChange*>(m_pChange);
        for(int i=0; i<m_case; ++i){
            cout<< pSt->quarter<<" "<< pSt->dime<<" "<< pSt->nickel<<" "<< pSt->penny<<endl;
            pSt+=1;
        }
        delete []m_pChange;
        m_pChange=nullptr;
    }
    
private:
    int m_case;
    int *m_pChange=nullptr;
    const int m_unit[4]={25, 10, 5, 1};
    vector<int> m_change;

    vector<stChange> m_data;

    int calc(int money, int type, int& cnt){
        cnt=money/type;
        return money%type;
    }
    
    int calc(int money, int type, int* cnt){
        *cnt=money/type;
        return money%type;
    }
};

int main()
{
    CCalcChange change;
    if(!change.InputData()){
        return -1;
    }
    change.Process();
    change.Print();
    return 0;
}