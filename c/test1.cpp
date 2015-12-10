#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string a = "c(a,b)";

    string::size_type lidx = a.find_first_of("(");
    string::size_type midx = a.find_first_of(",");

    cout << a.substr(lidx+1,midx-lidx-1) << endl;
    cout << a.substr(midx+1,a.size()-midx-2) << endl;
	return 0;
}
