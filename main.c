/**
 * Jonas Pfingst
 *  18.12.18
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int is_leapyear(int year);
int input_date();
int get_days_for_month(int month,int year);
int exits_date(int day,int month,int year);
int day_of_the_year(int day, int month, int year)
{

    return 0;
}

int main()
{
    int a =get_days_for_month(3,2004);
    printf("%i",a);
    //printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
/**
Die Funktion überprüft auf Grundlage des gregorianischen Kalenders,
ob es sich bei dem eigegeben Jahr um ein schaltjahr handelt.

**/
int is_leapyear(int year){
 if(year>=1582)
 {
   if(year%4 ==0) {                                                //Jahr ist durch 4 teilbar

        if(year%100 ==0) {                                          //Jahr ist durch 100 teilbar

            if(year%400 ==0) {                                      //Jahr ist durch 400 teilbar
                return 1;
                             }
            else {
                return 0;
                 }
                         }
        else {
           return 1;
             }
                   }
    else {
        return 0;
         }
 }
 else {
    return -1;
      }
}
/**
* Funktion ermittelt die Tage die der monat im jeweiligen Jahr hat
**/
int get_days_for_month(int month, int year) {
if (is_leapyear(year)== 1 && month == 2) {
    month = 13;
    }
switch(month) {
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12: return 31; break;
case 2: return 28; break;
case 4:
case 6:
case 9:
case 11: return 30; break;
default: return 29; break;
    }
}
int exists_date(int day,int month,int year) {
if (year >=1582 || year <= 2400) {
    if(1<=month<=12) {
        if(1<= day <= get_days_for_month(month,year)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}
else {
    return 0;
}

}



