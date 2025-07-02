#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Number{
public:
    void SetValue(int value){
        m_value = value;
    }
    void Process(){
        int a = m_value/100;
        int b = (m_value/10)%10;
        int c = m_value%10;
        m_revValue = (c*100)+(b*10)+(a);
    }
    int GetValue(){
        return m_revValue;
    }
private: 
    int m_value=0;
    int m_revValue;
};
class CRevNumber
{
private:
    int m_ret=0;
    Number m_first;
    Number m_second;

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

public:
    bool InputData(){
        int nNum1, nNum2;
        cin>>nNum1>>nNum2;
        if(!rangeCheck(nNum1, 100, 1000)||
           !rangeCheck(nNum2, 100, 1000)){
            return false;
        }
        if( nNum1 == nNum2 )
            return false;

        m_first.SetValue(nNum1);
        m_second.SetValue(nNum2);
        return true;
    }
    void Process(){
        m_first.Process();
        m_second.Process();

        int a = m_first.GetValue();
        int b = m_second.GetValue();
        if(a > b){
            m_ret = a;
        }
        else{
            m_ret = b;
        }
    }
    void Print(){
        cout<< m_ret<<endl;
    }
};

int main()
{
    CRevNumber revNumber;
    if(!revNumber.InputData()){
        return -1;
    }
    revNumber.Process();
    revNumber.Print();
    return 0;
}