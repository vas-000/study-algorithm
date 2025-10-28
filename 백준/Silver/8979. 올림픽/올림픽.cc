#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    if (N < 1 || N > 1000) return 0;
    
    int find_country;
    cin >> find_country;
    
    vector<int> gold(N+1);
    vector<int> silver(N+1);
    vector<int> bronze(N+1);
    
    int country_num = 0;
    
    for(int i = 0; i < N; i++)
    {
        cin >> country_num;
        cin >> gold[country_num];
        cin >> silver[country_num];
        cin >> bronze[country_num];   
    }
    
    int rank = 1;
    for (int i = 1; i <= N; ++i) 
    {
        if (i == find_country) 
            continue;
        
        if (gold[i] > gold[find_country] ||
            (gold[i] == gold[find_country] && silver[i] > silver[find_country]) ||
            (gold[i] == gold[find_country] && silver[i] == silver[find_country] 
             && bronze[i] > bronze[find_country])) 
        {
            rank++;
        }
    }
    
    cout << rank << '\n';
    
}