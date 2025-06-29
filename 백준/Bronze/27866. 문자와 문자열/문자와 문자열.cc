#include <iostream>

using namespace std;

class CWord
{
private:
    string m_word;
    int m_count;

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
        cin>>m_word;
        if( m_word.length() > 1000){
            return -1;
        }
        cin >> m_count;
        if(!rangeCheck(m_count, 1, m_word.length())){
            return -1;
        }
    }

    void Print(){
       cout<< m_word.at(m_count-1)<<endl;
    }
};

int main()
{
    CWord word;
    if(!word.InputData()){
        return -1;
    }
    word.Print();
    return 0;
}