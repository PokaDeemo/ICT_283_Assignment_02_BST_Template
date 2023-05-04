#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

/**
 * @class Date
 * @brief Date Class is created to store the day, month and year
 * @author Tan Hong Rui Freeman
 * @version 02
 * @date 22/11/2022 Freeman Tan, Started
 *
 */

using namespace std;

class Date
{
public:
    Date();
    /**
    * @brief Default Constructor for Date
    * @param An default constructor that is empty
    */

    Date(int day, int month, int year);
    /**
    * @brief Parameter Constructor for Date
    * @param An parameter constructor that is use to create or name the objects by variables.
    */

    // Setter
    void SetDay(int day);
    /**
    * @brief setter for the Day
    * @param day represents private m_day
    * @post day is changed
    */

    void SetMonth(int month);
    /**
    * @brief setter for the Month
    * @param month represents private m_month
    * @post month is changed
    */

    void SetYear(int year);
    /**
    * @brief setter for the Year
    * @param year represents private m_year
    * @post year is changed
    */

    // Getter
    int GetDay() const;
    /**
    * @brief getter for the Day
    * @pre m_day object must be initialised
    * @return the Day
    */

    int GetMonth() const;
    /**
    * @brief getter for the Month
    * @pre m_month object must be initialised
    * @return the Month
    */

    int GetYear() const;
    /**
    * @brief getter for the Year
    * @pre m_year object must be initialised
    * @return the Year
    */

    string ConvertMonth(int month);
    /**
    * @brief function to convert to the integer month into an string month
    * @param month must be initialized
    * @return string month
    */

    bool operator == (const Date& date) const;
    /**
    * @brief This function will overload the operator and compare the Date objects
    * @param Date& - date
    * @return true if two objects have the same value of day, month, year
    */

    bool operator < (const Date& date) const;
    /**
    * @brief This function will overload the operator and compare the Date objects
    * @param Date& - date
    * @return true if this day will come first
    */

    bool operator > (const Date& date) const;
    /**
    * @brief This function will overload the operator and compare the Date objects
    * @param Date& - date
    * @return true if this day will come later
    */

    bool operator <= (const Date& date) const;
    /**
    * @brief This function will overload the operator and compare the Date objects
    * @param Date& - date
    * @return true if two date objects have the same value of day, month, year or this day come first.
    */

    bool operator >= (const Date& date) const;
    /**
    * @brief This function will overload the operator and compare the Date objects
    * @param Date& - date
    * @return true if two objects have same value of day, month, year or this day come later
    */


private:
    int m_day;
    int m_month;
    int m_year;

    /**
     * @brief Private variables is to store and use the data
     * @param m_day represents day
     * @param m_month represents the month
     * @param m_year represents the year
     */
};

ostream & operator << (ostream & os, const Date & date);
/**
* @brief an overload output operator. Use to output the object or result
* @param ostream is reference to OS. That is use for the output stream using the #include <iostream> header
* @param date is just a object variable name that we created for Date.CPP ostream operator.
*/
#endif // DATE_H

