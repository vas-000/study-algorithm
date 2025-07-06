#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> ROW;
namespace UTIL{
    bool RangeCheck(int& val, int min, int max){
        if( (val<min)||(val>max)){
            return false;
        }
        return true;
    }

    bool Input(int& val, int min, int max){
        cin>>val;
        return RangeCheck(val, min, max);
    }
}
class CPrintString{
public:
    bool InputData(){
        for(int i=0; i<5; ++i){
            string str;
            cin>>str;
            if( (str.length()<0) || (str.length()>100))
                return false;
            m_data.push_back(str);
        }
        return true;
    }

    void Process(){
        for(auto data:m_data){
            cvtStringData(data);
        }
       
    }
    void Print(){
        for(auto data:m_cvtData){
            cout<< data;
        }
        cout<<endl;
    }
    
private:
    vector<string> m_data;
    vector<string> m_cvtData;

    void cvtStringData(const string& data){
        int nDataLength = data.length();
        if(nDataLength>m_cvtData.size()){
            m_cvtData.resize(nDataLength);
        }
        for(int i =0; i<nDataLength; ++i){
            m_cvtData[i].push_back(data.at(i));
        }
    }
};

int main()
{
    CPrintString printString;
    if(!printString.InputData()){
        return -1;
    }
    printString.Process();
    printString.Print();
    return 0;
}