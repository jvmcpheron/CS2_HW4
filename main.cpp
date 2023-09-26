#include <iostream>
using namespace std;




void moveStack(int numOfDisks, int starterSpindle, int endSpindle, int otherSpindle){
    
    //end of recursion
	if(numOfDisks==1){
		cout<<"Move disk 1 from spindle "<<starterSpindle<<" to spindle "<<endSpindle<<endl;
		return;
	}

    //when solving the problem irl, you usually try to stack 
    //all but one on the other spindle before you try to stack all
    //of them on the end, so the solution should go back and solve 
    //the amount of disks - 1 with the goal being the other spindle
    //before solving the final amount with the final spindle

    //call function with one less disk and set the other as the end
    moveStack(numOfDisks-1, starterSpindle, otherSpindle, endSpindle);

    cout << "Move disk " << numOfDisks << " moves from spindle " << starterSpindle << " to " << endSpindle << endl;

    moveStack(numOfDisks-1, otherSpindle, endSpindle, starterSpindle);

}

int main(){

    //tests:
    cout<< " Test One (Three Disks, start at 2, end at 1): "<<endl;
    moveStack(3,2,1,3);
    cout<< " Test Two (Two Disks, start at 1, end at 3): "<<endl;
    moveStack(2,1,3,2);
    cout<< " Test Three (Four Disks, start at 1, end at 3): "<<endl;
    moveStack(4,1,3,2);
    cout<< " Test Four (Three Disks, start at 1, end at 3): "<<endl;
    moveStack(3,1,3,2);
}