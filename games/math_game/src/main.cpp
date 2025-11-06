#include "math.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	string your_answer = "";

	int number_a, number_b, the_answer;

	generate_Random(number_a, number_b, the_answer);

	bool isFirst = true;

	while (!(your_answer == "y")) {
		while (your_answer != to_string(the_answer)) {
			if (!isFirst) {
				cout << "Incorrect..." << endl << endl;
			}

			cout << number_a << " + " << number_b << " = ?" << endl << endl;
			cin >> your_answer;
			cout << endl;
			isFirst = false;
		}

		cout << "Correct!!!" << endl << endl;
		isFirst = true;

		generate_Random(number_a, number_b, the_answer);
		cout << "Do you want to exit this test? y/n" << endl << endl;
		cin >> your_answer;
		cout << endl;
	}
}
