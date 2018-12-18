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
int isLeapyear(int year);
int day_of_the_year(int day, int month, int year)
{

    return 0;
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
int isLeapyear(int year)
{
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
