/**
 * Jonas Pfingst
 *  18.12.18
 *  Time-Library
 *  Library which includes a few functions for working with dates and years
 **/

#include <stdio.h>
#include <stdlib.h>

/**
The function checks based on the gregorian calendar if the given year is  leap year.
**/
int is_leapyear(struct date *date)
{
    if(date.year>=1582)
    {
        if(date.year%400 == 0)
        {
            return 1;
        }
        else if(date.year%100 == 0)
        {
            return 0;
        }
        else if(date.year%4 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}
/**
* The function calculates the days of the given month in the given year and gives them back
**/
int get_days_for_month(struct date *date)
{
    switch(date.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;                                      //All months which have 31 days
    case 2:
        return 28;
        break;                                       //All months which have 28 days
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;                                      //All months which have 20 days
    default:
        return 29;
        break;                                      //All months which have 29 days
    }
}
/**
* Function which checks if the given date is an existing date
**/
int exists_date(struct date *date)
{
    if (date.year >= 1582 || date.year <= 2400)
    {
        if(1 <= date.month && date.month <= 12)
        {
            if(1 <= date.day && date.day <= get_days_for_month(date.month,date.year))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}
/**
* Function which calcs the last days of the given year and returns them
**/
int day_of_the_year(struct date *date)
{
    int days = 0;
    for(int i = 1; i < date.month; i++)                      //Adding the days of each month
    {
        days += get_days_for_month(i,date.year);
    }
    days += date.day;                                        //Adding the days of the actual month
    return days;
}

/**
Function which determines the day of the week
**/
void day_of_the_week(struct date *date)
{
    int days = 0;
    int weekday = 0;
//Determination if the given year is a leap year
    for(int i = 1582; i<date.year; i++)
    {
        if (is_leapyear(date.year)==1)
        {
            days += 366;
        }
        else
        {
            days += 365;
        }
    }
//Addition of the last days
    days += day_of_the_year(date.day,date.month,date.year);
//Determines the day of the week based on its difference to the 1.1.1582
    weekday = days%7;
//Return of the weekday
    switch (weekday)
    {
    case 0:
        printf("The day is a thurday");
        break;
    case 1:
        printf("The day is a friday");
        break;
    case 2:
        printf("The day is a saturday");
        break;
    case 3:
        printf("The day is a sunday");
        break;
    case 4:
        printf("The day is a monday");
        break;
    case 5:
        printf("The day is a tuesday");
        break;
    case 6:
        printf("The day is a wednesday");
        break;
    }

    struct date input_date()
    {
        struct date actualdate;
        printf("Please give in a day");
        scanf("%i",actualdate.day);
        printf("Please give in a month");
        scanf("%i",actualdate.month);
        printf("Please give in a year");
        scanf("%i",actualdate.year);
        return actualdate;
    }    ;
