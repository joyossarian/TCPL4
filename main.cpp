#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

using namespace std;

string f() {
    return "test";
}

// if type T has move constructor or a move assignment
template<typename T>
void swap(T &a, T &b) // "perfect swap" (almost)
{
    T tmp{static_cast<T &&>(a)}; // the initialization may write to a
    a = static_cast<T &&>(b); // the assignment may write to b
    b = static_cast<T &&>(tmp); // the assignment may write to tmp
}

class PODType {
public:
    int iNum;
    double dNum;
};

class Inherited : public PODType {
public:
    virtual bool isPOD() { return false; }
};

int main() {


    // quoted string
    string Rstring = R"("quoted string")";
    cout << Rstring << endl;
    cout << R"***("quoted string containing the usual terminator ("))")***" << endl;


    string var{"cambridge"};
    string &r1{var};
    //string& r2{f()}; // error: f() is an rvalue
    //string& r3{"Princeton"}; // try to bind temporary
    string &&rr1{f()}; // bind a temporary to rvalue reference
    cout << rr1 << endl;

    // string&& rr2{r1}; // try to bind a lvalue to rvalue reference
    string &&rr2{"Oxford"};
    //string& c1{"Oxford"}; try to bind lvalue reference to temporary
    const string &constLVR{"Oxford"}; // bind temporary to const lvalue reference
    cout << constLVR << endl;

    // cast lvalue, lvalue reference to right value reference
    string &&rcast = static_cast<string &&>(var);
    cout << rcast << endl;

    string temp{static_cast<string &&>(r1)};


    vector<string> s;

    vector<string> s2(s);
    //vector<string> s3(s + "tail"); // no supported even in Clang

    bool isPODType = is_pod<PODType>::value;
    bool isVirtualPOD = is_pod<Inherited>::value;

    cout << "virtual is " << (isVirtualPOD ? "" : "not ") << "a POD" << endl;


    return 0;
}