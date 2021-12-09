#include <iostream>
#include "Money.h"

using namespace std;

int main()
{
	try {
		Money firstMoney(0, 0, 10), secondMoney(1, 0, 0);
		Money addition;
		cout << "amount1 =" << endl;
		firstMoney.print();
		cout << endl;
		cout << "amount2 =" << endl;
		secondMoney.print();
		cout << endl;
		cout << "amount1 > amount2  " << (firstMoney > secondMoney) << endl;
		cout << "amount1 < amount2  " << (firstMoney < secondMoney) << endl;
		cout << "amount1 >= amount2  " << (firstMoney >= secondMoney) << endl;
		cout << "amount1 <= amount2  " << (firstMoney <= secondMoney) << endl;
		cout << "amount1 != amount2  " << (firstMoney != secondMoney) << endl;
		cout << "amount1 == amount2  " << (firstMoney == secondMoney) << endl << endl;
		cout << "amount1 + amount2 =" << endl;
		addition = firstMoney + secondMoney;
		addition.print();
		cout << endl;
		cout << "amount1 - amount2 =" << endl;
		addition = firstMoney - secondMoney;
		addition.print();
		cout << endl;
		addition += secondMoney;
		cout << "(amount1 - amount2) += amount2  amount1 =" << endl;
		addition.print();
		cout << endl;
		addition -= secondMoney;
		cout << "amount1 -= amount2  amount1 - amount2 =" << endl;
		addition.print();
		cout << endl;
		addition = -addition;
		cout << "(amount1 - amount2) = -(amount1 - amount2)  -(amount1 - amount2) =" << endl;
		addition.print();
		cout << endl;


	}
	catch (const char* exception) {
		cout << exception;
	}

	system("PAUSE");
	return 0;
}