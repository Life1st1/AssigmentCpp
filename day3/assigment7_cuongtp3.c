#include <iostream>
using namespace std;

float myPlus(float a, float b);  
float myMinus(float a, float b); 
float multiply(float a, float b); 
float divide(float a, float b);
void operation(float a, float b, float (*p2Func)(float, float));

int main()
{
	float a;
	float b;
	float result;
	
    cout << "Enter a,b" << endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	
	cout << "a + b. ";
	operation(a,b,myPlus);
	
	cout << "a - b. ";
	operation(a,b,myMinus);
	
	cout << "a * b. ";
	operation(a,b,multiply);
	
	cout << "a / b. ";
	operation(a,b,divide);
	
	return 0;
}

/**********************************************************************************************
* Funtion name: myPlus
* Description: Add 2 number
* Input: float a, float b
* Return: result of adding 2 number
***********************************************************************************************/
float myPlus(float a, float b) // plus -> myPlus, because of conflict with library
{
	float sum;
	sum = a + b;
	return sum;
}

/**********************************************************************************************
* Funtion name: myMinus
* Description: Minus 2 number
* Input: float a, float b
* Return: result of minus 2 number
***********************************************************************************************/
float myMinus(float a, float b) // minus -> myMinus, because of conflict with library
{
	float min;
	min = a - b;
	return min;
}

/**********************************************************************************************
* Funtion name: multiply
* Description: multiply 2 number
* Input: float a, float b
* Return: result of multiply 2 number
***********************************************************************************************/
float multiply(float a, float b)
{
	float mul;
	mul = a * b;
	return mul;
}

/**********************************************************************************************
* Funtion name: divide
* Description: divide 2 number
* Input: float a, float b
* Return: result of divide 2 number
***********************************************************************************************/
float divide(float a, float b)
{
	float div;
	div = a / b;
	return div;
}

/**********************************************************************************************
* Funtion name: operation
* Description: caculate 2 number
* Input: float a, float b, float (*p2Func)(float, float): funtion pointer
* Return: result of caculation
***********************************************************************************************/
void operation(float a, float b, float (*p2Func)(float, float))
{
	cout << "Result: " << p2Func(a,b) << endl;
}