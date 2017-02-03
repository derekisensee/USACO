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

int countConsecutive(string necklace, char color) {
	int count = 0; // , whiteCount = 0, whiteSpot = 0;
	replace(necklace.begin(), necklace.end(), 'w', color);

	for (int i = 0; i < necklace.length() - 1; i++) {
		if ((necklace.at(i) == color && necklace.at(i + 1) == color)) {
			count++;
		}
		/*if (i + 1 != necklace.length() && necklace.at(i) == color && necklace.at(i + 1) == 'w') {
			whiteCount = 0;
			whiteCount++;
			bool trueWhile = true;
			whiteSpot = i;

			while (trueWhile) {
				if (whiteSpot != necklace.length() - 1 && necklace.at(whiteSpot + 1) == 'w') {
					whiteCount++;
					whiteSpot++;
				}
				else {
					trueWhile = false;
				}
			}
		}
		whiteSpot = 0;*/
	}
	//cout << necklace << "\n" << "count: " << count << " white count: " << whiteCount << endl;
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