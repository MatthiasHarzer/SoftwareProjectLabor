#include <iostream>
#include <string>

using namespace std;

#include "ast.h"

int IntExp::eval() { return val;}

string IntExp::pretty() {
    return to_string(val);
}

string IntExp::smartPretty() {
    return pretty();
}

int PlusExp::eval() { return e1->eval() + e2->eval(); }

string PlusExp::pretty() {
    string s("(");
    s.append(e1->pretty());
    s.append("+");
    s.append(e2->pretty());
    s.append(")");
    return s;
}
string PlusExp::smartPretty() {
    string s;
    s.append(e1->smartPretty());
    s.append("+");
    s.append(e2->smartPretty());
    return s;
}


int MultExp::eval() { return e1->eval() * e2->eval(); }

string MultExp::pretty() {
    string s("(");
    s.append(e1->pretty());
    s.append("*");
    s.append(e2->pretty());
    s.append(")");
    return s;
}

string MultExp::smartPretty() {
    bool e1IsPlus = typeid(*e1) == typeid(PlusExp);
    bool e2IsPlus = typeid(*e2) == typeid(PlusExp);

    string e1s = e1->smartPretty();
    string e2s = e2->smartPretty();

    string s;
    if(e1IsPlus){
        s.append("(");
        s.append(e1s);
        s.append(")");
    } else {
        s.append(e1s);
    }

    s.append("*");

    if(e2IsPlus) {
        s.append("(");
        s.append(e2s);
        s.append(")");
    } else {
        s.append(e2s);
    }
    return s;
}




EXP newInt(int i) {
    return std::make_shared<IntExp>(i);
}

EXP newPlus(EXP l, EXP r) {
    return std::make_shared<PlusExp>(l,r);
}

EXP newMult(EXP l, EXP r) {
    return std::make_shared<MultExp>(l,r);
}
