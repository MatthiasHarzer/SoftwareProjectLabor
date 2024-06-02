#include <iostream>
#include <string>

using namespace std;

#include "ast.h"

int IntExp::eval() { return val;}

string IntExp::pretty() {
    return to_string(val);
}

string IntExp::smartPretty(bool _) {
    return pretty();
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
string PlusExp::smartPretty(bool withBrackets) {
    string s;
    if (withBrackets) {
        s.append("(");
    }
    s.append(e1->smartPretty());
    s.append("+");
    s.append(e2->smartPretty());
    if (withBrackets) {
        s.append(")");
    }
    return s;


}
string PlusExp::smartPretty() {
    return smartPretty(false);
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

string MultExp::smartPretty(bool _) {
     string s;
    s.append(e1 -> smartPretty(true));
    s.append("*");
    s.append(e2 -> smartPretty(true));
    return s;
}

string MultExp::smartPretty() {
   return smartPretty(false);
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
