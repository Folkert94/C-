/*
Folkert Stijnman
10475206
Assignment 1, Date Problems


A yearsOld and monthsOld calculator
/**/

#include <time.h>
#include <iostream>
#include <cmath>

#include "assignment1.h"

using namespace std;

int ageTestSet [] = {
1967,1,18,1907,3,14,59,718,
2034,8,31,2000,1,30,34,415,
1923,3,3,1910,8,31,12,150,
2061,7,6,1957,6,28,104,1248,
2054,5,2,1958,10,31,95,1146,
2080,12,4,1973,3,2,107,1293,
2013,10,21,1944,5,2,69,833,
2023,10,25,2002,9,6,21,253,
2036,10,21,1998,1,13,38,465,
2030,7,20,2016,4,11,14,171,
2040,11,18,2035,6,3,5,65,
2050,1,27,1977,2,17,72,875,
2060,10,26,1901,10,29,158,1907,
2069,10,12,1926,3,9,143,1723,
2067,4,2,2025,12,15,41,495,
2023,2,15,1928,6,8,94,1136,
1960,1,24,1918,6,7,41,499,
1971,4,1,1941,3,14,30,360,
1958,4,16,1931,9,12,26,319,
2087,11,12,2021,10,1,66,793,
1984,3,7,1969,7,26,14,175,
2032,1,7,1929,4,11,102,1232,
2073,12,9,1932,10,31,141,1693,
1988,3,5,1930,8,26,57,690,
2053,1,6,1930,12,28,122,1464,
2027,5,20,1948,9,21,78,943,
1976,8,16,1931,10,12,44,538,
2037,3,28,2006,1,27,31,374,
2072,6,27,1910,7,9,161,1943,
2024,1,30,1962,2,10,61,743,
2055,8,30,1935,3,17,120,1445,
2022,6,4,1935,7,27,86,1042,
1988,11,30,1946,2,26,42,513,
2024,9,4,1952,2,11,72,870,
2074,10,12,2032,3,13,42,510,
2071,9,9,1994,3,7,77,930,
1988,3,11,1924,8,28,63,762,
2087,1,9,1904,12,14,182,2184,
1984,5,2,1965,6,10,18,226,
2097,5,12,1977,12,20,119,1432,
2059,6,22,2020,7,20,38,467,
2090,8,9,1901,7,11,189,2268,
2088,3,9,1996,3,16,91,1103,
1984,5,20,1973,11,5,10,126,
2057,3,19,2025,10,13,31,377,
2066,7,6,2042,4,10,24,290,
2096,11,14,1985,4,23,111,1338,
2044,2,11,2040,7,12,3,42,
1956,6,2,1934,5,21,22,264,
2050,10,9,2002,5,22,48,580,
2094,11,27,1913,7,6,181,2176,
2083,10,10,2056,6,15,27,327,
2009,4,6,2008,2,7,1,13,
1993,3,7,1967,3,3,26,312,
2062,10,2,1906,3,11,156,1878,
2046,6,13,2025,9,10,20,249,
2037,12,24,1986,7,22,51,617,
2041,8,5,1970,1,11,71,858,
2059,3,21,1929,2,5,130,1561,
2027,3,11,1996,1,26,31,373,
1925,1,11,1908,7,31,16,197,
2059,7,29,1958,8,13,100,1211,
2062,7,20,2052,8,13,9,119,
2080,9,13,1906,1,13,174,2095,
2039,3,12,2008,6,29,30,368,
1998,4,19,1998,2,17,0,2,
1972,6,7,1904,12,21,67,809,
2083,8,7,1994,7,3,89,1069,
1971,6,3,1920,4,6,51,613,
2053,3,22,1906,8,9,146,1759,
2049,11,28,2028,1,12,21,262,
2083,11,28,2002,4,7,81,979,
2062,3,21,1922,6,28,139,1676,
2089,12,13,1949,5,13,140,1686,
2079,6,29,1966,8,2,112,1354,
2089,2,13,1950,6,14,138,1663,
2057,8,23,1941,6,5,116,1394,
2020,11,3,2001,12,24,18,226,
2086,6,16,1960,4,25,126,1513,
2052,5,6,1938,4,27,114,1368,
2069,6,1,1963,2,4,106,1275,
1993,3,1,1984,2,13,9,108,
2062,2,14,1963,6,30,98,1183,
2090,2,13,2047,5,3,42,513,
2028,6,24,1965,10,18,62,752,
2091,2,5,2040,5,15,50,608,
2060,11,22,2018,6,11,42,509,
2017,10,28,1992,8,2,25,302,
1955,1,11,1902,10,22,52,626,
2070,6,8,2015,2,14,55,663,
2012,10,9,1900,1,12,112,1352,
2053,6,27,2010,1,7,43,521,
2087,5,14,1958,3,30,129,1549,
2058,8,22,2003,10,18,54,658,
2075,1,6,2047,6,13,27,330,
1941,8,9,1930,4,15,11,135,
2008,11,5,1921,9,20,87,1045,
2046,11,8,1906,2,23,140,1688,
2079,9,15,2051,2,10,28,343,
2081,5,16,2019,3,10,62,746,
1994,3,2,1914,9,25,79,953,
2088,7,27,2079,2,1,9,113,
2075,9,1,1939,7,18,136,1633,
2046,6,24,2004,10,20,41,500,
2080,11,19,1978,7,4,102,1228,
1989,10,24,1927,4,11,62,750,
2091,5,8,1926,11,30,164,1973,
2091,4,29,2061,12,11,29,352,
1989,8,28,1905,5,13,84,1011,
2075,9,16,2008,7,11,67,806,
2072,12,14,2048,5,31,24,294,
2066,11,24,1921,8,17,145,1743,
2069,1,1,1914,8,12,154,1852,
2060,12,24,2015,12,1,45,540,
2041,1,11,1953,9,11,87,1047,
2064,4,16,2052,6,27,11,141,
2045,4,2,2034,4,21,10,131,
2049,4,2,1907,9,28,141,1698,
2029,4,4,1979,9,25,49,594,
1997,9,29,1957,3,23,40,486,
2042,7,27,2026,1,18,16,198,
2014,3,25,1984,6,21,29,357,
1993,10,17,1950,8,16,43,518,
1970,11,30,1922,6,17,48,581,
2044,4,16,1923,1,28,121,1454,
2066,6,26,1982,10,26,83,1003,
2071,1,25,1913,1,23,158,1896,
2072,8,10,2047,5,22,25,302,
2095,10,8,2045,7,14,50,602,
1975,4,11,1934,10,28,40,485,
1929,3,17,1925,9,17,3,41,
2002,2,19,1950,3,19,51,622,
2096,6,23,2069,3,26,27,326,
2038,7,12,1915,11,20,122,1471,
2032,8,24,2028,4,28,4,51,
2085,5,18,2084,1,2,1,16,
2075,5,4,2034,3,24,41,493,
1952,7,7,1941,8,24,10,130,
1980,2,28,1924,9,2,55,665,
2058,8,27,2006,8,29,51,623,
2002,2,7,1927,1,3,75,901,
2088,3,6,1954,10,23,133,1600,
1976,3,7,1956,2,17,20,240,
2051,9,8,1949,4,4,102,1229,
1971,10,15,1944,2,24,27,331,
2057,12,2,1997,8,8,60,723,
2059,12,18,2009,6,2,50,606,
2086,4,4,1975,8,16,110,1327,
1983,12,19,1934,9,12,49,591,
};

    // int currentYear;
    // int currentMonth;
    // int currentDay;
    // int birthYear;
    // int birthMonth;
    // int birthDay;
    // int months;
    // time_t currentTime;
    // time(&currentTime);
    // tm* timePtr = localtime(&currentTime);
    // // cout<<" year:" << timePtr->tm_year+1900
    // // <<" month:"<< timePtr->tm_mon+1
    // // <<" day:" << timePtr->tm_mday <<endl;
    // currentYear = timePtr->tm_year+1900;
    // currentMonth = timePtr->tm_mon+1;
    // currentDay = timePtr->tm_mday;
    // cout << "Please enter your year and month of birth (dd/mm/yyyy): ";
    // scanf("%d/%d/%d", &birthDay, &birthMonth, &birthYear);
    // months = (currentYear - birthYear - 1) * 12 + currentMonth + (11 - birthMonth);

    // }
    // cout << "You are " << months << " months old.\n";

void testAge()
{
  int dim=sizeof(ageTestSet)/sizeof(int);
  for (int i=0;i<dim;i+=8)
  {
    int currentYear= ageTestSet[i+0]; // read line from array
    int currentMonth=ageTestSet[i+1];
    int currentDay=  ageTestSet[i+2];
    int birthYear=   ageTestSet[i+3];
    int birthMonth=  ageTestSet[i+4];
    int birthDay=    ageTestSet[i+5];
    int oldYears=    ageTestSet[i+6];
    int oldMonths=   ageTestSet[i+7];
    int oldYearsTest=yearsOld(currentYear,currentMonth,currentDay, // compute years
                              birthYear,birthMonth,birthDay);
    int oldMonthsTest=monthsOld(currentYear,currentMonth,currentDay, // compute months
                                birthYear,birthMonth,birthDay);
    if (oldYears!=oldYearsTest) // test and print in case of error
    {
      cout<<"ERROR yearsOld("<<currentYear<<","<<currentMonth<<","<<currentDay<<","<<endl
          <<"               "<<birthYear<<","<<birthMonth<<","<<birthDay<<") = "
          << oldYearsTest <<" is not correct, should be "<<oldYears<<endl;
    }
    if (oldMonths!=oldMonthsTest) // test and print in case of error
    {
      cout<<"ERROR monthsOld("<<currentYear<<","<<currentMonth<<","<<currentDay<<","<<endl
          <<"                "<<birthYear<<","<<birthMonth<<","<<birthDay<<") = "
          << oldMonthsTest <<" is not correct, should be "<< oldMonths << endl;
    }
  }
  cout<<"testAge() done"<<endl;
}

int yearsOld(int currentYear,int currentMonth,int currentDay,
    int birthYear,int birthMonth,int birthDay) {
    int years;
    // time_t currentTime;
    // time(&currentTime);
    // tm* timePtr = localtime(&currentTime);
    // // cout<<" year:" << timePtr->tm_year+1900
    // // <<" month:"<< timePtr->tm_mon+1
    // // <<" day:" << timePtr->tm_mday <<endl;
    // currentYear = timePtr->tm_year+1900;
    // currentMonth = timePtr->tm_mon+1;
    // currentDay = timePtr->tm_mday;
    // cout << "Please enter your year and month of birth (dd/mm/yyyy): ";
    // scanf("%d/%d/%d", &birthDay, &birthMonth, &birthYear);
    years = currentYear - birthYear - 1;
    if ((birthMonth < currentMonth) || ((birthMonth == currentMonth) && (birthDay <= currentDay)))
    years += 1;
    // cout << "You are " << years << "\n";
    // cout << "In this year you will be " << timePtr->tm_year - (i - 1900) << "\n";
    return years;
    }

int monthsOld(int currentYear,int currentMonth,int currentDay,
    int birthYear,int birthMonth,int birthDay) {
    // time_t currentTime;
    int months;
    // time(&currentTime);
    // tm* timePtr = localtime(&currentTime);
    // // cout<<" year:" << timePtr->tm_year+1900
    // // <<" month:"<< timePtr->tm_mon+1
    // // <<" day:" << timePtr->tm_mday <<endl;
    // currentYear = timePtr->tm_year+1900;
    // currentMonth = timePtr->tm_mon+1;
    // currentDay = timePtr->tm_mday;
    // cout << "Please enter your year and month of birth (dd/mm/yyyy): ";
    // scanf("%d/%d/%d", &birthDay, &birthMonth, &birthYear);
    months = (currentYear - birthYear) * 12 + (currentMonth - birthMonth - 1);
        if (currentDay > birthDay) {
            months += 1; }
    // cout << "You are " << months << "months old.\n";
    return months;
    }

int dayOfTheYear(int birthYear,int birthMonth,int birthDay) {
    // using Zeller's rule
    // int dayofbirth;
    // cout << "Please enter your day of birth (1 for Monday, etc.): ";
    // scanf("%d", &dayofbirth);
    int refYear = 2000;
    int daysdiff;
    // int refMonth = 1;
    // int refDay = 1;
    // int refDow = 6;
    cout << refYear << "\n";
    cout << birthYear << "\n";

    if (birthYear % 4 == 0) {
        const int leapYear[] = {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336};
        daysdiff = leapYear[birthMonth - 1] + birthDay - 1;
    }
    else if (birthYear % 4 != 0) {
    const int regYear[] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
        daysdiff = regYear[birthMonth - 1] + birthDay - 1;
    }
    if (refYear == birthYear) {
        daysdiff -= 1;
    }

    int yeardiff = birthYear - refYear;
    if (yeardiff == 1) {
        daysdiff += 365;
    }
    else {
        while (yeardiff > 0) {
            if ((yeardiff - 1) % 4 == 0 && ((yeardiff - 1) != 0)) {
                daysdiff += 366;
                yeardiff -= 1;
            }
            else {
            daysdiff += 365;
            yeardiff -= 1;
            }
        }
    }
    int x = daysdiff % 7;
    // map numbers to proper weekdays
    if (x == 0 || x == 1) {
        x += 6;
    }
    else {
        x -= 1;
    }
    return x;
}

int main() {
    // testAge();
    int birthDay, birthMonth, birthYear;
    int dayofbirth;
    cout << "Please enter your year and month of birth (dd/mm/yyyy): ";
    scanf("%d/%d/%d", &birthDay, &birthMonth, &birthYear);
    dayofbirth = dayOfTheYear(birthYear, birthMonth, birthDay);
    cout << "You were born on the " << dayofbirth << " day of the week\n" ;
}
