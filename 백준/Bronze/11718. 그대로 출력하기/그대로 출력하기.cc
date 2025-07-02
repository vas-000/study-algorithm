#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CLine
{
public:
    bool InputData(){
        getline(cin, m_data);
        if(m_data.length()>100){
            return false;
        }
        return true;
    }
    void Print(){
        cout<< m_data<<endl;
    }
private:
    string m_data;
};
class CEditor
{
private:
    int m_ret=0;
    vector<CLine> m_data;
    
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
        do{
            CLine line;
            if(!line.InputData()){
                return false;
            }
            m_data.push_back(line);
        }while(!cin.eof());
        
        return true;
    }
    void Process(){
    }
    void Print(){
        for(auto str:m_data){
            str.Print();
        }
    }
};

int main()
{
    CEditor editor;
    if(!editor.InputData()){
        return -1;
    }
    editor.Process();
    editor.Print();
    return 0;
}