#include <iostream>
#include<string>
#include <cstring>

using namespace std;

class my_String
{
	private:
		char* str;
		
	public:
		my_String();
		friend my_String operator + (const my_String&, const my_String&);
		friend ostream& operator << (ostream&, my_String&);
		friend istream& operator >> (istream&, my_String&);
};

/********************************************************************************************
* Function name: my_String::my_String()
* Description: Contructor function
* Input: None
* Output: None
********************************************************************************************/
my_String::my_String()
{
	this->str = new char[50];
	memset(this->str, '\0', 50);
}

/********************************************************************************************
* Description: Over load +
* Input: const my_String& str_a, const my_String& str_b
* Output: None
********************************************************************************************/
my_String operator + (const my_String& str_a, const my_String& str_b)
{
	// my_String temp_str;
	// int i = 0;
	
	// for(i = 0; str_a.str[i] != '\0'; i++)
	// {
		// temp_str.str[i] = str_a.str[i];
	// }
	strcat(str_a.str, str_b.str);  // Theo em hiểu chỗ này đang thay đổi giá trị str_a trong khi mình truyền vào là const. Nhưng em biên dịch bằng g++ vẫn pass qua chỗ này
	return str_a;
}

/********************************************************************************************
* Description: Over load <<
* Input: const ostream& out_string_stream, my_String& str_out
* Output: None
********************************************************************************************/
ostream& operator << (ostream& out_string_stream, my_String& str_out)
{
	cout << str_out.str;
	return out_string_stream;
}

/********************************************************************************************
* Description: Over load >>
* Input: istream& in_string_stream, my_String& str_in
* Output: None
********************************************************************************************/
istream& operator >> (istream& in_string_stream, my_String& str_in)
{
	cin >> str_in.str;
	return in_string_stream;
}

int main()
{
	my_String temp_str1;
	my_String temp_str2;
	my_String temp_str3;
	
	cout << "Enter string 1:";
	cin >> temp_str1;
	
	cout << "Enter string 2:";
	cin >> temp_str2;
	
	cout << "Result after pair string:";
	temp_str3 = temp_str1 + temp_str2;
	
	cout << temp_str3 << endl;
	
	return 0;
}