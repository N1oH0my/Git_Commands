#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include<sstream>
//-------------------//
#include <tuple>

using std::cout;
using std::cin;
using std::endl;

std::tuple<int, int, double> add_multiply_divide(int a, int b) {
	return std::make_tuple(a + b, a * b, double(a) / double(b));
}
//-------------------------------------------MAIN--------------------------------------------------//
int main() {
	
	std::tuple<int, char> T(10, 'ch');
	int a = 0; //char b = 'T';
	int b = 1;
	//swap
	std::tie(a, b) = std::make_tuple(b, a);
	cout << a << ' ' << b;
	//--
	cout << endl;
	cin.get();
	return 0;
}
//-------------------------------------------END-OF-MAIN--------------------------------------------------//