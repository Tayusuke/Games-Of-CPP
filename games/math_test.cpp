#include <iostream>
#include <string>
#include <random>

using namespace std;

int main() {
	string your_answer = "";
	random_device rd;

	std::uniform_int_distribution<int> dist(1, 10000);

	int number_a = dist(rd);
	int number_b = dist(rd);

	int the_answer = number_a + number_b;

	bool isFirst = true;

	while (your_answer != to_string(the_answer)) {
		if (!isFirst) {
			cout << "Incorrect..." << endl;
		}

		cout << number_a << " + " << number_b << " = ?" << endl;
		cin >> your_answer;
		isFirst = false;
	}

	cout << "Correct!!!" << endl;
}
