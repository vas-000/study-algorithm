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
class CMatrix{
public:
    CMatrix(){
      SetSize(9,9);  
    }
    void SetSize(int row, int col){
        m_row = row;
        m_col = col;
        for( int i=0; i<m_col; ++i){
            ROW row;
            row.resize(m_row);
            m_data.push_back(row);
        }
    }
    bool InputData(){
        for(int i=0; i<m_col; ++i){
            for(int j=0; j<m_row; ++j){
                int val;
                if(!UTIL::Input(val, 0, 100)){
                    return false;
                }
                m_data[i][j]=val;
            }
        }
        return true;
    }
    void findRowMax(int aIdx, int& aMax, int& aRow, int& aCol){
        auto row = m_data.at(aIdx);
        for(int i=0;i<m_col;++i){
            if( aMax < row.at(i)){
                aMax = row.at(i);
                aCol = i;
                aRow = aIdx;
            }
        }
    }
    void Process(){
        
        for(int i=0; i< m_row; ++i){
            findRowMax(i, m_max, m_maxRow, m_maxCol);
        }
        m_maxRow+=1;
        m_maxCol+=1;
    }
    void Print(){
        cout<< m_max<<endl;
        cout<< m_maxRow<< " "<<m_maxCol<<endl;
    }
    
private:
    int m_row;
    int m_col;
    int m_max=-1, m_maxRow=-1, m_maxCol=-1;
    vector<ROW> m_data;
};

int main()
{
    CMatrix matrix;
    if(!matrix.InputData()){
        return -1;
    }
    matrix.Process();
    matrix.Print();
    return 0;
}