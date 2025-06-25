#include <iostream>

using namespace std;

int main()
{
    int exam;
    cin >> exam;
    exam = exam/10;
    switch(exam)
    {
        case 10:
        case 9:
            cout << "A"<<endl;
            break;
        case 8:
            cout << "B"<< endl;
            break;
        case 7:
            cout << "C"<<endl;
            break;
        case 6:
            cout << "D"<<endl;
            break;
        default:
            cout << "F"<<endl;
            break;
    }
    return 0;
}