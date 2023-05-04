#include <iostream>
#include "Time.h"

// Default Constructor
Time::Time()
{
    m_hour = 0;
    m_minute = 0;
}

// Parameter Constructor
Time::Time(int hours, int minutes)
{
    m_hour = hours;
    m_minute = minutes;
}

// Setter
void Time::SetHour(int hours)
{
    m_hour = hours;
}

void Time::SetMinute(int minutes)
{
    m_minute = minutes;
}

// Getter
int Time::GetHour() const
{
    return m_hour;
}

int Time::GetMinute() const
{
    return m_minute;
}

// compare or check for equals two Time objects
bool Time::operator == (const Time& time) const
{
    if(GetMinute() == time.GetMinute() && GetHour() == time.GetHour())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// overload operator of "<" for the time
bool Time::operator < (const Time& time) const
{
    if(GetHour() < time.GetHour() || (GetHour() == time.GetHour()
                                      && GetMinute() < time.GetMinute()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// overload the "<" operator to compare two Time objects
bool Time::operator > (const Time& time) const
{
    return!(*this==time || *this < time);
}

// overload the "<=" operator to compare two Time objects
bool Time::operator <= (const Time& time) const
{
    return(*this==time || *this < time);
}

// overload the ">=" operator to compare two Time objects
bool Time::operator >= (const Time& time) const
{
    return!(*this < time);
}

ostream & operator << (ostream & os, const Time & time)
{
    os << time.GetHour() << ":" << time.GetMinute() << endl;

    return os;
}
