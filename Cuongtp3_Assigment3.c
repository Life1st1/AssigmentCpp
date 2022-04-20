#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FALSE 0
#define TRUE 1

#define MAX_DAY_OF_MONTH 31
#define MAX_MONTH_OF_YEAR 12
#define DAY_OF_MONTH_MASK 0b101011010101

#define IS_LEAP_YEAR(x)					(((x % 4 == 0 && x % 100 != 0)|| (x % 400 == 0)) ? 1:0)  	/*Check leap year*/
#define MAX_DATE_OF_MONTH(month,year)	(((DAY_OF_MONTH_MASK >> (month - 1)) & 0x01) ? 31 : (month != 2 ? 30: (IS_LEAP_YEAR(year) ? 29 : 28))) 	/*Max date of month */

typedef struct date_time
{
	uint8_t date;
	uint8_t month;
	int year;
}date_time_t;

void inputTime(date_time_t *time);
int check_input_date(date_time_t input_time);
void showTheNextDay(date_time_t *time);
void showPreviousDay(date_time_t *time);

int main(void)
{
	date_time_t CurrentDateTime;
	date_time_t tempDateTime;
	uint8_t option;
	while(1)
	{
		uint8_t exit = TRUE;
		printf("*******CALENDAR*********\n");
		printf("Input dd/mm/yyyy\n");
		
		inputTime(&CurrentDateTime);
		while(!check_input_date(CurrentDateTime))
		{
			printf("Input again\n");
			inputTime(&CurrentDateTime);
		}
		
		printf("Current date:%hhd/%hhd/%d\n", CurrentDateTime.date, CurrentDateTime.month, CurrentDateTime.year);
		printf("============MENU===============\n");
		printf("1. Find the number of month.\n");
		printf("2. Show the next day(dd/mm/yyyy).\n");
		printf("3. Show the previous day (dd/mm/yyyy).\n");
		printf("4. Restart program\n");

		while(exit)
		{
			printf("Select option please:");
			scanf("%hhd", &option);
			switch(option)
			{
				case 1:
					printf("%d days in this month\n", MAX_DATE_OF_MONTH(CurrentDateTime.month, CurrentDateTime.year));
					break;
				case 2:
					tempDateTime = CurrentDateTime;
					showTheNextDay(&CurrentDateTime);
					printf("Next day is: %hhd/%hhd/%d\n", tempDateTime.date, tempDateTime.month, tempDateTime.year);
					break;
				case 3:
					tempDateTime = CurrentDateTime;
					showPreviousDay(&tempDateTime);
					printf("Previous day is: %hhd/%hhd/%d\n", tempDateTime.date, tempDateTime.month, tempDateTime.year);
					break;
				case 4:
					exit = FALSE;
					break;
				default:
					printf("Enter again\n");	
					break;
			}	
		}
	}	
	return 0;
}

/************************************************
* Description: Input date
* Input:
* Output: Date struct
*************************************************/
void inputTime(date_time_t *time)
{
	do	/*Input date*/
	{
		printf("date:");
		scanf("%hhd", &(time->date));
	}while(MAX_DAY_OF_MONTH < time->date || 0 > time->date);
	
	do	/*Input month*/	
	{
		printf("month:");
		scanf("%hhd", &(time->month));
	}while(MAX_MONTH_OF_YEAR < time->month || 0 > time->month);
	
	do	/*Input year*/			
	{
		printf("year:");
		scanf("%d", &(time->year));
	}while(0 > time->year);
}


/************************************************
* Description: Check whether input date is valid
* Input: Date struct
* Output: Valid or not
*************************************************/
int check_input_date(date_time_t input_time)
{
	int is_valid = TRUE;
	if(MAX_DATE_OF_MONTH(input_time.month, input_time.year) < input_time.date)
	{
		return is_valid == FALSE;
	}
	return is_valid;
}

/************************************************
* Description: Show the next day
* Input: 
* Output: Next day data struct
*************************************************/
void showTheNextDay(date_time_t *time)
{
	if(time->date == MAX_DATE_OF_MONTH(time->month, time->year))
	{
		time->date = 1;
		if(time->month == MAX_MONTH_OF_YEAR)
		{
			time->month = 1;
			time->year ++;
		}
		else
		{
			time->month ++;
		}
	}
	else
	{
		time->date ++;
	}

}

/************************************************
* Description: Show the next previous day
* Input: 
* Output: Previous day data struct
*************************************************/
void showPreviousDay(date_time_t *time)
{
	if(time->month == 1)
	{
		if(time->date == 1)
		{
			time->month = MAX_MONTH_OF_YEAR;
			time->date = MAX_DATE_OF_MONTH(MAX_MONTH_OF_YEAR, time->year - 1);
			time->year --;
		}
		else
		{
			time->date --;
		}
	}
	else
	{
		if(time->date == 1)
		{
			time->month --;
			time->date = MAX_DATE_OF_MONTH(time->month, time->year);
		}
		else
			time->date --;
	}
}





