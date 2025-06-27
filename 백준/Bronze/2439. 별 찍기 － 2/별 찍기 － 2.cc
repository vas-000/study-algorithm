#include <iostream>

using namespace std;

class CDraw
{
private:
    int m_rowCount;
    void draw(int count, char ch){
        for(int i=0;i<count; ++i){
            cout<<ch;
        }
    }
    void drawRow(int row){
        draw(m_rowCount-row, ' ');
        draw(row, '*');
        cout << endl;
    }
public:
    void Input(){
        cin >> m_rowCount;
    }
    void Print(){
        for(int i=1; i<= m_rowCount; i++){
            drawRow(i);
        }
    }
};

int main()
{
    CDraw draw;
    draw.Input();
    draw.Print();
    return 0;
}