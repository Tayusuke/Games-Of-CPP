#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	int your_answer{};

	bool isFirst = true;

	srand(time(nullptr));

	int the_answer = rand() % 9 + 1;
	
	while (your_answer != the_answer) {
		if (!isFirst) {
			cout << "✖" << endl;
		}
		cout << "数を当ててみてください(1～9):";
		cin >> your_answer;
		isFirst = false;
	}

	cout << "◎正解！答えは... " << the_answer << " !" << endl;
}
