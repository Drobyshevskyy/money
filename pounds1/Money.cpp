#include "Money.h"
#include <cstdlib>
#include <iostream>
using namespace std;
void Money::setPound(int m_pound) {
	pound = m_pound;
}
int Money::getPound() {
	if (!positive) {
		return -pound;
	}
	return pound;
}
void Money::setShilling(int m_shilling) {
	shilling = m_shilling;
}
int Money::getShilling() {
	if (!positive) {
		return -shilling;
	}
		return shilling;
}
void Money::setPence(int m_pence) {
	pence = m_pence;
}
int Money::getPence() {
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
	if ((pound > maxpound) || (pound < 0)) {
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
double Money::getHalfPenny() {
	if ((pound > 0) && (shilling > 0) && (pence > 0)) {
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
	if (shilling > 0) {
		shilling %= 20;
		pound+=(shilling / 20);
		
	}
	if (pence > 0) {
		pence %= 12;
		shilling +=(pence / 12);
	}
		cout << pound << "pd." << endl;
		cout << shilling << "sh." << endl;
		cout << pence << "p." << endl;
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
Money Money::operator + (const Money& secondmoney) const {
	int aPound = pound, saPound = secondmoney.pound;
	int aShilling = shilling, saShilling = secondmoney.shilling;
	int aPence = pence, saPence = secondmoney.pence;
	if ((pound < 0) && (shilling < 0) && (pence < 0)) {
		aPound = -pound;
		aShilling = -shilling;
		aPence = -pence;
	}
	if ((secondmoney.pound < 0) && (secondmoney.shilling < 0) && (secondmoney.pence < 0)) {
		saPound = -secondmoney.pound;
		saShilling = -secondmoney.shilling;
		saPence = -secondmoney.pence;
	}
	Money aMoney(aPound + saPound, aShilling + saShilling, aPence + saPence, true);
	return aMoney;
}
Money Money::operator - (const Money& secondmoney) const {
	int dPound = pound, sdPound = secondmoney.pound;
	int dShilling = shilling, sdShilling = secondmoney.shilling;
	int dPence = pence, sdPence = secondmoney.pence;
	if ((pound < 0) && (shilling < 0) && (pence < 0)) {
		dPound = -pound;
		dShilling = -shilling;
		dPence = -pence;
	}
	if ((secondmoney.pound < 0) && (secondmoney.shilling < 0) && (secondmoney.pence < 0)) {
		sdPound = -secondmoney.pound;
		sdShilling = -secondmoney.shilling;
		sdPence = -secondmoney.pence;
	}
	Money dMoney(dPound - sdPound, dShilling - sdShilling, dPence - sdPence, true);
	return dMoney;
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