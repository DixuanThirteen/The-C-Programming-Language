#include <stdio.h>

static int daytab1[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};   //��5-8�Ķ�ά�����д������ָ������
static int daytab2[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
static int *daytab[2] = {daytab1 , daytab2};

int day_of_year(int year , int month , int day);
void month_day(int year , int yearday , int *pmonth , int *pday);

int main(){
    int year , month , day;
    printf("������/��/�գ�");
    scanf("%d/%d/%d",&year , &month , &day);
    int day_year = day_of_year(year , month , day);
    printf("������һ���еĵ�%d��\n",day_year);

    int yearday;
    printf("����xx��,xx�գ�");
    scanf("%d,%d",&year , &yearday);
    int pmonth , pday;
    month_day(year , yearday , &pmonth , &pday);
    printf("������%d��%d��%d��",year , pmonth , pday);

    return 0;
}

int day_of_year(int year , int month , int day){
    int leap , i;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if( day <= daytab[leap][month] ){       
        for(i = 1 ; i < month ; i++){
            day += daytab[leap][i];
        }
    }else{
        printf("error");
        return 0;
    }

    return day;

}

void month_day(int year , int yearday , int *pmonth , int *pday){
    int leap , i;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if( (yearday <= 365 && leap == 0) || (yearday <= 366 && leap == 1) ){     //ƽ���������ܴ���355�������������ܴ���366
        for(i = 1 ; yearday > daytab[leap][i] ; i++){
            yearday -= daytab[leap][i];
        }
        *pmonth = i;
        *pday = yearday;
    }else{
        printf("error\n");
    }
}