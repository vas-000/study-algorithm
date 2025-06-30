#include <iostream>
#include <string>
#include <map>

using namespace std;

class CFindAlphabet
{
private:
    string m_values;
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
    CFindAlphabet(){
        for(char i='a';i<= 'z'; ++i){
            m_alphabet[i]=-1;
        }
    }
    bool InputData(){
        cin>> m_values;
        if( m_values.length()>100){
            return false;
        }
        for( int i=0; i< m_values.length(); ++i){
            if( 'a' <=m_values.at(i) &&  m_values.at(i)<='z'){
                continue;
            }
            return false;
        }
        return true;
    }
    void Process(){
        for(int i=0;i<m_values.length(); ++i){
            if( m_alphabet[m_values.at(i)]==-1)
                m_alphabet[m_values.at(i)]=i;
        }
    }
    void Print(){
        for(char i='a';i<= 'z'; ++i){
            cout<< m_alphabet[i] << " ";
        }
        cout<<endl;
    }
};

int main()
{
    CFindAlphabet findAlphabet;
    if(!findAlphabet.InputData()){
        return -1;
    }
    findAlphabet.Process();
    findAlphabet.Print();
    return 0;
}