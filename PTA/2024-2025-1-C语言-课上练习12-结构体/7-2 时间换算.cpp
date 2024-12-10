#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int hh, mm, ss, n;
	char colon;

	// Read the input time in hh:mm:ss format
	cin >> hh >> colon >> mm >> colon >> ss;
	// Read the number of seconds to add
	cin >> n;

	// Add the seconds
	ss += n;

	// Handle overflow of seconds
	if (ss >= 60) {
		mm += ss / 60;
		ss %= 60;
	}

	// Handle overflow of minutes
	if (mm >= 60) {
		hh += mm / 60;
		mm %= 60;
	}

	// Handle overflow of hours
	if (hh >= 24) {
		hh %= 24;
	}

	// Output the result in hh:mm:ss format
	cout << setw(2) << setfill('0') << hh << ":"
		<< setw(2) << setfill('0') << mm << ":"
		<< setw(2) << setfill('0') << ss << endl;

	return 0;
}