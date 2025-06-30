#include <cctype>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class CUsingWord
{
private:
    string m_word;
    map<char, int> m_alphabet;

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
    CUsingWord(){
        for(char ch='a'; ch<='z'; ++ch){
            m_alphabet[ch]=0;
        }
    }
    bool InputData(){
        cin >> m_word;
        if(m_word.length()>1000000){
            return false;
        }
        return true;
    }
    void Process(){
        for(int i=0; i<m_word.length(); ++i){
            char ch = std::toupper(m_word.at(i));
            if(m_alphabet.find(ch)== m_alphabet.end())
                m_alphabet[ch]=1;
            else
                m_alphabet[ch]++;
        }
    }
    void Print(){
        char result='?';
        int cnt=-1;
        for(auto alpha:m_alphabet){
            if( cnt == alpha.second){
                result ='?';
            }
            else if( cnt < alpha.second){
                result=alpha.first;
                cnt=alpha.second;
            }
        }
        cout<< result<<endl;
    }
};

int main()
{
    CUsingWord usingWord;
    if(!usingWord.InputData()){
        return -1;
    }
    usingWord.Process();
    usingWord.Print();
    return 0;
}