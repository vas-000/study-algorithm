#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

bool ChkRange(const int val, const int aMin, const int aMax){
    if( (val< aMin) || (val > aMax)){
        return false;
    }
    return true;
}

int main(){
    int A,B,C,X,Y;
    std::cin >> A>>B>>C>>X>>Y;
    
    if(!ChkRange(A, 1, 5'000)) return 0;
    if(!ChkRange(B, 1, 5'000)) return 0;
    if(!ChkRange(C, 1, 5'000)) return 0;
    if(!ChkRange(X, 1, 100'000)) return 0;
    if(!ChkRange(Y, 1, 100'000)) return 0;

    int sum=0;
    int nHalfPrice = 2*C;
    if((A+B) < nHalfPrice){
        sum = (X*A)+(Y*B);
    }
    else{
        // (A+B) > 2C
        if( (A > nHalfPrice) && (B>nHalfPrice)){
            // A>2C && B>2C
            int count = std::max(X,Y);
            sum = count*nHalfPrice;
        }
        else if( (A<nHalfPrice) && (B>nHalfPrice)){
            // A<2C && B>2C
            if( X > Y){
                sum = nHalfPrice*Y + (X-Y)*A;
            }
            else{
                sum = nHalfPrice*Y;
            }
        }
        else if( (A>nHalfPrice)&&(B<nHalfPrice)){
            // A>2C && B<2C
            if( Y > X){
                sum = nHalfPrice*X + (Y-X)*B;
            }
            else{
                sum = nHalfPrice*X;
            }
        }
        else{
            if( X > Y){
                sum = nHalfPrice*Y+(X-Y)*A;
            }
            else{
                sum = nHalfPrice*X+(Y-X)*B;
            }
        }
    }
        
    std::cout<<sum<<"\n";
    return 0;
}