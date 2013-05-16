//*************************************************************
// Author: Haneen Mohammed& Amal Mukhtar
//
// class BGate
// This class  is the user interface
//*************************************************************

#include <iostream>
using namespace std;
 
template <typename Elem>
class BGate
{
private:
    string type;    //Type
    string in1;     //input1
    string in2;     //input2
    string output;  //output
    double time;    //time
    Elem data1;     //input1(var) = data1 (value)
    Elem data2;     //input2(var) = data2 (value)
    Elem data3;     //output(var) = data3 (value)
public:
    BGate(string e,string input1,string input2,string o,double t)
    {type =  e; in1 = input1; in2 = input2; output = o;time = t;}
    BGate(){}
    string getType() const { return type; }
    void setType(const string& e) {type = e;}
    string getIn1() const { return in1; }
    void setIn1(const string& e) {in1 = e;}
    string getIn2() const{ return in2; }
    void setIn2(const string& e) { in2 = e; }
    string getOut() const { return output; }
    void setOut(const string& e) { output = e; }
    double getTime() const { return time; }
    void setTime(const double& e) { time = e; }
    Elem getData1()const { return data1; }
    void setData1(const Elem& b) { data1 = b; }
    Elem getData2()const { return data2; }
    void setData2(const Elem& b){ data2 = b; }
    Elem getData3() const{ return data3; }
    void setData3(const Elem& b){ data3 = b; }
};
