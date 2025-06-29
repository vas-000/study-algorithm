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
        if( m_word.length() > 100){
            return -1;
        }
    }

    void Print(){
       cout<< m_word.length()<<endl;
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