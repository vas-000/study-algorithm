#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class CCharacter
{
private:
    vector<int> m_Idxs;
    char m_character;
    bool m_isGrouped;
    int preIdx=-1;
public:
    void SetData(char ch, int idx){
        m_character = ch;
        m_Idxs.push_back(idx);
        m_isGrouped=true;
    }
    void AddIdx(int idx){
        m_Idxs.push_back(idx);
    }
    bool Process(int idx){
        if( (idx >= m_Idxs.size()) || (m_isGrouped==false)){
            return m_isGrouped;
        }
        int val = m_Idxs[idx];
        if( preIdx == -1){
            preIdx=val;
        }
        else{
            if( preIdx != val-1){
                m_isGrouped = false;
            }
            else{
                preIdx = val;
            }
        }

        return Process(idx+1);
    }
};
class CWord{
public:
    bool InputData(){
        cin>> m_data;
        if( m_data.length() > 100){
            return false;
        }
        return true;
    }
    void Process(){
        for( int i=0; i< m_data.length(); ++i){
            char ch = m_data.at(i);
            if( m_process.find(ch)== m_process.end()){
                CCharacter data;
                data.SetData(m_data.at(i), i);
                m_process[ch]=data;
            }
            else{
                m_process[ch].AddIdx(i);
            }
        }

        for( auto ch:m_process){
            if( ch.second.Process(0) == false){
                isGrouped = false;
                return;
            }
        }
    }
    bool IsGrouped(){
        return isGrouped;
    }
private:
    string m_data;
    map<char, CCharacter> m_process;
    bool isGrouped=true;

};

class CGroupChecker
{
private:
    int m_count=0;
    vector<CWord> m_group;

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
        if(!input(m_count, 0, 100)){
            return false;
        }
        
        for(int i=0; i<m_count; ++i){
            CWord word;
            if( !word.InputData())
                return false;
            m_group.push_back(word);
        }
        
        return true;
    }
    void Process(){
        for(auto& data:m_group){
            data.Process();
        }
    }
    void Print(){
        int sum=0;
        for(auto data: m_group){
            if( data.IsGrouped()){
                sum+=1;
            }
        }

        cout << sum<<endl;
    }
};

int main()
{
    CGroupChecker groupChecker;
    if(!groupChecker.InputData()){
        return -1;
    }
    groupChecker.Process();
    groupChecker.Print();
    return 0;
}