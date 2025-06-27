#include <iostream>

using namespace std;
class CDataType
{
private:
    int m_bytes;
public:
    bool Input(){
        cin>> m_bytes;
        if( (m_bytes<4) || (m_bytes>1000)){
            cout<< "Input Data Error!!"<<endl;
            return false;
        }
        if( (m_bytes%4!=0)){
            cout<< "Input Data Error!!"<<endl;
            return false;
        }
        return true;
    }
    void Print(){
        int loopcount = m_bytes / 4;
        for(int i=0; i< loopcount; ++i){
            cout<< "long ";
        }
        cout<< "int"<<endl;
    }
};

int main()
{
    CDataType dataType;
    if(!dataType.Input()){
        return -1;
    }
    dataType.Print();
    return 0;
}