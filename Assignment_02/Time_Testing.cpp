#include <iostream>
#include "Time.h"

int main()
{
    Time time1;
    time1.SetHour(11);
    time1.GetHour();
    time1.SetMinute(30);
    time1.GetMinute();
    cout <<"Test-Test: (Hour) " << time1.GetHour() << endl;
    cout <<"Test-Test: (Minute) " << time1.GetMinute() << endl;
    cout <<"Test-Time: " << time1.GetHour() << ":" << time1.GetMinute() << endl;

    cout << endl;

    Time Compare1;
    Compare1.SetHour(12);
    Compare1.GetHour();
    Compare1.SetMinute(35);
    Compare1.GetMinute();

    Time Compare2;
    Compare2.SetHour(8);
    Compare2.SetMinute(15);
    Compare2.GetHour();
    Compare2.GetMinute();

    Time Compare3;
    Compare3.SetHour(7);
    Compare3.SetMinute(45);
    Compare3.GetHour();
    Compare3.GetMinute();

    Time Compare4;
    Compare4.SetHour(12);
    Compare4.SetMinute(35);
    Compare4.GetHour();
    Compare4.GetMinute();

    // Equal Operator Test
    cout << "Equal [==] Operator Test" << endl;
    cout << endl;
    if(Compare1 == Compare2)
    {
        cout << Compare1.GetHour() << ":" << Compare1.GetMinute() << " Is Equal To " << Compare2.GetHour() << ":" <<Compare2.GetMinute() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare1.GetHour() << ":" << Compare1.GetMinute() << " Is Equal To " << Compare2.GetHour() << ":" <<Compare2.GetMinute() << endl;
        cout << "Is False" << endl;
    }

    cout << endl;

    if(Compare1 == Compare4)
    {
        cout << Compare1.GetHour() << ":" << Compare1.GetMinute() << " Is Equal To " << Compare4.GetHour() << ":" <<Compare4.GetMinute() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare2.GetHour() << ":" << Compare2.GetMinute() << " Is Equal To " << Compare3.GetHour() << ":" <<Compare3.GetMinute() << endl;
        cout << "Is False" << endl;
    }

    cout << endl;

    // < Operator Test
    cout << "Smaller [<] Operator Test" << endl;
    cout << endl;
    if(Compare1 < Compare2)
    {
        cout << Compare1.GetHour() << ":" << Compare1.GetMinute() << " Is Smaller Then " << Compare2.GetHour() << ":" <<Compare2.GetMinute() << endl;
        cout << "Is Smaller " << endl;
    }
    else
    {
        cout << Compare1.GetHour() << ":" << Compare1.GetMinute() << " Is Smaller Then " << Compare2.GetHour() << ":" <<Compare2.GetMinute() << endl;
        cout << "Is Not Smaller " << endl;
    }

    cout << endl;

    if(Compare3 < Compare4)
    {
        cout << Compare3.GetHour() << ":" << Compare3.GetMinute() << " Is Smaller Then " << Compare4.GetHour() << ":" <<Compare4.GetMinute() << endl;
        cout << "Is Smaller " << endl;
    }
    else
    {
        cout << Compare3.GetHour() << ":" << Compare3.GetMinute() << " Is Smaller Then " << Compare4.GetHour() << ":" <<Compare4.GetMinute() << endl;
        cout << "Is Not Smaller " << endl;
    }

    cout << endl;

    // < Operator Test
    cout << endl;
    cout << "Bigger [>] Operator Test" << endl;
    if(Compare1 > Compare2)
    {
        cout << Compare1.GetHour() << ":" << Compare1.GetMinute() << " Is Bigger Then " << Compare2.GetHour() << ":" <<Compare2.GetMinute() << endl;
        cout << "Is Bigger " << endl;
    }
    else
    {
        cout << Compare1.GetHour() << ":" << Compare1.GetMinute() << " Is Bigger Then " << Compare2.GetHour() << ":" <<Compare2.GetMinute() << endl;
        cout << "Is Not Bigger Then" << endl;
    }

    cout << endl;

    if(Compare3 > Compare4)
    {
        cout << Compare3.GetHour() << ":" << Compare3.GetMinute() << " Is Bigger Then " << Compare4.GetHour() << ":" <<Compare4.GetMinute() << endl;
        cout << "Is Bigger " << endl;
    }
    else
    {
        cout << Compare3.GetHour() << ":" << Compare3.GetMinute() << " Is Bigger Then " << Compare4.GetHour() << ":" <<Compare4.GetMinute() << endl;
        cout << "Is Not Bigger " << endl;
    }

    cout << endl;

    // <= Operator Test
    cout << "Smaller or Equal [<=] Operator Test" << endl;
    cout << endl;

    if(Compare2 <= Compare3)
    {
        cout << Compare2.GetHour() << ":" << Compare2.GetMinute() << " Is Smaller or Equal to " << Compare3.GetHour() << ":" <<Compare3.GetMinute() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare2.GetHour() << ":" << Compare2.GetMinute() << " Is Smaller or Equal to " << Compare3.GetHour() << ":" <<Compare3.GetMinute() << endl;
        cout << "Is False" << endl;
    }

    cout << endl;

    if(Compare3 <= Compare4)
    {
        cout << Compare3.GetHour() << ":" << Compare3.GetMinute() << " Is Smaller or Equal to " << Compare4.GetHour() << ":" <<Compare4.GetMinute() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare3.GetHour() << ":" << Compare3.GetMinute() << " Is Smaller or Equal to " << Compare4.GetHour() << ":" <<Compare4.GetMinute() << endl;
        cout << "Is False" << endl;
    }

    cout << endl;

    // >= Operator Test
    cout << "Bigger or Equal [>=] Operator Test" << endl;
    cout << endl;
    if(Compare1 >= Compare4)
    {
        cout << Compare1.GetHour() << ":" << Compare1.GetMinute() << " Is Bigger or Equal to " << Compare4.GetHour() << ":" <<Compare4.GetMinute() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare1.GetHour() << ":" << Compare1.GetMinute() << " Is Bigger or Equal to " << Compare4.GetHour() << ":" <<Compare4.GetMinute() << endl;
        cout << "Is False" << endl;
    }

    cout << endl;

    if(Compare4 >= Compare3)
    {
        cout << Compare4.GetHour() << ":" << Compare4.GetMinute() << " Is Bigger or Equal to " << Compare3.GetHour() << ":" <<Compare3.GetMinute() << endl;
        cout << "Is True" << endl;
    }
    else
    {
        cout << Compare4.GetHour() << ":" << Compare4.GetMinute() << " Is Bigger or Equal to " << Compare3.GetHour() << ":" <<Compare3.GetMinute() << endl;
        cout << "Is False" << endl;
    }

    return 0;
}

