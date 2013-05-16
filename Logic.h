//*************************************************************
//  Author: Haneen Mohammed& Amal Mukhtar
//
//  Logic.h
//  Functions for logical operations [AND,OR,NOR,NAND]
//  post condition: length(x) == length (y)
//*************************************************************
 
string AND(string x, string y)
{
    unsigned long len = x.length();
    string z;
    for (int i = 0; i<len;i++)
    {
        if( x[i]=='1'&& y[i]=='1' )
            z.append("1");
        else
            z.append("0");
    }
    return z;
}

string OR(string x, string y)
{
    unsigned long len = x.length();
    string z;
    for (int i = 0; i<len;i++)
    {
        if( x[i]=='1'|| y[i]=='1' )
            z.append("1");
        else
            z.append("0");
    }
    return z;
}

string NAND(string x, string y)
{
    unsigned long len = x.length();
    string z;
    for (int i = 0; i<len;i++)
    {
        if( x[i]=='1'&& y[i]=='1' )
            z.append("0");
        else
            z.append("1");
    }
    return z;
}

string NOR(string x, string y)
{
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

bool AND(bool x, bool y)
{
        return x && y;
    }
    bool OR(bool x, bool y)
    {
        return x || y;
}
    
bool NAND(bool x, bool y)
{
        return !(x && y);
    }
    bool NOR(bool x, bool y){
        return !(x || y);
}
