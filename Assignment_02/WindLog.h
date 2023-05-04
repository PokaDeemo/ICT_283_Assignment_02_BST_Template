#ifndef WINDLOG_H
#define WINDLOG_H

#include <iostream>
#include "Date.h"
#include "Time.h"
#include "Weather.h"

using namespace std;

/**
 * @class WindLog
 * @brief WindLog Class is created to store the Date Class, Time Class and Weather Class
 * @author Tan Hong Rui Freeman
 * @version 02
 * @date 22/11/2022 Freeman Tan, Started
 *
 */

class WindLog
{
public:
    WindLog();
    /**
    * @brief Default Constructor for WindLog
    * @param An default constructor that is empty
    */

    WindLog(Date date, Time time, Weather weather);
    /**
    * @brief Parameter Constructor for WindLog
    * @param An parameter constructor that is use to create or name the objects by variables.
    */

    void SetDate(Date date);
    /**
    * @brief setter for the Date that is calling from the Date class
    * @param date represents private m_date
    * @post d is changed
    */

    void SetTime(Time time);
    /**
    * @brief setter for the Time that is calling from the Time class
    * @param time represents private m_time
    * @post time is changed
    */

    void SetWeather(Weather weather);
    /**
    * @brief setter for the Weather that is calling from the Time class
    * @param weather represents private m_weather
    * @post weather is changed
    */

    Date GetDate() const;
    /**
    * @brief getter for the Date from the Date Class
    * @pre m_date object must be initialised
    * @return Get Date informations
    */

    Time GetTime() const;
    /**
    * @brief getter for the Time from the Time Class
    * @pre m_time object must be initialised
    * @return Get Time informations
    */

    Weather GetWeather() const;
    /**
    * @brief getter for the Time from the Weather Class
    * @pre m_weather object must be initialised
    * @return Get Weather informations
    */

    bool operator == (WindLog& windLog) const;
    /**
    * @brief This function will overload the "==" operator and will compare two WindLog Objects
    * @param WindLog& - windLog
    * @return true if two objects have the same value of Time, Date
    */

    bool operator < (WindLog& windLog) const;
    /**
    * @brief This function will overload the "<" operator and will compare two WindLog Objects
    * @param WindLog& - windLog
    * @return true if two objects have the same value of Time, Date
    */

    bool operator > (WindLog& windLog) const;
    /**
    * @brief This function will overload the ">" operator and will compare two WindLog Objects
    * @param WindLog& - windLog
    * @return true if two objects have the same value of Time, Date
    */

    bool operator <= (WindLog& windLog) const;
    /**
    * @brief This function will overload the "<=" operator and will compare two WindLog Objects
    * @param WindLog& - windLog
    * @return true if two objects have the same value of Time, Date
    */

    bool operator >= (WindLog& windLog) const;
    /**
    * @brief This function will overload the ">=" operator and will compare two WindLog Objects
    * @param WindLog& - windLog
    * @return true if two objects have the same value of Time, Date
    */

private:
    Date m_date;
    Time m_time;
    Weather m_weather;

};

ostream& operator << (ostream& os, const WindLog& windlog);
/**
* @brief an overload output operator. Use to output the object or result
* @param ostream is reference to OS. That is use for the output stream using the #include <iostream> header
* @param windlog is just a object variable name that we created for windlog.CPP ostream operator.
*/



#endif // WINDLOGTYPE_H

