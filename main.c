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
int day_of_the_year(int day, int month, int year);
void weekdays(int day,int month, int year);




int main()
{
    int a = day_of_the_year(7,1,1582);
    printf("%i",a);
    weekdays(7,1,1582);
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
   if(year%400 == 0) {
    return 1;
   }
   else if(year%100 == 0) {
    return 0;
   }
   else if(year%4 == 0) {
    return 1;
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
* Funktion ermittelt die Tage die der Monat im jeweiligen Jahr hat.
**/
int get_days_for_month(int month, int year) {
switch(month) {
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12: return 31; break;                                      //Alle Monate die 31 Tage haben aufgeführt
case 2: return 28; break;                                       //Alle Monate die 28 Tage haben aufgeführt
case 4:
case 6:
case 9:
case 11: return 30; break;                                      //Alle Monate die 30 Tage haben aufgeführt
default: return 29; break;
    }
}
/**
* Funktion prüft ob der Tag existiert
**/
int exists_date(int day,int month,int year) {
    if (year >= 1582 || year <= 2400) {
        if(1 <= month && month <= 12) {
            if(1 <= day && day <= get_days_for_month(month,year)) {
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
/**
* Funktion ermittelt die Tage die bereits im Jahr vergangen sind
**/
int day_of_the_year(int day, int month, int year) {
    int days = 0;
    for(int i = 1; i < month; i++) {                    //Zusammenrechnen der Tage der Monate
        days += get_days_for_month(i,year); }
    days += day;                                        //Addition der im laufenden Monat vergangenen Tage
    return days;
}

/**
Funktion zur Berechnung des Wochentages anhand des Datums
**/
void weekdays(int day,int month, int year) {
int days = 0;
int weekday = 0;
//Wahl ob Schaltjahr oder nicht
for(int i = 1582;i<year;i++) {
    if (is_leapyear(year)==1) {
        days += 366;
    }
    else {
        days += 365;
    }
}
//Addition der vergangenen Tage
    days += day_of_the_year(day,month,year);
//Bestimmen des Wochentages aufgrund der Differenz zum 1.1.1582
    weekday = days%7;
//Ausgabe des Wochentages
    switch (weekday) {
    case 0: printf("Der Tag ist ein Donnerstag");    break;
    case 1: printf("Der Tag ist ein Freitag");    break;
    case 2: printf("Der Tag ist ein Samstag");    break;
    case 3: printf("Der Tag ist ein Sonntag");     break;
    case 4: printf("Der Tag ist ein Montag");   break;
    case 5: printf("Der Tag ist ein Dienstag");   break;
    case 6: printf("Der Tag ist ein Mittwoch"); break;
    }

}









