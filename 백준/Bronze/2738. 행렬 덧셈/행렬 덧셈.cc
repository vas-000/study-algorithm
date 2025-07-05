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
                if(!UTIL::Input(val, -100, 100)){
                    return false;
                }
                m_data[i][j]=val;
            }
        }
        return true;
    }
    const vector<ROW>& GetData(){return m_data;}
    void Sum(const vector<ROW>& first, const vector<ROW>& second){
        for(int i=0; i<m_col; ++i){
            for(int j=0; j<m_row; ++j){
                m_data[i][j]=first[i][j]+second[i][j];
            }
        }
    }
    void Print(){
        for(int i=0; i<m_col; ++i){
            for(int j=0; j<m_row; ++j){
                cout << m_data[i][j];
                if( (j+1)==m_row)
                    cout<<endl;
                else
                    cout << " ";
            }
            
        }  
    }
    
private:
    int m_row;
    int m_col;
    vector<ROW> m_data;
};

class CMatrixSum
{
private:
    int m_row, m_col;
    CMatrix m_first, m_second, m_sum;
public:
    bool InputData(){
        cin>> m_row >>m_col;
        if( !UTIL::RangeCheck(m_row, 0, 100)||
            !UTIL::RangeCheck(m_col, 0, 100)){
                return false;
        }

        m_first.SetSize(m_row, m_col);
        if(!m_first.InputData())
            return false;

        m_second.SetSize(m_row, m_col);
        if(!m_second.InputData())
            return false;

        m_sum.SetSize(m_row, m_col);
        return true;
    }
    void Process(){
        m_sum.Sum(m_first.GetData(), m_second.GetData());
    }
    void Print(){
        m_sum.Print();
    }
};

int main()
{
    CMatrixSum matrixSum;
    if(!matrixSum.InputData()){
        return -1;
    }
    matrixSum.Process();
    matrixSum.Print();
    return 0;
}