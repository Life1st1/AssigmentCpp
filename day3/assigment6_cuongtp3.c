#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define ERROR 0
#define SUCCESS 1

bool importData(int*** pArr, int szRow, int szCol);
void freeMem(int** pArr, int szRow, int szCol);
int** add2Matrix(int** pArr1, int** pArr2, int szRow, int szCol);
void printMatrix(int** pArr, int szRow, int szCol);

int main()
{
	int *a;
	char *b;
	int c;
	int nCol;
	int nRow;
	int nCol2;
	int nRow2;
	int **m_pArr1 = NULL;
	int **m_pArr2 = NULL;
	int **m_pArr3 = NULL;
	int i = 0;
	int j = 0;
	int ret;
	
	cout <<  "Enter number of ROW and Colum array 1" << endl;
	cout << "Col: ";
	cin >> nRow;
	cout << "Row: ";
	cin >> nCol;
	ret = importData(&m_pArr1, nRow, nCol);
	
	cout <<  "Enter number of ROW and Colum array 2" << endl;
	cout << "Col: ";
	cin >> nRow2;
	cout << "Row: ";
	cin >> nCol2;
	ret = importData(&m_pArr2, nRow2, nCol2);
	
	if(nRow != nRow2 || nCol != nCol2)
	{
		cout << "2 matric not match row and colum!" << endl;
	}
	else
	{
		m_pArr3 = add2Matrix((int**)m_pArr1, (int**)m_pArr2, nRow, nCol);
		
		cout << "Sum result 2 matric:" << endl;
		printMatrix((int**)m_pArr3, nRow, nCol);
	}
	
	freeMem((int**)m_pArr1, nRow, nCol);
	freeMem((int**)m_pArr2, nRow, nCol);
	return ret;
}



/**********************************************************************************************
* Funtion name: importData
* Description: Alocalte 2way array
* Input: int szRow, int szCol
* Output: int*** pArr: pointer point to 2way array
* Return: 0 -> allocate fail; 1 -> allocate success
***********************************************************************************************/
bool importData(int*** pArr, int szRow, int szCol)
{
	bool ret = SUCCESS;
	int i = 0;
	int j = 0;
	int data;
	int** temp_pArr = NULL;
	
	temp_pArr = (int**)malloc(szCol * sizeof(int*));
	if(temp_pArr == NULL)
	{
		return ret = ERROR;
	}
	
	for(i = 0; i < szCol; i++)
	{
		temp_pArr[i] = (int*)malloc(szRow * sizeof(int));
		if(temp_pArr[i] == NULL)
		{
			return ret = ERROR;
		}
		for(j = 0; j < szRow ; j++)
		{
			cout << "a[" << i << "][" << j << "] = "; 
			cin >> data;
			*((int*)temp_pArr[i] + j) = data;
		}
	}
	*pArr = (int**)temp_pArr;
	return ret;
}

/**********************************************************************************************
* Funtion name: add2Matrix
* Description: Add 2 matric
* Input: int** pArr1, int** pArr2, int szRow, int szCol
* Output: pointer point to sum of 2 matric
***********************************************************************************************/
int** add2Matrix(int** pArr1, int** pArr2, int szRow, int szCol)
{
	int** resultArr;
	int i; 
	int j;
	
	for(i = 0; i < szCol; i++)
	{
		for(j = 0; j < szRow; j++)
		{
			*((int*)pArr1[i] + j) = *((int*)pArr1[i] + j) + *((int*)pArr2[i] + j);
		}
	}
	
	return pArr1;
}

/**********************************************************************************************
* Funtion name: printMatrix
* Description: print matric
* Input: int** pArr, int szRow, int szCol
* Output: Matric image
***********************************************************************************************/
void printMatrix(int** pArr, int szRow, int szCol)
{
	int i = 0;
	int j = 0;
	
	for(i = 0; i < szCol; i++)
	{
		for(j = 0; j < szRow; j++)
		{
			cout << *((int*)pArr[i] + j)<< " ";
		}
		cout << endl;
	}
}

/**********************************************************************************************
* Funtion name: freeData
* Description: Free data allocated
* Input: void **free_prt, int size
* Output: N/A
* Return: N/A
***********************************************************************************************/
void freeMem(int** pArr, int szRow, int szCol)
{
	int i = 0;
	for(i = 0; i < szCol; i++)
	{
		free(pArr[i]);
	}
	free(pArr);
}
