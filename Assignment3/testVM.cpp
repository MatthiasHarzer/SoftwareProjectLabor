#include <iostream>
#include <string>

using namespace std;

#include "vm.h"
#include "ast.h"
#include "parser.h"

void showVMRes(Optional<int> r) {
    if(r.isNothing())
        cout << "\nVM stack (top): empty";

    cout << "\nVM stack (top):" << r.fromJust();
}

void parse(const string& exp) {
    Optional<EXP> e = Parser(exp).parse();
    if (e.isNothing()){
        cout << exp << " is nothing \n";
        return;
    }

    auto root = e.fromJust();
    auto vm = VM((e.fromJust())->toVm());
    auto res = vm.run();

    cout << "Orig: " << exp << " | Parsed: " << root->smartPretty() << " = " << res.fromJust() << "\n";
}

void testVM() {

    {
        vector<Code> vc{
                newPush(1),
                newPush(2),
                newPush(3),
                newMult(),
                newPlus() };

        Optional<int> res = VM(vc).run();

        showVMRes(res);
    }

    {
        vector<Code> vc{
                newPush(2),
                newPush(3),
                newPush(5),
                newPlus(),
                newMult() };

        Optional<int> res = VM(vc).run();

        showVMRes(res);
    }

    parse("1");

    parse("1 + 0 ");

    parse("1 + (0) ");
    parse("1 + 2 * 0 ");
    parse("1 * 2 + 0 ");
    parse("1 + 2 * 2");
    parse("(1 + 2) * 2");
    parse("(1 + 2) * 2 * (2 * (1 + 0))");
    parse("(1 + 2) * 0 + 2");
    parse("2*2*2*2*2*2*2*2");
}


int main() {

    testVM();

    return 1;
}
