#include <iostream>
#include <vector>

using namespace std;

class CData{
private:
    int m_first;
    int m_second;
    int m_sum;
public:
    bool Input(){
        cin >> m_first>>m_second;
        if((m_first==0) && (m_second==0))
            return false;
        m_sum = m_first+m_second;
        return true;
    }

    void Print(){
        cout<< m_sum<< endl;
    }
};

class CSum{
private:
    vector<CData> m_datas;

public:
    void run(){
        while(true){
            CData data;
            if(!data.Input())
                break;
            m_datas.push_back(data);
        }

        for(int i=0; i< m_datas.size(); i++){
            m_datas.at(i).Print();
        }

    }
};

int main()
{
    CSum sum;
    sum.run();
    return 0;
}