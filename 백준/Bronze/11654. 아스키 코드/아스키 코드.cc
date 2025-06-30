#include <iostream>

using namespace std;

class CAscii
{
private:
    char m_values;

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
        cin>> m_values;
        if( ( 'a'<=m_values && m_values<='z') || 
            ( 'A'<=m_values && m_values<='Z') ||
            ( '0'<=m_values && m_values<='9')){
                return true;
            }

        return false;
    }
    void Process(){
    }
    void Print(){
        cout<<static_cast<int>(m_values)<<endl;
    }
};

int main()
{
    CAscii ascii;
    if(!ascii.InputData()){
        return -1;
    }
    
    ascii.Print();
    return 0;
}