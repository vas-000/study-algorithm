#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CAlphabet{
private:
    int m_repeat=1;
    string m_values;
    string m_ret;
    void repeatCharacter(char ori){
        for(int i=0;i <m_repeat; ++i){
            m_ret.push_back(ori);
        }
    }
public:
    CAlphabet(int& repeat, string& src)
        :m_repeat(repeat), m_values(src){}
    void Process(){
        for(int i=0; i<m_values.length(); ++i){
            repeatCharacter(m_values.at(i));
        }
    }
    void Print()
    {
        cout<< m_ret<<endl;
    }
};
class CRepeatAlphabet
{
private:
    int m_cnt;
    vector<CAlphabet> m_alphabet;

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
        if(!input(m_cnt, 1, 1000)){
            return false;
        }
        int repeat;
        string src;
        for(int i=0; i< m_cnt; ++i){
            cin>> repeat>>src;
            if( (1>repeat) || (repeat>8)){
                return false;
            }
            if(src.length()>20){
                return false;
            }
            CAlphabet alpha(repeat, src);
            m_alphabet.push_back(alpha);
        }
        return true;
    }
    void Process(){
        for(auto& alpha:m_alphabet){
            alpha.Process();
        }
    }
    void Print(){
        for(auto alpha:m_alphabet){
            alpha.Print();
        }
    }
};

int main()
{
    CRepeatAlphabet repeatAlphabet;
    if(!repeatAlphabet.InputData()){
        return -1;
    }
    repeatAlphabet.Process();
    repeatAlphabet.Print();
    return 0;
}