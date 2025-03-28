/*This program is binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
#Author: Khris Vaz (166882)
#Created: 5 Feb., 2025
#Modified: 5 Feb., 2025
*/
#include<stdio.h>
#include "header.h"
 
static char daytab[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
 
 
void q9(void)
{
    int day,mo,ye,dat,c;
    while(c){
        printf("1. DATE to DAY       2. DAY to DATE\n");
        printf("Enter your choice:");
        scanf("%d",&c);
        switch(c){
                case 1:
                        printf("Enter year:");
                        scanf("%d",&ye);
                        printf("Enter month:");
                        scanf("%d",&mo);
                        printf("Enter day:");
                        scanf("%d",&dat);
                        day=day_of_year2(ye,mo,dat);
                        if(day!=-1)
                                printf("day is of the year is %d\n",day);
                        else
                                printf("Invalid input\n");
                        break;
                case 2:
                        printf("Enter year:");
                        scanf("%d",&ye);
                        printf("Enter no of days:");
                        int noofdays;
                        scanf("%d",&noofdays);
                        month_day2(ye,noofdays,&mo,&day);
                        if(mo!=-1 && day!=-1){
                                printf("Month:%d  Day:%d\n",mo,day);
                        }else{
                                printf("Invalid Input\n");
                        }
                        break;
                default:
                        printf("Invalid choice\n");
                        return;
        }
    }
}
 
/* day_of_year: set day of year from month & day */
 
int day_of_year2(int year,int month,int day)
{
    int i,leap;
 
    leap = (year % 4 == 0 && year%100 != 0 || year%400) == 0;
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > daytab[leap][month]) {
            return -1;
     }
    for(i=1;i<month;i++)
        day += daytab[leap][i];
 
    return day;
}
 
/* month_day: set month,day from day of year */
 
void month_day2(int year,int yearday,int *month,int *day)
{
    int i,leap;
 
    leap = year % 4 == 0 && year%100 != 0 || year%400 == 0;
    if (year < 1 || yearday < 1 || yearday > (leap ? 366 : 365)) {
                *month=-1;
                *day=-1;
                return;
     }
    for(i=1;yearday > daytab[leap][i];i++)
        yearday -= daytab[leap][i];
 
    *month=i;
    *day=yearday;
    return;
}
