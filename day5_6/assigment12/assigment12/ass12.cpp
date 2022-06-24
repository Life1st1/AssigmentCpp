#include <iostream>
#include "ass12.h"

using namespace std;

template <class T>
int CStacks<T>::pop(T *result){
	int err = NO_ERR;
	if(Top < 0){
		cout << "Stacks is empty!!!" << endl;
		err = ERR;
	}
	else{
		*result = stack_element[Top];
		Top--;
	}
	
	return err;
}

template <class T>
void CStacks<T>::push(T data){
	Top++;
	stack_element[Top] = data;
}

int main(){
	float temp;
	float data;
	int num;
	int index = 0;
	int err = NO_ERR;
	CStacks<float> work_stack;
	cout << "Enter number of element(n < 10) n = ";
	cin >> num;
	
	while(num--){
		cout << "a[" << index << "] = ";
		index ++;
		cin >> data;
		work_stack.push(data);
	}
	cout << "Pop data of stack" << endl;
	while(err){
		err = work_stack.pop(&temp);
		if(err == ERR){
			break;
		}
		else{
			index--;
			cout << "a[" << index << "] = " << temp << endl;
		}
			
	}

	return 0;
}