#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    const int min = -1'000'000;
    const int max = 1'000'000;
    vector<int> m_data;
    int nTestCase;
    cin>>nTestCase;
    int val;
    for(int i=0; i< nTestCase; ++i){
        cin>>val;
        if( (val< min) || (val > max)){
            return -1;
        }
        m_data.push_back(val);
    }
    
    sort(m_data.begin(), m_data.end());
    
    for(int i=0; i< nTestCase; ++i){
        printf("%d\n", m_data[i]);
    }
    return 0;
}