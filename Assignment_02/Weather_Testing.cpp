#include <iostream>
#include "Weather.h"

int main()
{
    Weather myWeather;

    myWeather.SetSolar(3);
    myWeather.SetSpeed(6);
    myWeather.SetTemp(9);

    myWeather.GetSolar();
    myWeather.GetSpeed();
    myWeather.GetTemp();

    cout <<"Weather-Test: (Solar) "<< myWeather.GetSolar() << endl;
    cout <<"Weather-Test: (Speed) "<< myWeather.GetSpeed() << endl;
    cout <<"Weather-Test: (Temperature) "<< myWeather.GetTemp() << endl;
    cout <<"Weather-Test: "<< myWeather.GetSolar() << ',' << myWeather.GetSpeed() << ',' << myWeather.GetTemp() << endl;

    return 0;
}
