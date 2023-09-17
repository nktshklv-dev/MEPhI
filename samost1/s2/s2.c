#include <stdio.h>

int validate_date(int dd, int mm, int yy)
{
    short int date_is_valid = 1;
    //check year
    if(yy>=0 && yy<=9999)
    {
        //check month
        if(mm>=1 && mm<=12)
        {
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)) date_is_valid = 1;
                
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)) date_is_valid=1;
                
            else if((dd>=1 && dd<=28) && (mm==2)) date_is_valid=1;
                
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))) date_is_valid=1;
                
            else date_is_valid = 0;
        }
        else date_is_valid = 0;
    }
    else date_is_valid = 0;
    if(yy==1582 && mm==10 && dd>=5 && dd<=14) date_is_valid=0;

 
    return date_is_valid;
}
int date_is_grigorian(int dd, int mm, int yy)
{
    if(yy>1582) return 1;
    else if(yy==1582)
    {
        if(mm>10) return 1;
        else if(mm==10)
        {
            if(dd>=15) return 1;
            else return 0;
        }
        else return 0;
    }
    else return 0;
}

int main(void)
{
    int day, month, year;
    scanf("%d%d%d", &day, &month, &year);

    if( !  validate_date(day, month, year)) 
    {
        printf("uncorrect date\n");
        return 0;
    }

    int day_week;

    if (date_is_grigorian(day, month, year))
    {
        if(month==1 || month==2)
        {
            year = year-1;
            month = month + 10;
        }
        else month = month - 2;
        day_week = (day + (31*month)/12 + year + year/4 - year/100 + year/400)%7;

        
    }
    else
    {
        int a = (14 - month)/12;
        year = year + 4800 -a;
        month = month + 12*a -3;
        day_week = (day + (153*month+2)/5 + 365*year + year/4 - 32083 + 1)%7;    
    }
    switch(day_week)
    {
    case 0:
        printf("sunday\n");
        break;
    case 1:
        printf("monday\n");
        break;
    case 2:
        printf("tuesday\n");
        break;
    case 3:
        printf("wednesday\n");
        break;
    case 4:
        printf("thursday\n");
        break;
    case 5:
        printf("friday\n");
        break;
    case 6:
        printf("saturday\n");
        break;
    }

    return 0;
}