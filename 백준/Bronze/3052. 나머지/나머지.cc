#include <iostream>
#include <vector>

using namespace std;
class CNumber
{
private:
    int m_number;
public:
    void SetNumber(int &number){
        m_number=number;
    }

    int Remain(){
        return m_number % 42;
    }
};
class CNumbers
{
private:
    vector<CNumber> m_numbers;
    vector<int> m_remains;

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

    bool chkRemains(int& aValue){
        for(int i=0; i<m_remains.size(); ++i){
            if( m_remains.at(i)==aValue)
                return false;
        }
        return true;
    }
public:
    bool InputData(){
        for( int cnt=0; cnt< 10; ++cnt){
            int number;
            if(!input(number,0,1000))
                return false;
            CNumber num;
            num.SetNumber(number);
            m_numbers.push_back(num);
        }
        return true;
    }

    void Process(){
        for(auto number: m_numbers){
            int remain =number.Remain();
            if( chkRemains(remain))
                m_remains.push_back(remain);
        }
    }
    void Print(){
       cout<< m_remains.size()<<endl;
    }
};

int main()
{
    CNumbers numbers;
    if(!numbers.InputData()){
        return -1;
    }
    numbers.Process();
    numbers.Print();
    return 0;
}