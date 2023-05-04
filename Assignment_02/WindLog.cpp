#include "WindLog.h"

WindLog::WindLog()
{
    m_date = Date(0,0,0);
    m_time = Time(0,0);
    m_weather = Weather(0,0,0);
}

WindLog::WindLog(Date date, Time time, Weather weather)
{
    m_date = date;
    m_time = time;
    m_weather = weather;
}

void WindLog::SetDate(Date date)
{
    m_date = date;
}

void WindLog::SetTime(Time time)
{
    m_time = time;
}

void WindLog::SetWeather(Weather weather)
{
    m_weather = weather;
}

// Getter
Date WindLog::GetDate() const // Getter for the Date it will return the date object
{
    return m_date;
}

Time WindLog::GetTime() const // Getter for the Time it will return the time object
{
    return m_time;
}

Weather WindLog::GetWeather() const // Getter for the Weather it will return the weather object
{
    return m_weather;
}

// This function will overload the "==" and compare two WindLog Objects
bool WindLog::operator == (WindLog& windLog) const
{
    if(GetDate() == windLog.GetDate() && GetTime() == windLog.GetTime())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// This function will overload the "<" and compare two WindLog Objects
bool WindLog::operator < (WindLog& windLog) const
{
    if(GetDate() < windLog.GetDate() || (GetDate() == windLog.GetDate()
        && GetTime() < windLog.GetTime()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// This function will overload the ">" and compare two WindLog Objects
bool WindLog::operator > (WindLog& windLog) const
{
    return!(*this==windLog || *this < windLog);
}

// This function will overload the "<=" and compare two WindLog Objects
bool WindLog::operator <= (WindLog& windLog) const
{
    return(*this==windLog || *this < windLog);
}

// This function will overload the ">=" and compare two WindLog Objects
bool WindLog::operator >= (WindLog& windLog) const
{
    return!(*this<windLog);
}

ostream& operator << (ostream& os, const WindLog& windlog)
{
    os
            << windlog.GetDate() << "\n"
            <<"Time: " << windlog.GetTime() << "\n"
            << windlog.GetWeather()<< endl;

    return os;
}


