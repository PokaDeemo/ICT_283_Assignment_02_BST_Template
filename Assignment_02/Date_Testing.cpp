#include <iostream>
#include "Date.h"

int main()
{
    Date date1;
    date1.SetDay(16);
    date1.SetMonth(11);
    date1.SetYear(2022);
    date1.GetDay();
    date1.GetMonth();
    date1.GetYear();
    cout <<"Date-Test: (Day): "<< date1.GetDay() << endl;
    cout <<"Date-Test: (Month): "<< date1.GetMonth() << endl;
    cout <<"Date-Test: (Year): "<< date1.GetYear() << endl;
    cout <<"Date-Test: "<< date1.GetDay() << "/" << date1.GetMonth() << "/" << date1.GetYear() << endl;

    cout << endl;

    cout << "--- Month Convert Test --- " << endl;
    cout << endl;
    Date date2;
    date2.SetMonth(12);
    date2.GetMonth();

    cout <<"Month-Convert: "<< date2.GetMonth() << " ---> " << date2.ConvertMonth(12) << endl;

    cout << endl;

    Date Compare1;
    Compare1.SetDay(16);
    Compare1.SetMonth(11);
    Compare1.SetYear(2022);
    Compare1.GetDay();
    Compare1.GetMonth();
    Compare1.GetYear();

    Date Compare2;
    Compare2.SetDay(26);
    Compare2.SetMonth(12);
    Compare2.SetYear(2022);
    Compare2.GetDay();
    Compare2.GetMonth();
    Compare2.GetYear();

    Date Compare3;
    Compare3.SetDay(16);
    Compare3.SetMonth(11);
    Compare3.SetYear(2022);
    Compare3.GetDay();
    Compare3.GetMonth();
    Compare3.GetYear();

    Date Compare4;
    Compare4.SetDay(04);
    Compare4.SetMonth(3);
    Compare4.SetYear(2021);
    Compare4.GetDay();
    Compare4.GetMonth();
    Compare4.GetYear();

    // Equal Operator Test
    cout << "Equal [==] Operator Test" << endl;
    cout << endl;
    if(Compare1 == Compare3)
    {
        cout << Compare1.GetDay() << "/" << Compare1.GetMonth() << "/" << Compare1.GetYear() << " Is Equal To " << Compare3.GetDay() << "/" << Compare3.GetMonth() << "/" << Compare3.GetYear() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare1.GetDay() << "/" << Compare1.GetMonth() << "/" << Compare1.GetYear() << " Is Equal To " << Compare3.GetDay() << "/" << Compare3.GetMonth() << "/" << Compare3.GetYear() << endl;
        cout << "Is False" << endl;
    }

    cout << endl;

    if(Compare2 == Compare4)
    {
        cout << Compare2.GetDay() << "/" << Compare2.GetMonth() << "/" << Compare2.GetYear() << " Is Equal To " << Compare4.GetDay() << "/" << Compare3.GetMonth() << "/" << Compare4.GetYear() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare2.GetDay() << "/" << Compare2.GetMonth() << "/" << Compare2.GetYear() << " Is Equal To " << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << endl;
        cout << "Is False" << endl;
    }

    cout << endl;

    // < Operator Test
    cout << "Smaller [<] Operator Test" << endl;
    cout << endl;
    if(Compare2 < Compare4)
    {
        cout << Compare2.GetDay() << "/" << Compare2.GetMonth() << "/" << Compare2.GetYear() << " Is Equal To " << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << endl;
        cout << "Is Smaller " << endl;
    }
    else
    {
        cout << Compare2.GetDay() << "/" << Compare2.GetMonth() << "/" << Compare2.GetYear() << " Is Equal To " << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << endl;
        cout << "Is Not Smaller " << endl;
    }

    cout << endl;

    if(Compare4 < Compare3)
    {
        cout << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << " Is Equal To " << Compare3.GetDay() << "/" << Compare3.GetMonth() << "/" << Compare3.GetYear() << endl;
        cout << "Is Smaller " << endl;
    }
    else
    {
        cout << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << " Is Equal To " << Compare3.GetDay() << "/" << Compare3.GetMonth() << "/" << Compare3.GetYear() << endl;
        cout << "Is Not Smaller " << endl;
    }

    cout << endl;

    // < Operator Test
    cout << "Bigger [>] Operator Test" << endl;
    cout << endl;
    if(Compare2 > Compare3)
    {
        cout << Compare2.GetDay() << "/" << Compare2.GetMonth() << "/" << Compare2.GetYear() << " Is Equal To " << Compare3.GetDay() << "/" << Compare3.GetMonth() << "/" << Compare3.GetYear() << endl;
        cout << "Is Bigger " << endl;
    }
    else
    {
        cout << Compare2.GetDay() << "/" << Compare2.GetMonth() << "/" << Compare2.GetYear() << " Is Equal To " << Compare3.GetDay() << "/" << Compare3.GetMonth() << "/" << Compare3.GetYear() << endl;
        cout << "Is Not Bigger" << endl;
    }

    cout << endl;

    if(Compare4 > Compare1)
    {
        cout << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << " Is Equal To " << Compare1.GetDay() << "/" << Compare1.GetMonth() << "/" << Compare1.GetYear() << endl;
        cout << "Is Bigger " << endl;
    }
    else
    {
        cout << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << " Is Equal To " << Compare1.GetDay() << "/" << Compare1.GetMonth() << "/" << Compare1.GetYear() << endl;
        cout << "Is Not Bigger " << endl;
    }

    cout << endl;

    // <= Operator Test
    cout << "Smaller or Equal [<=] Operator Test" << endl;
    cout << endl;

    if(Compare1 <= Compare3)
    {
        cout << Compare1.GetDay() << "/" << Compare1.GetMonth() << "/" << Compare1.GetYear() << " Is Equal To " << Compare3.GetDay() << "/" << Compare3.GetMonth() << "/" << Compare3.GetYear() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare1.GetDay() << "/" << Compare1.GetMonth() << "/" << Compare1.GetYear() << " Is Equal To " << Compare3.GetDay() << "/" << Compare3.GetMonth() << "/" << Compare3.GetYear() << endl;
        cout << "Is False" << endl;
    }

    cout << endl;

    if(Compare2 <= Compare4)
    {
        cout << Compare2.GetDay() << "/" << Compare2.GetMonth() << "/" << Compare2.GetYear() << " Is Equal To " << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare2.GetDay() << "/" << Compare2.GetMonth() << "/" << Compare2.GetYear() << " Is Equal To " << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << endl;
        cout << "Is False" << endl;
    }

    cout << endl;

    // >= Operator Test
    cout << "Bigger or Equal [>=] Operator Test" << endl;
    cout << endl;
    if(Compare1 >= Compare4)
    {
        cout << Compare1.GetDay() << "/" << Compare1.GetMonth() << "/" << Compare1.GetYear() << " Is Equal To " << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare1.GetDay() << "/" << Compare1.GetMonth() << "/" << Compare1.GetYear() << " Is Equal To " << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << endl;
        cout << "Is False" << endl;
    }

    cout << endl;

    if(Compare4 >= Compare2)
    {
        cout << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << " Is Equal To " << Compare2.GetDay() << "/" << Compare2.GetMonth() << "/" << Compare2.GetYear() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare4.GetDay() << "/" << Compare4.GetMonth() << "/" << Compare4.GetYear() << " Is Equal To " << Compare2.GetDay() << "/" << Compare2.GetMonth() << "/" << Compare2.GetYear() << endl;
        cout << "Is False" << endl;
    }


    return 0;
}
