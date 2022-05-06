#include <iostream>
using namespace std;

static int g_numElementOfArray;

int* get_even_num(int *arr, int *sz);

int main()
{
	int n = 0;
	int i;
	int *ptr = NULL;
	int *output_arr = NULL;
	int size = 0;
	cout <<"Enter number element of array n = ";
	cin >> g_numElementOfArray;
	
	ptr = new int[g_numElementOfArray];
	if(NULL == ptr)
	{
		cout << "Allowcate fail\n";
		return -1;
	}
	
	for(i = 0; i < g_numElementOfArray; i++)
	{
		cout << "Element: " << i << "= ";
		cin >> ptr[i];
	}
	
	output_arr = get_even_num(ptr, &size);
	cout << "Size: "<< size << endl;
	
	cout << "Output array: ";
	for(i = 0; i < size; i++)
	{
		cout << output_arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}



int* get_even_num(int *arr, int *sz)
{
	int i;
	int j = 0;
	int count;
	int *new_arr = NULL;
	
	for(i = 0; i < g_numElementOfArray; i++)
	{
		if(arr[i] % 2 == 0)
			(*sz) ++;
	}
	
	new_arr = new int[(*sz)];
	if(NULL == new_arr)
	{
		cout << "Allowcate fail\n";
		return NULL;
	}
	
	for(i = 0; i < g_numElementOfArray; i++)
	{
		if(arr[i] % 2 == 0)
		{
			new_arr[j] = arr[i];
			j++;
		}
	}
	
	return new_arr; 	
}