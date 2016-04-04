#include <iostream>
#include <vector>
#include <string>

using namespace std;

string f()
{
    return "test";
}

int main() {


    // quoted string
    string Rstring = R"("quoted string")";
    cout << Rstring << endl;
    cout << R"***("quoted string containing the usual terminator ("))")***";


    string var{"Cambridge"};
    string& r1{var};
    //string& r2{f()};



    return 0;
}