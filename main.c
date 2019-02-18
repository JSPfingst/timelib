/**
 * Jonas Pfingst
 *  18.12.18
 *
 **/

#include <stdio.h>
#include <stdlib.h>

struct date {
int day;
int month;
int year;

};


int main()
{
    struct date searchdate;
    int a = day_of_the_year(7,1,1582);
    printf("%i",a);
    weekdays(7,1,1582);
    //printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}






