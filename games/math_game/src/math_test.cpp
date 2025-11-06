#include <iostream>
#include <string>
#include <random>

using namespace std;

void generate_Random(int& a, int& b, int& ans) {
	random_device rd;

	std::uniform_int_distribution<int> dist(1, 10000);

	a = dist(rd);
	b = dist(rd);

	ans = a + b;
}

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
