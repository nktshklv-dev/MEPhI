#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int validateDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
        return 0;
    }
    
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return (day <= 30);
    }
    
    if (month == 2) {
        if (isLeapYear(year)) {
            return (day <= 29);
        } else {
            return (day <= 28);
        }
    }
    
    return 1;
}

int daysInMonth(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    
    return days[month];
}

int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    if (!validateDate(day1, month1, year1) || !validateDate(day2, month2, year2)) {
        printf("uncorrect date\n");
        return -1;
    }

    int totalDays = 0;

    while (year1 < year2 || (year1 == year2 && month1 < month2)) {
        totalDays += daysInMonth(month1, year1) - day1 + 1;
        day1 = 1;
        month1++;

        if (month1 > 12) {
            month1 = 1;
            year1++;
        }
    }

    totalDays += day2 - day1;

    return totalDays;
}

int main() {
    int day1, month1, year1;
    int day2, month2, year2;

    scanf("%d%d%d", &day1, &month1, &year1);
    scanf("%d%d%d", &day2, &month2, &year2);

    int days = daysBetweenDates(day1, month1, year1, day2, month2, year2);

    if (days >= 0) {
        printf("%d\n", days);
    }

    return 0;
}
