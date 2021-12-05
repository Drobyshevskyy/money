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

	void setPound(int);
	int getPound();
	void setShilling(int);
	int getShilling();
	void setPence(int);
	int getPence();
	double getHalfPenny();
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

