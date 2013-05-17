#include "circuit.h"
using namespace std;
int main()
{
    //f = ask the user to write the directory of the file contains the gates
    circuit<string> CKT;
    CKT.build("/Users/ahmedmohammed/file.txt");
    CKT.addGate("OR", "A", "B","X1","2");
    CKT.equation();
    CKT.setVar("A", "1101");
    CKT.setVar("B", "1001");
    CKT.setVar("C", "1111");
    CKT.setVar("D", "0111");
    cout << "evaluate:" <<endl;
    cout << "Y =( " <<  CKT.evaluate() << " )" <<endl;
    cout << "\n" <<endl;
    CKT.slowPath();
    cout << "\n" <<endl;
    CKT.longPath();
    cout << "\n" <<endl;
    CKT.removeGate("AND", "B", "D","X4","4");
    CKT.removeGate("AND", "B", "C","X2","2");
    CKT.removeGate("OR", "A", "B","X1","1");
    CKT.removeGate("OR", "A", "C","X3","3");
    CKT.equation();
    CKT.longPath();
    cout << "\n" <<endl;
    CKT.slowPath();
  
return 0;
} 