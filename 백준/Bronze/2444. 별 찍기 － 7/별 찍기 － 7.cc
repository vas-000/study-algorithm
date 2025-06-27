#include <iostream>

using namespace std;

void printStar(int count){
    for(int i=0; i< count; i++)
        cout<<"*";
}
void printSpace(int count){
    for( int i=0; i< count; i++)
        cout<<" ";
}
void printRow(int total, int line, int space){
    printSpace(space);
    printStar(total-(space*2)-1);
    cout<<endl;
}

int main()
{
    int count;
    cin >> count;

    int nTotal = count*2;
    int nlspace = count-1;
    for( int i=1; i< nTotal; ++i){
        printRow(nTotal, i, nlspace);
        if(i<count){
            nlspace--;
        }
        else{
            nlspace++;
        }
    }

    return 0;
}