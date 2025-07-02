#include <cctype>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class CDialNumber
{
private:
    int m_ret=0;
    string m_word;
    map<char, int> m_dialValue={{'A',3}, {'B',3},{'C',3},
                                {'D',4}, {'E',4},{'F',4},
                                {'G',5}, {'H',5},{'I',5},
                                {'J',6}, {'K',6},{'L',6},
                            {'M',7}, {'N',7},{'O',7},
                            {'P',8}, {'Q',8},{'R',8},
                            {'S',8}, {'T',9},{'U',9}, {'V',9},
                            {'W',10},{'X',10},{'Y',10}, {'Z',10}};

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
        if((m_word.length()>15) || (m_word.length()<2)){
            return false;
        }
        
        return true;
    }
    void Process(){
        int time=0;
        for(int i=0;i<m_word.length(); i++){
            time += m_dialValue[m_word.at(i)];
        }
        m_ret = time;
    }
    void Print(){
        cout<< m_ret <<endl;
    }
};

int main()
{
    CDialNumber number;
    if(!number.InputData()){
        return -1;
    }
    number.Process();
    number.Print();
    return 0;
}