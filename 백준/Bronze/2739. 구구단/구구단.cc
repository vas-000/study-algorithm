#include <iostream>

using namespace std;

class CMultiplicationTable
{
private:
    int m_base;
    bool input(int& val, int min, int max){
        cin>>val;
        if( (val<min)||(val>max)){
            return false;
        }
        return true;
    }
public:
    bool InputData(){
        if(!input(m_base, 1, 9)){
            return false;
        }
        return true;
    }
    void Print(){
        for(int i=1; i<=9; ++i){
            cout<<m_base<<" * "<<i <<" = "<<m_base*i<<endl;
        }
    }
};

int main()
{
    CMultiplicationTable gugudan;
    if(!gugudan.InputData()){
        return -1;
    }
    gugudan.Print();
    return 0;
}