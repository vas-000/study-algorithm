#include <iostream>
#include <vector>

using namespace std;

class CMinMax
{
private:
    int m_count;
    int m_min=1000000;
    int m_max=-1000000;
    vector<int> m_data;
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
        if(!input(m_count, 1, 1000000)){
                return false;
            }

        for(int i=0; i<m_count; ++i){
            int data;
            if(!input(data, -1000000, 1000000)){
                return false;
            }
            m_data.push_back(data);
        }
        
        return true;
    }

    void Process(){
        for( auto data:m_data){
            if(m_max<data)
                m_max=data;
            if(m_min>data)
                m_min=data;
        }
    }
    void Print(){
        cout<<m_min<<" "<<m_max<<endl;
    }
};

int main()
{
    CMinMax minmax;
    if(!minmax.InputData()){
        return -1;
    }
    minmax.Process();
    minmax.Print();
    return 0;
}