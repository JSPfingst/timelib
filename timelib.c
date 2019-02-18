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


/**
Die Funktion überprüft auf Grundlage des gregorianischen Kalenders,
ob es sich bei dem eigegeben Jahr um ein schaltjahr handelt.

**/
int is_leapyear(struct date *date){
 if(date.year>=1582)
 {
   if(date.year%400 == 0) {
    return 1;
   }
   else if(date.year%100 == 0) {
    return 0;
   }
   else if(date.year%4 == 0) {
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
int get_days_for_month(struct date *date) {
switch(date.month) {
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
int exists_date(struct date *date) {
    if (date.year >= 1582 || date.year <= 2400) {
        if(1 <= date.month && date.month <= 12) {
            if(1 <= date.day && date.day <= get_days_for_month(date.month,date.year)) {
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
int day_of_the_year(struct date *date) {
    int days = 0;
    for(int i = 1; i < date.month; i++) {                    //Zusammenrechnen der Tage der Monate
        days += get_days_for_month(i,date.year); }
    days += date.day;                                        //Addition der im laufenden Monat vergangenen Tage
    return days;
}

/**
Funktion zur Berechnung des Wochentages anhand des Datums
**/
void weekdays(struct date *date) {
int days = 0;
int weekday = 0;
//Wahl ob Schaltjahr oder nicht
for(int i = 1582;i<date.year;i++) {
    if (is_leapyear(date.year)==1) {
        days += 366;
    }
    else {
        days += 365;
    }
}
//Addition der vergangenen Tage
    days += day_of_the_year(date.day,date.month,date.year);
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
