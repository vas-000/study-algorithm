#include <iostream>
#include <cmath>
using namespace std;


// 소수 판별하기
bool Prime(unsigned long long n) 
{
    if (n < 2) // 2 미만은 소수 x
        return false;
    
    if (n == 2) // 2는 가장 작은 소수
        return true;
    
    if (n % 2 == 0) // 짝수는 소수 x
        return false;
    
    // 3부터 n의 제곱근까지 검사
    int N = round(sqrt(n));
    for (unsigned long long i = 3; i <= N; i += 2) 
    {
        if (n % i == 0) 
            return false;
    }
    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        if (n < 1 || n > 123'456) return 0;

        int count = 0;
        for (int i = n+1; i <= n*2; i++)
        {
            if (Prime(i))
                count++;
        }
        cout << count << '\n';
    }

    return 0;
}