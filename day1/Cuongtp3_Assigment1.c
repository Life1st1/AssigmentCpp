#include <stdio.h>
#include <stdlib.h>

#define PALINDROME_NUMBER 0
#define NO_PALINDROME_NUMBER -1

typedef struct number_arry_atribute
{
    char *array_num;
    int len;
}number_arry_atribute_t;

int convertInt2Arr(long long int number, number_arry_atribute_t *ptr);
int isPalindromeNum(number_arry_atribute_t *ptr);

int main (void)
{
    long long int number;
    number_arry_atribute_t arry_number;
    printf("========CHECK PALINDROME NUMBER PROGRAM========\n\n");
    while(1)
    {
        printf("Input the number to check: ");
        scanf("%lld", &number);
    
        arry_number.array_num == NULL;
    
        arry_number.array_num = (char*)malloc(sizeof(char));
    
        convertInt2Arr(number, &arry_number);
        if(isPalindromeNum(&arry_number) == PALINDROME_NUMBER)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}


int convertInt2Arr(long long int number, number_arry_atribute_t *ptr)
{
    int i;
    long long int temp = number;
    char value;

    ptr->len = 0;
    
    for(i = 0; temp != 0; i++)
    {
        value = temp % 10;
        ptr->array_num[i] = value;
        temp = temp / 10;
        ptr->len ++;
        ptr->array_num = (char*)realloc(ptr->array_num, (ptr->len + 1)*sizeof(char));
    }
}

int isPalindromeNum(number_arry_atribute_t *ptr)
{
    int count = 0;
    for(count = 0; count < ptr->len /2; )
    {
        ptr->array_num[ptr->len];
        if(ptr->array_num[count] == ptr->array_num[ptr->len - count - 1])
        {
            count ++;
        }
        else
            break;
        
    }
    
    if(count == ptr->len /2)
        return PALINDROME_NUMBER;
    else
        return NO_PALINDROME_NUMBER;
}
