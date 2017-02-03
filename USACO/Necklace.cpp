/*
ID: derek.i1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string breakAtSpot(int spot, string n) {
	return (n.substr(spot, n.length()) + n.substr(0, spot));
}

int main() {
	ofstream out("beads.out");
	ifstream in("beads.in");

	int size; string necklace;

	in >> size >> necklace;

	cout << "Original: " << necklace << endl;
	cout << "New: " << breakAtSpot(1, necklace);

	return 0;
}