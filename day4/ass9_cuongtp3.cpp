// Make by g++

#include <iostream>

using namespace std;

class CFraction
{
	private:
		int num;
		int den;
		
		int greatest_common_divisor(int a, int b);
		void simpl_fraction();
		
	public:
		CFraction(int init_num = 1, int init_den = 1);
		void my_print();

		friend CFraction operator + (const CFraction&, const CFraction&);
		friend CFraction operator - (const CFraction&, const CFraction&);
		friend CFraction operator * (const CFraction&, const CFraction&);
		friend CFraction operator / (const CFraction&, const CFraction&);	
};

/********************************************************************************************
* Function name: CFraction::CFraction()
* Description: Contructor function
* Input: int init_num, int init_den
* Output: None
********************************************************************************************/
CFraction::CFraction(int init_num, int init_den)
{
	this->num = init_num;
	this->den = init_den;
}

/********************************************************************************************
* Function name: CFraction::my_print()
* Description: Print fraction number
* Input: None
* Output: None
********************************************************************************************/
void CFraction::my_print()
{
	if(this->num == 0)
		cout << "= " << 0 << endl;
	
	else if(this->num == this->den)
		cout << "= " << 1 << endl;
	else if(this->den < 0)
		cout << "= " << 0 - (this->num) << "/" << 0 - this->den << endl;
	else
		cout << "= " << this->num << "/" << this->den << endl;
}

/********************************************************************************************
* Function name: CFraction::greatest_common_divisor()
* Description: Get greatest common divisor of num and den
* Input: num, den of fraction number
* Output: Greatest common divisor number
********************************************************************************************/
int CFraction::greatest_common_divisor(int a, int b)
{
	if (a % b != 0)
        return greatest_common_divisor(b, a % b);
    else
        return b;
}

/********************************************************************************************
* Function name: CFraction::simpl_fraction()
* Description: Simplest fraction number
* Input: None
* Output: None
********************************************************************************************/
void CFraction::simpl_fraction()
{
	int temp;
	temp = greatest_common_divisor(this->num, this->den);
	this->num = this->num / temp;
	this->den = this->den / temp;
}

/********************************************************************************************
* Function name: operator +
* Description: Add number
* Input: const CFraction& num1, const CFraction& num2
* Output: None
********************************************************************************************/
CFraction operator +(const CFraction& num1, const CFraction& num2)
{
	CFraction result;
	
	result.num = num1.num * num2.den + num1.den * num2.num;
	result.den = num1.den * num2.den;
	result.simpl_fraction();
	
	return result;
}

/********************************************************************************************
* Function name: operator -
* Description: Add number
* Input: const CFraction& num1, const CFraction& num2
* Output: None
********************************************************************************************/
CFraction operator -(const CFraction& num1, const CFraction& num2)
{
	CFraction result;
	
	result.num = num1.num * num2.den - num1.den * num2.num;
	result.den = num1.den * num2.den;
	result.simpl_fraction();
	
	return result;
}

/********************************************************************************************
* Function name: operator *
* Description: Multi number
* Input: const CFraction& num1, const CFraction& num2
* Output: None
********************************************************************************************/
CFraction operator *(const CFraction& num1, const CFraction& num2)
{
	CFraction result;
	
	result.num = num1.num * num2.num;
	result.den = num1.den * num2.den;
	result.simpl_fraction();
	
	return result;
}

/********************************************************************************************
* Function name: operator /
* Description:Div number
* Input: const CFraction& num1, const CFraction& num2
* Output: None
********************************************************************************************/
CFraction operator /(const CFraction& num1, const CFraction& num2)
{
	CFraction result;
	
	result.num = num1.num * num2.den;
	result.den = num1.den * num2.num;
	result.simpl_fraction();
	
	return result;
}

int main()
{
	CFraction result;
	int a;
	int b;
	int c;
	int d;
	do
	{	
		cout << "Enter Fraction 1: " << endl;
		cout << "num = ";
		cin >> a;
		cout << "den = ";
		cin >> b;	
	}while(b == 0);

	do
	{	
		cout << "Enter Fraction 2: " << endl;
		cout << "num = ";
		cin >> c;
		cout << "den = ";
		cin >> d;
	}while(d == 0);
	
	CFraction num_a(a,b);
	CFraction num_b(c,d);
	
	cout << "a + b";
	result = num_a + num_b;
	result.my_print();
	
	cout << "a - b";
	result = num_a - num_b;
	result.my_print();
	
	cout << "a * b";
	result = num_a * num_b;
	result.my_print();
	
	cout << "a / b";
	result = num_a / num_b;
	result.my_print();
	
	return 0;
}