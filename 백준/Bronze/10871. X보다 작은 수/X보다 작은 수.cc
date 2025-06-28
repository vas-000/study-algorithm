#include <iostream>
#include <vector>

using namespace std;

class CCounter
{
private:
    int m_count;
    int m_limitVal;
    vector<int> m_data;
    vector<int> m_retData;
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
        cin>> m_count>> m_limitVal;
        if(!rangeCheck(m_count, 1, 10000)
        || !rangeCheck(m_limitVal, 1, 10000)){
            return false;
        }

        for(int i=0; i<m_count; ++i){
            int data;
            if(!input(data, -1, 10000)){
                return false;
            }
            m_data.push_back(data);
        }
        
        return true;
    }

    void Process(){
        for( auto data:m_data){
            if( data<m_limitVal){
                m_retData.push_back(data);
            }
        }
    }
    void Print(){
        for( auto data:m_retData){
           cout<<data<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    CCounter counter;
    if(!counter.InputData()){
        return -1;
    }
    counter.Process();
    counter.Print();
    return 0;
}