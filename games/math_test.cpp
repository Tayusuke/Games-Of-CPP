#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
	string your_answer = "";
	srand(time(nullptr));
	int number_a = rand() % 10000 + 1;
	int number_b = rand() % 10000 + 1;

	int the_answer = number_a + number_b;

	bool isFirst = true;

	while (your_answer != to_string(the_answer)) {
		if (!isFirst) {
			cout << "Incorrect..." << endl;
		}

		cout << number_a << " + " << number_b << " = ?" << endl;
		cin >> your_answer;
	}

	cout << "Correct!!!" << endl;
}
