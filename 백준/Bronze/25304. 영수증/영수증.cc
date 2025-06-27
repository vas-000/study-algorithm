#include <iostream>
#include <vector>

using namespace std;
class CProduct{
private: 
    int m_price;
    int m_count;

    bool checkRange(int val, int min, int max){
        if( (val<min)||(val>max))
            return false;
        return true;
    }
public:
    bool SetData(){
        cin>>m_price>>m_count;
        if( !checkRange(m_price, 1, 1000000)
            ||!checkRange(m_count, 1, 10))
            return false;
        return true;
    }
    int GetTotalPrice(){
        return m_price*m_count;
    }
};

class CReceipt
{
private:
    int m_total;
    int m_count;

    vector<CProduct> m_purchase;
    bool input(int& data, int min, int max){
        cin>> data;
        if( (data<min) || (data>max)){
            cout<< "Input Data Error!!"<<endl;
            return false;
        }
        return true;
    }
public:
    bool InputData(){
        if( !input(m_total, 1, 1000000000)){
            return false;
        }

        if( !input(m_count, 1, 100)){
            return false;
        }

        for(int i=0; i< m_count; ++i){
            CProduct product;
            product.SetData();
            m_purchase.push_back(product);
        }
        return true;
    }
    bool Check(){
        int nSum=0;
        for( auto product:m_purchase){
            nSum+=product.GetTotalPrice();
        }

        if( nSum == m_total)
            return true;

        return false;
    }
};

int main()
{
    CReceipt recipt;
    if(!recipt.InputData()){
        return -1;
    }
    if(recipt.Check()){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}