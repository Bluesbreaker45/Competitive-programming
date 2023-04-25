#include<iostream>
#include<cstdio>
using namespace std;

bool isRun(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year;
    int month;
    cin >> year >> month;
    int currDay = 1;
    
    for (int i = 1900; i < year; i++) {
        if (isRun(i)) {
            currDay = currDay + 366;
        } else {
            currDay = currDay + 365;
        }
    }
    switch (month) {
        case 12:
        currDay += 30;
        case 11:
        currDay += 31;
        case 10:
        currDay += 30;
        case 9:
        currDay += 31;
        case 8:
        currDay += 31;
        case 7:
        currDay += 30;
        case 6:
        currDay += 31;
        case 5:
        currDay += 30;
        case 4:
        currDay += 31;
        case 3:
        if (isRun(year)) {
            currDay += 29;
        } else {
            currDay += 28;
        }
        case 2:
        currDay += 31;
        case 1:
        break;
    }

    currDay = currDay % 7;

    int dd;
    switch (month) {
        case 12:
        dd = 31;
        break;
        case 11:
        dd = 30;
        break;
        case 10:
        dd = 31;
        break;
        case 9:
        dd = 30;
        break;
        case 8:
        dd = 31;
        break;
        case 7:
        dd = 31;
        break;
        case 6:
        dd = 30;
        break;
        case 5:
        dd = 31;
        break;
        case 4:
        dd = 30;
        break;
        case 3:
        dd = 31;
        break;
        case 2:
        if (isRun(year)) {
            dd = 29;
        } else {
            dd = 28;
        }
        break;
        case 1:
        dd = 31;
        break;
    }
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for (int i = 0; i < currDay; i++) {
        printf("    ");
    }


    for (int i = 1; i <= dd; i++) {
        printf("%3.d ", i);
        currDay = (currDay + 1) % 7;
        if (currDay == 0) {
            printf("\n");
        }
    }

    return 0;
}