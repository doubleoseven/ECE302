/**
 ECE302 final project
 BGate.h
 @author Haneen Mohammed& Amal Mukhtar
 @brief
 */

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
    Elem x;     //input1(var) = x (value)
    Elem y;     //input2(var) = y (value)
    Elem z;     //output(var) = z (value)
public:
    BGate(string e,string input1,string input2,string o,double t);
    BGate();
    string getType() const;
    void setType(const string&);
    string getIn1() const;
    void setIn1(const string&);
    string getIn2() const;
    void setIn2(const string&);
    string getOut() const;
    void setOut(const string&);
    double getTime() const;
    void setTime(const double&);
    Elem getDataX()const;
    void setDataX(const Elem&);
    Elem getDataY()const;
    void setDataY(const Elem&);
    Elem getDataZ() const;
    void setDataZ(const Elem&);
    string AND(string, string);
    string OR(string, string);
    string NAND(string, string);
    string NOR(string, string);
    bool AND(bool, bool);
    bool OR(bool, bool);
    bool NAND(bool, bool);
    bool NOR(bool, bool);
    Elem operation();
};

template <typename Elem>
BGate<Elem>::BGate(string e,string input1,string input2,string o,double t)
    {
        type =  e; in1 = input1; in2 = input2; output = o;time = t;
    }
template <typename Elem>
BGate<Elem>::BGate(){}
template <typename Elem>
string BGate<Elem>::getType() const{return type;}
template <typename Elem>
void BGate<Elem>::setType(const string& e){type = e;}
template <typename Elem>
string BGate<Elem>::getIn1() const{return in1;}
template <typename Elem>
void BGate<Elem>::setIn1(const string& e){in1 = e;}
template <typename Elem>
string BGate<Elem>::getIn2() const{return in2;}
template <typename Elem>
void BGate<Elem>::setIn2(const string& e){in2 = e;}
template <typename Elem>
string BGate<Elem>::getOut() const{return output;}
template <typename Elem>
void BGate<Elem>::setOut(const string& e){output = e;}
template <typename Elem>
double BGate<Elem>::getTime() const{return time;}
template <typename Elem>
void BGate<Elem>::setTime(const double& e){time = e;}
template <typename Elem>
Elem BGate<Elem>::getDataX()const{return x;}
template <typename Elem>
void BGate<Elem>::setDataX(const Elem& b){x = b;}
template <typename Elem>
Elem BGate<Elem>::getDataY()const{return y;}
template <typename Elem>
void BGate<Elem>::setDataY(const Elem& b){y = b;}
template <typename Elem>
Elem BGate<Elem>::getDataZ() const {return z;}
template <typename Elem>
void BGate<Elem>::setDataZ(const Elem& b){ z = b; }
template <typename Elem>
string BGate<Elem>::AND(string x, string y){
    unsigned long len = x.length();
    string z;
    for (int i = 0; i<len;i++){
        if( x[i]=='1'&& y[i]=='1' )
            z.append("1");
        else
            z.append("0");
    }
    return z;
}
template <typename Elem>
string BGate<Elem>::OR(string x, string y){
    unsigned long len = x.length();
    string z;
    for (int i = 0; i<len;i++){
        if( x[i]=='1'|| y[i]=='1' )
            z.append("1");
        else
            z.append("0");
    }
    return z;
}
template <typename Elem>
string BGate<Elem>::NAND(string x, string y){
    unsigned long len = x.length();
    string z;
    for (int i = 0; i<len;i++){
        if( x[i]=='1'&& y[i]=='1' )
            z.append("0");
        else
            z.append("1");
    }
    return z;
}
template <typename Elem>
string BGate<Elem>::NOR(string x, string y){
    unsigned long len = x.length();
    string z;
    for (int i = 0; i<len;i++){
        if( x[i]=='1'|| y[i]=='1' )
            z.append("0");
        else
            z.append("1");
    }
    return z;
}
template <typename Elem>
bool BGate<Elem>::AND(bool x, bool y)
{
    return x && y;
}
template <typename Elem>
bool BGate<Elem>::OR(bool x, bool y)
{
    return x || y;
}
template <typename Elem>
bool BGate<Elem>::NAND(bool x, bool y)
{
    return !(x && y);
}
template <typename Elem>
bool BGate<Elem>::NOR(bool x, bool y){
    return !(x || y);
}
template <typename Elem>
Elem BGate<Elem>::operation(){
    if (type == "AND")
        return AND(x,y);
    else if (type == "OR")
        return OR(x,y);
    else if (type == "NOR")
        return NOR(x,y);
    else
        return NAND(x,y);
}

