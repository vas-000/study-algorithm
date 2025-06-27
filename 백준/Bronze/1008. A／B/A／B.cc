#include <iostream>
#include <string>

using namespace std;

void calc(int a, int b, int decimalPlace)
{
    if( (a==0) || (decimalPlace==0))
        return;
    a = a*10;
    cout << a/b;
    calc(a%b, b, --decimalPlace);  
}

int main()
{
    int a, b, c;
    int decimalPlace=10;
    cin >> a >> b;
    
    cout<< a/b;
    
    c = a%b;
    if( c != 0)
        cout << ".";
    calc( c, b, decimalPlace);
    return 0;
}