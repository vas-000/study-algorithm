#include <iostream>

using namespace std;

class CSum
{
private:
    int m_count;
    string m_values;
    int m_sum;

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
        if( !input(m_count, 1, 100)){
            return false;
        }

        cin>> m_values;
        if(m_values.size() > m_count){
            return false;
        }

        return true;
    }
    void Process(){
        int sum=0;
        for( int i=0; i< m_count; ++i){
            sum += (m_values.at(i)-'0');
        }
        m_sum = sum;
    }
    void Print(){
        cout<<m_sum<<endl;
    }
};

int main()
{
    CSum sum;
    if(!sum.InputData()){
        return -1;
    }
    sum.Process();
    sum.Print();
    return 0;
}