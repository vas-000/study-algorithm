#include <cctype>
#include <iostream>
#include <map>
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

class CBaseTransfomation{
public:
    CBaseTransfomation(){
        for(int i=0; i<36; ++i){
            if(i<10){
                m_data['0'+i]=i;
            }
            else{
                m_data['A'+i-10]=i;
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
        int nLength=m_number.length()-1;
        for( int i=nLength; i>=0; --i){
            char ch =m_number.at(i);
            m_total += (m_data[ch] * pow(m_base,nLength-i));
        }
    }
    void Print(){
        cout<<m_total<<endl;
    }
    
private:
    int m_base;
    int m_total=0;
    string m_number;
    map<char, int> m_data;
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