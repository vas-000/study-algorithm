#include <iostream>

using namespace std;

int main()
{
    int year;
    cin >> year;

    //4의 배수 인지
    if( (year % 4) != 0){
        cout << "0" << endl;
        return 0;
    }

    if( (year %100 == 0) && ( year %400 !=0)){
        cout << "0"<<endl;
        return 0;
    }

    cout << "1"<<endl;
    return 0;
}