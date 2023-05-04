#include "Date.h"

Date::Date() // Default Constructor
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

Date::Date(int day, int month, int year) // Parameter Constructor
{
    m_day = day;
    m_month = month;
    m_year = year;
}

// Setter
void Date::SetDay(int day)
{
    m_day = day;
}

void Date::SetMonth(int month)
{
    m_month = month;
}

void Date::SetYear(int year)
{
    m_year = year;
}

// Getter
int Date::GetDay() const
{
    return m_day;
}

int Date::GetMonth() const
{
    return m_month;
}

int Date::GetYear() const
{
    return m_year;
}

string Date::ConvertMonth(int month)
{
    switch(month)
    {
    case 1 :
        return "January";
    case 2 :
        return "February";
    case 3 :
        return "March";
    case 4 :
        return "April";
    case 5 :
        return "May";
    case 6 :
        return "June";
    case 7 :
        return "July";
    case 8 :
        return "August";
    case 9 :
        return "September";
    case 10 :
        return "October";
    case 11 :
        return "November";
    case 12 :
        return "December";
    }
}

// Overload "==" operator function and compare two Date objects
bool Date::operator == (const Date& date) const
{
    if(m_year == date.GetYear() && m_month == date.GetMonth() && m_day == date.GetDay())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Overload "<" operator function and compare two Date objects
bool Date::operator < (const Date& date) const
{
    if ((m_year < date.GetYear()) ||
            (m_year < date.GetYear() && m_month < date.GetMonth()) ||
            (m_year < date.GetYear() && m_month < date.GetMonth() && m_day < date.GetDay()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Overload ">" operator function and compare two Date objects
bool Date::operator > (const Date& date) const
{
    return!(*this == date || *this < date);
}

// Overload "<=" operator function and compare two Date objects
bool Date::operator <= (const Date& date) const
{
    return(*this == date || *this < date);
}

// Overload ">=" operator function and compare two Date objects
bool Date::operator >= (const Date& date) const
{
    return!(*this < date);
}

// ostream operator
ostream & operator << (ostream & os, const Date & date)
{
    os << "Date : " << date.GetDay() << "/" << date.GetMonth()
       << "/" << date.GetYear() << endl;

    return os;
}
