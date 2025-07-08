#include <cctype>
#include <iostream>
#include <cmath>

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

class CMoveCenter{
public:
    bool InputData(){
        if(!UTIL::Input(m_count, 0, 16)){
            return false;
        }
       return true;
    }

    void Process(){
        int row = pow(2,m_count)+1;
        m_total = row*row;     
    }
    void Print(){
        cout<<m_total<<endl;
    }
    
private:
    int m_count;
    int m_total;
};

int main()
{
    CMoveCenter center;
    if(!center.InputData()){
        return -1;
    }
    center.Process();
    center.Print();
    return 0;
}