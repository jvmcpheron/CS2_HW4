//Jane McPheron
//Teammate: Alex Heidorn



#include <iostream>
#include <fstream> 
#include <string> 
using namespace std;




class LLData {
private:
    int data;
    LLData *next;
    LLData() {}
public:
    LLData(int d, LLData *nxt) {
        data = d;
        next = nxt;
    }
    int getData() { return data; }
    LLData* getNext() { return next; }
    void setData(int d) { data = d; }
    void setNext(LLData* nxt) { next = nxt; }
};
class LinkedList {
private:
    LLData* head;
    LLData* tail;
    string name;
public:
    LinkedList() { 
        tail = NULL; 
        head = new LLData(NULL, tail);   
    }
    LinkedList(string n) { 
        tail = NULL; 
        head = new LLData(NULL, tail); 
        name = n;  
    }
    LLData *getFirst() { return head->getNext(); }
    void setFirst(LLData *fst) { head->setNext(fst); }
    void addItem(int d) {
        head->setNext(new LLData(d,head->getNext()));
    }
    void showList() {
        LLData *curr = getFirst();
        cout << getName() << ": ";
        while (curr != tail) {
            cout << curr->getData() << " -> ";
            curr = curr->getNext();
        }
        cout << endl;
    }
    void populateList(int n){
        if (n==0) {return;};
        addItem(n);
        populateList(n-1);        
    }
    string getName(){return name;}
};
void moveDisk(LinkedList fromPole, LinkedList toPole);
void moveStack(int n, LinkedList fromPole, LinkedList toPole, LinkedList extraPole);
int main()
{
    LinkedList poleA("Pole A");
    LinkedList poleB("Pole B");
    LinkedList poleC("Pole C");
    int numDisks;
       
    cout << "How many disks do you want to use?\n";
    cin >> numDisks;

    poleA.populateList(numDisks);
    poleA.showList();
    cout << endl;

    /*testing move Disk funtion
    moveDisk(poleA, poleB);
    poleA.showList();

    poleB.showList();
    */

    moveStack(numDisks, poleA, poleB, poleC);
}
/*
checks:
1. number under is smaller
2. if lists are empty, operation fails

*/

/*My attempts*/
void moveStack(int n, LinkedList fromPole, LinkedList toPole, LinkedList extraPole){
    if (n==0){ return; };

    moveStack(n-1, fromPole, extraPole, toPole);
    
    
    if (toPole.getFirst() == nullptr || (fromPole.getFirst() != nullptr && toPole.getFirst()->getData() > fromPole.getFirst()->getData())) {
        cout << "Moving disk " << fromPole.getFirst()->getData() << " from " << fromPole.getName() 
        << " to " << toPole.getName() << endl;
        moveDisk(fromPole, toPole);
        fromPole.showList();
        toPole.showList(); 
        extraPole.showList();
        cout << endl;

        moveStack(n-1, extraPole, toPole, fromPole);
    } else {
    // Handle the case where the move is not valid (e.g., the last disk in 'toPole' is not larger).
        cout << "Invalid move: The last disk on " << toPole.getName() << " is not larger than the last disk on " << fromPole.getName() << "." << endl;
    }
    
}
void moveDisk(LinkedList fromPole, LinkedList toPole){
    LLData* temp = fromPole.getFirst(); //copies the node to be moved
    fromPole.setFirst(fromPole.getFirst()->getNext()); //advances fromPole First
    temp->setNext(toPole.getFirst()); //links temp node to toPole
    toPole.setFirst(temp); //make temp node the new first of toPole
}