#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    vector<pair<int, int>> m_data;
    int nTestCase;
    cin>>nTestCase;
    
    int x, y;
    while(nTestCase>0){
        cin >> x>>y;
        pair<int, int> data={x,y};
        m_data.push_back(data);
        nTestCase--;
    }
    sort(m_data.begin(), m_data.end());
    
    for(int i=0; i< m_data.size(); ++i){
        printf("%d %d\n", m_data[i].first, m_data[i].second);
    }
    
    return 0;
}
