#include "circuit.h"
using namespace std;
int main(int argc, const char * argv[])
{
    //f = ask the user to write the directory of the file contains the gates
    //build(f)
    
    circuit<string> reg;
    reg.build("/Users/ahmedmohammed/academic/2013-14/ECE302/ECE302_labs/ECE302-finalProject2/ECE302-finalProject2/file.txt");

    /*reg.addGate("NOR", "X5", "X6","Y",7);
    reg.addGate("NAND", "X3", "X4","X6",6);
    reg.addGate("NAND", "X1", "X2","X5",5);
    reg.addGate("AND", "B", "D","X4",4);
    reg.addGate("OR", "A", "C","X3",3);
    reg.addGate("AND", "B", "C","X2",2);
    reg.addGate("OR", "A", "B","X1",1);
    */

    reg.equation();

    reg.setVar("A", "1101");
    reg.setVar("B", "1001");
    reg.setVar("C", "1111");
    reg.setVar("D", "0111");
    cout << "evaluate:" <<endl;
    cout << "Y =( " <<  reg.evaluate() << " )" <<endl;
    cout << "\n" <<endl;

    reg.slowPath();
    cout << "\n" <<endl;

    reg.longPath();
    cout << "\n" <<endl;

    reg.removeGate("AND", "B", "D","X4",4);
    reg.removeGate("AND", "B", "C","X2",2);
    reg.removeGate("OR", "A", "B","X1",1);
    reg.removeGate("OR", "A", "C","X3",3);  

    reg.equation();
    reg.longPath();
    cout << "\n" <<endl;

    reg.slowPath();
    
  
return 0;
} 