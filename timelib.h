/**
 * Jonas Pfingst
 *  18.12.18
 *  Time-Library
 **/

#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

struct date
{
    int day;
    int month;
    int year;

};

int is_leapyear(struct date *date);
int get_days_for_month(struct date *date);
int exists_date(struct date *date);
int day_of_the_year(struct date *date);
void day_of_the_week(struct date *date);

#endif // TIMELIB_H_INCLUDED



