/*
ID: derek.i1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string breakAtSpot(int spot, string n) {
	return (n.substr(spot, n.length()) + n.substr(0, spot));
}

int countConsecutive(string necklace, char color) { // TODO: make this only read the first consecutive beads, then break after it isn't consecutive
	int count = 0;
	replace(necklace.begin(), necklace.end(), 'w', color);

	for (int i = 0; i < necklace.length() - 1; i++) {
		if (necklace.at(i) == color && necklace.at(i + 1) == color) { // TODO: if blue, make any whites blue. if encounter red, then make subsequent whites red.
			count++;
		}
	}
	cout << necklace << " " << color << ": " << count << endl;

	return count; // +whiteCount;
}

int main() {
	ofstream out("beads.out");
	ifstream in("beads.in");

	int size; string necklace;

	in >> size >> necklace;

	int redMax = 0, blueMax = 0;
	
	for (int currentBreak = 0; currentBreak < necklace.length(); currentBreak++) {
		int redCount = countConsecutive(breakAtSpot(currentBreak, necklace), 'r');
		int blueCount = countConsecutive(breakAtSpot(currentBreak, necklace), 'b');

		if (redCount > redMax) {
			redMax = redCount;
		}

		if (blueCount > blueMax) {
			blueMax = blueCount;
		}
	}

	cout << "red: " << redMax << "\nblue: " << blueMax << endl;
	cout << "total: " << redMax + blueMax;

	return 0;
}