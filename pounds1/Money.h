#pragma once
class Money
{
private:
	int pound;
	int shilling;
	int pence;
	int halfpenny;
	bool positive;
	Money(int, int, int, bool);
public:
	Money transformToMoney(double);
	void setPound(int);
	int getPound() const;
	void setShilling(int);
	int getShilling() const;
	void setPence(int);
	int getPence() const;
	double getHalfPenny() const;
	void print();
	Money();
	Money(int, int, int);
	bool operator > (Money);
	bool operator < (Money);
	bool operator >= (Money);
	bool operator <= (Money);
	bool operator == (Money);
	bool operator != (Money);
	Money operator + (const Money&) const;
	Money operator - (const Money&) const;
	Money& operator += (const Money&);
	Money& operator -= (const Money&);
	Money operator - ();

};

