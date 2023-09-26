#include <iostream>
using namespace std;




void moveStack(int numOfDisks, int starterSpindle, int endSpindle, int otherSpindle){
    
    //end of recursion
    if (numOfDisks == 0){
        return;
    }

    moveStack(numOfDisks-1, starterSpindle, endSpindle, otherSpindle);
    cout << "Disk " << numOfDisks << " moves from spindle " << starterSpindle << " to " << endSpindle << endl;
    moveStack(numOfDisks-1, starterSpindle, endSpindle, otherSpindle);

}

int main(){
    moveStack(2,1,3,2);
}