#include <iostream>

using namespace std;

class CSum
{
private:
    int m_total=0;
    int m_count;
    bool input(int& data, int min, int max){
        cin>> data;
        if( (data<min) || (data>max)){
            cout<< "Input Data Error!!"<<endl;
            return false;
        }
        return true;
    }
public:
    bool InputData(){
        if( !input(m_count, 1, 10000)){
            return false;
        }
        return true;
    }
    void Process(){
        int nSum=0;
        for( int i=1;i<=m_count;i++){
            nSum+=i;
        }
        m_total = nSum;
    }
    void Print(){
        cout<< m_total<<endl;
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