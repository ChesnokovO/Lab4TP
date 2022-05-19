#include <iostream>
#include <random>
#include <time.h>
#include "shell.h"
#include "correct.h"
#include "linklist.h"

template<typename T>
void list() {
	int select;
	LinkList<T> l1, l2;
	LinkList<T>* temp = nullptr;
	do {
		std::cout << "\nFirst List: \n" << l1 <<
			"\nSecond List: \n" << l2 << std::endl;
		std::cout << "\n1. !=\n"
			"2. ==\n"
			"3. Push\n"
			"4. Exit\n";

		select = correct<int>();

		switch (select)
		{
		case 1:
			try {
				l1 != l2;
			}
			catch (const char* m) {
				std::cout << m << '\n';
			}

			break;
		case 2:
			try {
				l1 == l2;
			}
			catch (const char* m) {
				std::cout << m << '\n';
			}

		break;
		case 3:
		{
			do {
				std::cout << "Choose list (1 or 2):\n";
				select = correct<int>();
			} while (select <= 0 || select >= 3);
			(select == 1) ? temp = &l1 : temp = &l2;
			std::cout << "Enter a value: ";
			T value = correct<T>();
			*temp = *temp + value;
			temp = nullptr;
		}
			break;
		case 4:
			return;
			break;
		default:
			break;
		}

	} while (true);
}


int main() {
    srand(time(NULL));
	int select;
	do {
		std::cout << "1. Link List\n"
			"2. Shell Sorting\n"
			"3. Exit\n";
		select = correct<int>();
		switch (select)
		{
		case 1:
			std::cout << "Select the data type\n"
				"1. Int\n"
				"2. Float\n"
				"3. Double\n"
				"4. Char\n"
				"5. Char*\n"
				"6. Exit\n";

			select = correct<int>();

			switch (select)
			{
			case 1:
				list<int>();
				break;
			case 2:
				list<float>();
				break;
			case 3:
				list<double>();
				break;
			case 4:
				list<char>();
				break;
			case 5:
				list<char*>();
				break;
			default:
				break;
			}



			break;
		case 2:
		{
			std::cout << "Select type\n"
				"1. Int\n"
				"2. Float\n"
				"3. Double\n"
				"4. Char\n"
				"5. Char*\n"
				"6. Exit\n";

			select = correct<int>();
			switch (select)
			{
			case 1:
				shellSort<int>();
				break;
			case 2:
				shellSort<float>();
				break;
			case 3:
				shellSort<double>();
				break;
			case 4:
				shellSort<char>();
				break;
			case 5:
				shellSort<char*>();
				break;
			default:
				break;
			}
		}
		break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	} while (true);


	return 0;
}