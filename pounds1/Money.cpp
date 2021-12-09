#include "Money.h"
#include <cstdlib>
#include <iostream>
using namespace std;
void Money::setPound(int m_pound) { 
	pound = m_pound;
}
int Money::getPound() const {
	if (!positive) {
		return -pound;
	}
	return pound;
}
void Money::setShilling(int m_shilling) {
	shilling = m_shilling;
}
int Money::getShilling() const {
	if (!positive) {
		return -shilling;
	}
		return shilling;
}
void Money::setPence(int m_pence) {
	pence = m_pence;
}
int Money::getPence() const {
	if (!positive) {
		return -pence;
	}
	return pence;
}
Money::Money() {
	pound = 0;
	shilling = 0;
	pence = 0;
	positive = true;
}
Money::Money(int m_pound, int m_shilling, int m_pence, bool m_positive) {
	pound = m_pound;
	shilling = m_shilling;
	pence = m_pence;
	positive = m_positive;
}
Money::Money(int m_pound, int m_shilling, int m_pence) {
	pound = m_pound;
	shilling = m_shilling;
	pence = m_pence;
	const int maxpound = 1000000000;
	if ((pound > maxpound)||(pound<0)) {
		throw "wrong amount of pounds";
	}
	if ((shilling >= 20) || (shilling < 0)) {
		throw "wrong amount of shillings";
	}
	if ((pence >= 12) || (pence < 0)) {
		throw "wrong amount of pence";
	}
	if (((pence - (int)pence) != 0) && ((pence - (int)pence) != 0.5)) {
		throw "wrong accuracy";
	}
}
double Money::getHalfPenny() const {
	if (positive) {
		return pence * 2 + shilling * 24 + pound * 480;
	}
	else {
		return -pence * 2 - shilling * 24 - pound * 480;
	}
}
void Money::print() {
	if ((pound == 0) && (shilling == 0) && (pence == 0)) {
		cout << "0p." << endl;
	}
	
		cout << pound << "pd." << endl;
		cout << shilling << "sh." << endl;
		cout << pence << "p." << endl;
}
Money Money::transformToMoney(double halfpenny) {
	pence = ((double)((int)halfpenny % 24) / 2);
	halfpenny = (int)halfpenny / 24;
	shilling = ((int)halfpenny % 20);
	halfpenny = (int)halfpenny / 20;
	pound = halfpenny;
	return *this;
}
bool Money::operator>(Money secondmoney) {
	return this->getHalfPenny() > secondmoney.getHalfPenny();
}
bool Money::operator<(Money secondmoney) {
	return this->getHalfPenny() < secondmoney.getHalfPenny();
}
bool Money::operator>=(Money secondmoney) {
	return this->getHalfPenny() >= secondmoney.getHalfPenny();
}
bool Money::operator<=(Money secondmoney) {
	return this->getHalfPenny() <= secondmoney.getHalfPenny();
}
bool Money::operator!=(Money secondmoney) {
	return this->getHalfPenny() != secondmoney.getHalfPenny();
}
bool Money::operator==(Money secondmoney) {
	return this->getHalfPenny() == secondmoney.getHalfPenny();
}
Money Money::operator+(const Money& secondmoney) const {
	double hpennies = this->getHalfPenny() + secondmoney.getHalfPenny();
	Money money;
	money.transformToMoney(hpennies);
	return money;
}
Money Money::operator-(const Money& secondmoney) const {
	double hpennies = this->getHalfPenny() - secondmoney.getHalfPenny();
	Money money;
	money.transformToMoney(hpennies);
	return money;
}
Money& Money::operator+=(const Money& secondMoney) {
	*this = *this + secondMoney;
	return *this;
}
Money& Money::operator-=(const Money& secondMoney) {
	*this = *this - secondMoney;
	return *this;
}
Money Money::operator-() {
	return Money(pound, shilling, pence, !positive);
}