#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class CWordCount
{
private:
    string m_word;
    int m_count=0;

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

    void findString(char* str, int size){
        if( size <= 0 ){
            return;
        }
        int pos=0;   
        for( pos=0; pos< size; ++pos){
            if( pos==0 && *(str)==' '){
                pos +=1;
                break;
            }
            if((*(str+pos)==' ') || (pos+1 == size)){
                m_count++;
                pos +=1;
                break;
            }
        }
        findString(str+pos, size-pos);
    }
public:
    bool InputData(){
        getline(cin, m_word);
        if(m_word.length()>1000000){
            return false;
        }
        return true;
    }
    void Process(){
        
        findString((char*)m_word.c_str(), m_word.length());

    }
    void Print(){
        cout<< m_count<<endl;
    }
};

int main()
{
    CWordCount wordCount;
    if(!wordCount.InputData()){
        return -1;
    }
    wordCount.Process();
    wordCount.Print();
    return 0;
}