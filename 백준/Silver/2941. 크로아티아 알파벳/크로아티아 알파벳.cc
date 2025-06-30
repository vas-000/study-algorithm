#include <cctype>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class CCvtWord
{
private:
    string m_word;
    int m_count=0;
    map<string, char> m_alphabet={{"c=", 0}, {"c-", 1}, {"dz=", 2}, {"d-", 3}, {"lj", 4},
                                  {"nj", 5}, {"s=", 6}, {"z=", 7}};

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
        cin >> m_word;
        if(m_word.length()>100){
            return false;
        }
        return true;
    }
    void Process(){
        for(auto key: m_alphabet){
            while(true){
                if( m_word.find(key.first)==string::npos){
                    break;
                }
                m_word.replace(m_word.find(key.first), key.first.length(), to_string(key.second));
            }
        }

    }
    void Print(){
        cout<< m_word.length()<<endl;
    }
};

int main()
{
    CCvtWord cvtWord;
    if(!cvtWord.InputData()){
        return -1;
    }
    cvtWord.Process();
    cvtWord.Print();
    return 0;
}