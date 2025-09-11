#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;


// 소수 판별하기
bool Prime(const int num) 
{
        if( num%2 ==0){
            if(num==2){
                return true;
            }
            //짝수는 소수가 아님
            return false;
        }
        else{
            if( num == 1){
                return false;
            }
            int N = round(sqrt(num));
            //num의 약수는 N의 범위에 있음. 
            for( int i{3}; i<=N; i=i+2){
                if( num%i == 0){
                    // 나눠떨어지는 수가 하나라도 있으면 소수가 아님.
                    return false;
                }
            }
        }
        return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    
    std::vector<pair<int, int>> m_data;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        if (n < 1 || n > 123'456) return 0;
        
        int last = n*2;
        int start = n+1;
        m_data.push_back({start, last});
    }

    for(auto data: m_data){
        int count =0;
        for (int i = data.first; i <= data.second; i++)
        {
            if (Prime(i))
                count++;
        }
        cout<< count<<'\n';
    }
    
    

    return 0;
}