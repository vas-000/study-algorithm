#include <iostream>
#include <vector>

using namespace std;

class CCounter
{
private:
    int m_count;
    int m_findVal;
    int m_findCount=0;
    vector<int> m_data;
    bool input(int& val, int min, int max){
        cin>>val;
        if( (val<min)||(val>max)){
            return false;
        }
        return true;
    }
public:
    bool InputData(){
        if(!input(m_count, 1, 100)){
            return false;
        }

        for(int i=0; i<m_count; ++i){
            int data;
            if(!input(data, -100, 100)){
                return false;
            }
            m_data.push_back(data);
        }

        if(!input(m_findVal, -100, 100)){
            return false;
        }
        
        return true;
    }

    void Process(){
        for( auto data:m_data){
            if( data==m_findVal){
                m_findCount++;
            }
        }
    }
    void Print(){
        cout<<m_findCount<<endl;
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