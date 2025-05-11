//Matteo Podesta
//Lab #9

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

int FractionCount = 0;
void printFractionCount();

class FractionException
{
public:
	FractionException()
	{
		exceptionErrorMessage = "UNKNOWN ERROR";
	}


	FractionException(string errorMessage)
	{
		exceptionErrorMessage = errorMessage;
	}


	string what()
	{
		return exceptionErrorMessage;
	}


private:
	string exceptionErrorMessage;
};
class Fraction {
public:
	Fraction();
	Fraction(Fraction& Fraction);
	Fraction(int numeratorInput, int denominatorInput, int wholeInput);
	Fraction(int numeratorInput, int denominatorInput);
	Fraction(int wholeInput);
	~Fraction();

	void setNumerator(int input) { numerator = input; }
	void setDenominator(int input) { denominator = input; }

	void setFraction(int numeratorInput, int denominatorInput, int wholeInput);
	void setFraction(int NumeratorInput, int DenominatorInput);
	void setFraction(int NumeratorInput);

	void setDefault() { setFraction(DEFAULT_NUMERATOR, DEFAULT_DENOMINATOR, DEFAULT_WHOLE); }

	void catchFunction(int Numerator, int Nenominator, int Whole);

	bool operator==(Fraction const& otherFraction);
	const Fraction& operator=(const Fraction& fractionObject);

	friend ostream& operator<<(ostream& output, const Fraction& fractionObject);
	friend istream& operator>>(istream& input, Fraction& fractionObject);

	Fraction operator*(const Fraction& fractionObject) const;
	Fraction operator/(const Fraction& fractionObject) const;

	Fraction operator+(const Fraction& fractionObject) const;
	Fraction operator+(const int& intObject);

	Fraction operator-(const Fraction& fractionObject) const;
	Fraction operator-(const int& intObject) const;
	friend Fraction operator-(const int& intObject, const Fraction& fractionObject);

	string toString();

private:
	const int DEFAULT_NUMERATOR = 1;
	const int DEFAULT_DENOMINATOR = 1;
	const int DEFAULT_WHOLE = 0;

	int numerator = DEFAULT_NUMERATOR;
	int denominator = DEFAULT_DENOMINATOR;
	int whole = DEFAULT_WHOLE;
};

enum {
	MULTIPLY = 1,
	DIVIDE,
	PLUS,
	MINUS,
	QUIT
};

int main() {

	int input = 0;


	while (input != QUIT) {

		cout << "\nMenu:\n"
			"1. Multiply (*) demo\n"
			"2. Divide (/) demo\n"
			"3. Plus (+) demo\n"
			"4. Minus (-) demo\n"
			"5. Quit\n"
			"Input: ";


		cin >> input;

		switch (input) {
		case MULTIPLY:
		{

			Fraction cow(1, 3, 2);
			Fraction gambling(7, 5, 0);
			Fraction Cheese;
			Cheese = (cow * gambling);
			cout << cow.toString() << " * " << gambling.toString() << " = " << Cheese.toString() << endl;

		}
		break;
		case DIVIDE:
		{

			Fraction cow(4, 6, 8);
			Fraction gambling(1, 1, 0);
			Fraction Cheese;
			Cheese = (cow / gambling);
			cout << cow.toString() << " / " << gambling.toString() << " = " << Cheese.toString() << endl;
			
		}
		break;
		case PLUS:
		{
			
			Fraction cow(1, 3, 0);
			Fraction gambling(1, 4, 5);
			Fraction Cheese;
			Cheese = (cow + gambling);
			cout << cow.toString() << " + " << gambling.toString() << " = " << Cheese.toString() << endl;

			Fraction milk;
			milk = (cow + 2);
			cout << cow.toString() << " + " << 2 << " = " << milk.toString() << endl;

		}
		break;
		case MINUS:
		{

			Fraction cow(2, 3, 5);
			Fraction gambling(1, 4, 5);
			Fraction Cheese;
			Cheese = (cow - gambling);
			cout << cow.toString() << " - " << gambling.toString() << " = " << Cheese.toString() << endl;

			Fraction milk;
			milk = (cow - 2);
			cout << cow.toString() << " - " << 2 << " = " << milk.toString() << endl;

			Fraction trees;
			trees = (10 - cow);
			cout << 10 << " - " << cow.toString() << " = " << trees.toString() << endl;

		}
		break;
		case QUIT:
			break;
		default:
			cout << "Invalid choice, try again\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}

	}
}

Fraction::Fraction() {
	FractionCount++;
	setFraction(DEFAULT_NUMERATOR, DEFAULT_DENOMINATOR, DEFAULT_WHOLE);
}
Fraction::~Fraction() {
	numerator = 0;
	denominator = 1;
	FractionCount--;
}
Fraction::Fraction(int NumeratorInput, int DenominatorInput, int WholeInput) {
	FractionCount++;
	setFraction(NumeratorInput, DenominatorInput, WholeInput);
}
Fraction::Fraction(int NumeratorInput, int DenominatorInput) {
	FractionCount++;
	setFraction(NumeratorInput, DenominatorInput, whole);
}
Fraction::Fraction(int NumeratorInput) {
	FractionCount++;
	setFraction(NumeratorInput, denominator, whole);
}
Fraction::Fraction(Fraction& Fraction) {
	FractionCount++;
	Fraction.numerator = numerator;
	Fraction.denominator = denominator;
	Fraction.whole = whole;
}

string Fraction::toString() {

	ostringstream text;

	text << whole << " " << numerator << "/" << denominator;

	return text.str();

}

void Fraction::catchFunction(int Numerator, int Denominator, int Whole) {
	
	if (Numerator <= 0 && Denominator <= 0 && Whole <= 0) {
		setDefault();
		throw FractionException("FORMAT ERROR: improper fraction, all numbers are invalid");
	}

	if ((Numerator > Denominator) && (Whole > 0)) {
		setDefault();
		throw FractionException("FORMAT ERROR: fraction is improper");
	}

	if (Numerator <= 0 && Denominator <= 0) {
		Numerator = numerator;
		Denominator = denominator;
		throw FractionException("NUMERATOR & DENOMINATOR ERROR: numerator and denominator are invalid");
	}

	if (Numerator <= 0) {
		Numerator = numerator;
		throw FractionException("NUMERATOR ERROR: numerator is invalid");
	}
	if (Denominator <= 0) {
		Denominator = denominator;
		throw FractionException("DENOMINATOR ERROR: denominator is invalid");
	}
	if (Whole < 0) {
		Whole = whole;
		throw FractionException("WHOLE ERROR: whole is invalid");
	}
}
void Fraction::setFraction(int numeratorInput, int denominatorInput, int wholeInput) {

	try {
		catchFunction(numeratorInput, denominatorInput, wholeInput);
		numerator = numeratorInput;
		denominator = denominatorInput;
		whole = wholeInput;
	}
	catch (FractionException FractionExceptionObject) {
		cout << FractionExceptionObject.what() << endl;
	}
	catch (...) {
		FractionException Object;
		cout << Object.what() << endl;

	}



}
void Fraction::setFraction(int NumeratorInput, int DenominatorInput) {
	setFraction(NumeratorInput, DenominatorInput, whole);
}
void Fraction::setFraction(int NumeratorInput) {
	setFraction(NumeratorInput, denominator, whole);
}


void printFractionCount() {
	cout << "Current amount of Fraction classes in memory is: " << FractionCount << endl;
}

bool Fraction::operator==(Fraction const& otherFraction) {

	return (numerator + (whole * denominator)) * otherFraction.denominator == (otherFraction.numerator + (otherFraction.whole * otherFraction.denominator)) * denominator;

}
const Fraction& Fraction::operator=(const Fraction& fractionObject) {

	if (this != &fractionObject) {

		setFraction(fractionObject.numerator, fractionObject.denominator, fractionObject.whole);

	}

	return *this;

}

ostream& operator<<(ostream& output, const Fraction& fractionObject) {

	string tempString = "";
	int tempWhole = fractionObject.numerator / fractionObject.denominator;
	int tempNumber = fractionObject.numerator % fractionObject.denominator;

	tempString += ((tempWhole > 0) ? (to_string(tempWhole)) : "");
	tempString += ((tempWhole > 0) ? (" = " + to_string(fractionObject.denominator * tempWhole)) + "/" + to_string(fractionObject.denominator) : "");


	tempString += ((fractionObject.whole > 0) ? (to_string(fractionObject.whole) + " ") : "");
	tempString += ((tempNumber > 0) ? (to_string(tempNumber)) + "/" + to_string(fractionObject.denominator) : "");
	tempString += ((tempNumber > 0) ? (" = " + to_string((fractionObject.denominator * fractionObject.whole) + fractionObject.numerator)) + "/" + to_string(fractionObject.denominator) : "");


	output << tempString;

	return output;

}
istream& operator>>(istream& input, Fraction& fractionObject) {

	int tempWhole;
	int tempNumerator;
	int tempDenominator;

	input >> tempWhole >> tempNumerator >> tempDenominator;

	try {

		if (input.fail()) {
			input.clear();
			input.ignore(numeric_limits<streamsize>::max(), '\n');
			fractionObject.setFraction(tempNumerator, tempDenominator, tempWhole);
			throw FractionException("Invalid input format.");
		}

		fractionObject.catchFunction(tempNumerator, tempDenominator, tempWhole);
		
		fractionObject.whole = tempWhole;
		fractionObject.numerator = tempNumerator;
		fractionObject.denominator  = tempDenominator;
		
		return input;
	}
	catch (FractionException FractionExceptionObject) {
		cout << FractionExceptionObject.what() << endl;
	}
	catch (...) {

		FractionException Object;
		cout << Object.what() << endl;
	}


}

Fraction Fraction::operator*(const Fraction& fractionObject) const
{

	Fraction multiplyF;

	try {

		multiplyF.numerator = (fractionObject.numerator + (fractionObject.whole * fractionObject.denominator)) * (numerator + (whole * denominator));
		multiplyF.denominator = fractionObject.denominator * denominator;

		return multiplyF;

	}
	catch (FractionException FractionExceptionObject) {
		cout << FractionExceptionObject.what() << endl;
	}
	catch (...) {

		FractionException Object;
		cout << Object.what() << endl;
	}
}
Fraction Fraction::operator/(const Fraction& fractionObject) const
{

	Fraction divideF;

	try{
		
		divideF.numerator = (numerator + (whole * denominator)) / (fractionObject.numerator + (fractionObject.whole * fractionObject.denominator));
		divideF.denominator = denominator / fractionObject.denominator;

		return divideF;

	}
	catch (FractionException FractionExceptionObject) {
		cout << FractionExceptionObject.what() << endl;
	}
	catch (...) {

		FractionException Object;
		cout << Object.what() << endl;
	}
}

Fraction Fraction::operator+(const Fraction& fractionObject) const {

	Fraction additionF;

	try {
		if (fractionObject.denominator == denominator) {

			additionF.numerator = fractionObject.numerator + numerator;
			additionF.denominator = denominator;
		}
		else {

			additionF.numerator = (fractionObject.numerator * denominator) + (numerator * fractionObject.denominator);
			additionF.denominator = fractionObject.denominator * denominator;

		}
		
		additionF.whole = fractionObject.whole + whole;

		return additionF;

	}
	catch (FractionException FractionExceptionObject) {
		cout << FractionExceptionObject.what() << endl;
	}
	catch (...) {

		FractionException Object;
		cout << Object.what() << endl;
	}

}
Fraction Fraction::operator+(const int& intObject) {

	Fraction additionF;
	

	try {

		additionF.denominator = denominator;

		if (whole == 0) {

			additionF.numerator = numerator + (intObject * denominator);

		}
		else {

			additionF.whole = whole + intObject;
			additionF.numerator = numerator;

		}
		

		return additionF;

	}
	catch (FractionException FractionExceptionObject) {
		cout << FractionExceptionObject.what() << endl;
	}
	catch (...) {

		FractionException Object;
		cout << Object.what() << endl;
	}

}

Fraction Fraction::operator-(const Fraction& fractionObject) const {

	Fraction minusF;

	try {

		if (fractionObject.denominator == denominator) {

			minusF.numerator = numerator- fractionObject.numerator;
			minusF.denominator = denominator;
		}
		else {

			minusF.numerator = (numerator * fractionObject.denominator) - (fractionObject.numerator * denominator);
			minusF.denominator = fractionObject.denominator * denominator;

		}

		minusF.whole = fractionObject.whole - whole;

		
		
		

		return minusF;

	}
	catch (FractionException FractionExceptionObject) {
		cout << FractionExceptionObject.what() << endl;
	}
	catch (...) {

		FractionException Object;
		cout << Object.what() << endl;
	}

}
Fraction Fraction::operator-(const int& intObject) const {

	Fraction minusF;


	try {

		minusF.denominator = denominator;

		if (whole == 0) {

			minusF.numerator = numerator - (intObject * denominator);

		}
		else {

			minusF.whole = whole - intObject;
			minusF.numerator = numerator;

		}


		return minusF;

	}
	catch (FractionException FractionExceptionObject) {
		cout << FractionExceptionObject.what() << endl;
	}
	catch (...) {

		FractionException Object;
		cout << Object.what() << endl;
	}

}
Fraction operator-(const int& intObject, const Fraction& fractionObject) {

	Fraction minusF(intObject);

	try {

		minusF.denominator = fractionObject.denominator;
		minusF.numerator = (intObject * fractionObject.denominator) - (fractionObject.numerator + (fractionObject.whole * fractionObject.denominator));

		return minusF;

	}
	catch (FractionException FractionExceptionObject) {
		cout << FractionExceptionObject.what() << endl;
	}
	catch (...) {

		FractionException Object;
		cout << Object.what() << endl;
	}

}

/*
TEST RUN - ONLY ONE DUE DO VALUES BEING HARD CODED


Menu:
1. Multiply (*) demo
2. Divide (/) demo
3. Plus (+) demo
4. Minus (-) demo
5. Quit
Input: 1
2 1/3 * 0 7/5 = 0 49/15

Menu:
1. Multiply (*) demo
2. Divide (/) demo
3. Plus (+) demo
4. Minus (-) demo
5. Quit
Input: 2
8 4/6 / 0 1/1 = 0 52/6

Menu:
1. Multiply (*) demo
2. Divide (/) demo
3. Plus (+) demo
4. Minus (-) demo
5. Quit
Input: 3
0 1/3 + 5 1/4 = 5 7/12
0 1/3 + 2 = 0 7/3

Menu:
1. Multiply (*) demo
2. Divide (/) demo
3. Plus (+) demo
4. Minus (-) demo
5. Quit
Input: 4
5 2/3 - 5 1/4 = 0 5/12
5 2/3 - 2 = 3 2/3
10 - 5 2/3 = 0 13/3

Menu:
1. Multiply (*) demo
2. Divide (/) demo
3. Plus (+) demo
4. Minus (-) demo
5. Quit
Input: 9
Invalid choice, try again

Menu:
1. Multiply (*) demo
2. Divide (/) demo
3. Plus (+) demo
4. Minus (-) demo
5. Quit
Input: a
Invalid choice, try again

Menu:
1. Multiply (*) demo
2. Divide (/) demo
3. Plus (+) demo
4. Minus (-) demo
5. Quit
Input: 12
Invalid choice, try again

Menu:
1. Multiply (*) demo
2. Divide (/) demo
3. Plus (+) demo
4. Minus (-) demo
5. Quit
Input: 5

C:\Users\Matteo\source\repos\Lab 9 Fractions\x64\Debug\Lab 9 Fractions.exe (process 13380) exited with code 0.
Press any key to close this window . . .
---------------------------------------------------------------------------------------------------------------

ALL VALUES WERE CHECKED FOR MATHMATICAL ACCURACY


*/