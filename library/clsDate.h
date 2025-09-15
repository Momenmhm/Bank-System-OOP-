#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

class clsDate
{
  private:
    short _year, _month, _day;

    vector<string> split(string str, string space = "/")
    {
        string sword = "";
        vector<string> strInfo;
        short pos = 0;

        // find the separator and save index in pos
        while ((pos = str.find(space)) != std ::string ::npos)
        {
            //  cut a word and save it in vector
            sword = str.substr(0, pos);
            if (sword != "")
            {
                strInfo.push_back(sword);
            }
            str.erase(0, pos + space.length());
        }
        if (str != "")
            strInfo.push_back(str);

        return strInfo;
    }

    string Tap(short n)
    {
        string tap = "";
        for (short i = 0; i < n; i++)
        {
            tap += "     ";
        }
        return tap;
    }

    short DayOfWeekOrder(clsDate date)
    {
        short a = (14 - date._month) / 12;
        short y = date._year - a;
        short m = date._month + 12 * a - 2;

        short d = (date._day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;

        return d;
    }

  public:
    clsDate()
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        _year = now->tm_year + 1900;
        _month = now->tm_mon + 1;
        _day = now->tm_mday;
    }

    clsDate(string date)
    {
        vector<string> vstr = split(date, "/");
        _day = stoi(vstr[0]);
        _month = stoi(vstr[1]);
        _year = stoi(vstr[2]);
    }
    clsDate(short day, short month, short year)
    {
        _day = day;
        _month = month;
        _year = year;
    }
    clsDate(short days, short year)
    {
        _year = year;
        _month = 1;
        short daysinmonth = 0;
        short remenderdays = days;

        while (true)
        {
            daysinmonth = (*this).CountDaysInMonth();
            if (remenderdays > daysinmonth)
            {
                if (_month > 12)
                {
                    _month = 1;
                    _year++;
                }
                else
                {
                    remenderdays -= daysinmonth;
                    _month++;
                }
            }
            else
            {
                _day = remenderdays;
                break;
            }
        }
    }

    static bool LeapYear(short year)
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    bool LeapYear()
    {
        return (_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0;
    }

    short CountDaysInMonth()
    {
        short days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (_month == 2) ? ((*this).LeapYear() ? 29 : 28) : days[_month];
    }

    static short CountDaysInMonth(short month, short year)
    {
        short days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (month == 2) ? (LeapYear(year) ? 29 : 28) : days[month];
    }

    static short CalculatDayInYear(short year, short month, short day)
    {
        short a = (14 - month) / 12;
        short y = year - a;
        short m = month + 12 * a - 2;

        short d = (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;

        return d;
    }

    short CalculateDayInYear()
    {
        short a = (14 - _month) / 12;
        short y = _year - a;
        short m = _month + 12 * a - 2;

        short d = (_day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;

        return d;
    }

    static string GetDayName(short dayNumber)
    {
        string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        if (dayNumber < 0 || dayNumber > 6)
            return "Inv";

        return days[dayNumber];
    }

    string GetDayName()
    {
        short dayNumber = (*this).CalculateDayInYear();
        string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        if (dayNumber < 0 || dayNumber > 6)
            return "Inv";

        return days[dayNumber];
    }

    static string PrintMon(short daynumber)
    {
        string months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Agu", "Sep", "Oct", "Nov", "Dec"};

        return months[daynumber];
    }

    string PrintMon()
    {
        string months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Agu", "Sep", "Oct", "Nov", "Dec"};

        return months[_month];
    }

    static void MonthCalendar(short month, short year)
    {
        clsDate d;

        cout << "\n________________" << PrintMon(month) << "________________\n\n";

        cout << setw(5) << "Sun"; //<<  "  " ;
        cout << setw(5) << "Mon"; //<< "  ";
        cout << setw(5) << "Tue"; //<<  "  " ;
        cout << setw(5) << "Wed"; //<<  "  " ;
        cout << setw(5) << "Thu"; // <<  "  " ;
        cout << setw(5) << "Fri"; //<<  "  " ;
        cout << setw(5) << "Sat"; // <<  "  " ;
        cout << endl;

        cout << d.Tap(CalculatDayInYear(year, month, 1));
        short DaysOfMonth = d.CountDaysInMonth(month, year);

        for (short i = 1; i <= DaysOfMonth; i++)
        {
            if (d.CalculatDayInYear(year, month, i - 1) == 6)
                cout << endl;

            cout << setw(5) << i;
        }
        cout << "\n___________________________________\n";
    }

    void MonthCalendar()
    {
        cout << "\n________________" << PrintMon(_month) << "________________\n\n";

        cout << setw(5) << "Sun"; //<<  "  " ;
        cout << setw(5) << "Mon"; //<< "  ";
        cout << setw(5) << "Tue"; //<<  "  " ;
        cout << setw(5) << "Wed"; //<<  "  " ;
        cout << setw(5) << "Thu"; // <<  "  " ;
        cout << setw(5) << "Fri"; //<<  "  " ;
        cout << setw(5) << "Sat"; // <<  "  " ;
        cout << endl;

        cout << Tap(CalculatDayInYear(_year, _month, 1));
        short DaysOfMonth = (*this).CountDaysInMonth();

        for (short i = 1; i <= DaysOfMonth; i++)
        {
            if (CalculatDayInYear(_year, _month, i - 1) == 6)
                cout << endl;

            cout << setw(5) << i;
        }
        cout << "\n___________________________________\n";
    }

    static void YearCalendar(short year)
    {
        cout << "\n________________ Calendar -" << year << "________________\n\n";

        for (short month = 1; month <= 12; month++)
        {
            MonthCalendar(month, year);
            cout << "\n________________________________________\n";
        }
    }

    void YearCalendar()
    {
        cout << "\n________________ Calendar -" << _year << "________________\n\n";

        for (short month = 1; month <= 12; month++)
        {
            MonthCalendar(month, _year);
            cout << "\n________________________________________\n";
        }
    }

    static short DayFromBeginingTheYear(short y, short m, short d)
    {
        short Total_Days = d;
        clsDate date;

        for (short i = 1; i < m; i++)
        {
            Total_Days += date.CountDaysInMonth(i, y);
        }
        return Total_Days;
    }

    short DayFromBeginingTheYear()
    {
        short Total_Days = _day;

        for (short i = 1; i < _month; i++)
        {
            Total_Days += CountDaysInMonth(i, _year);
        }
        return Total_Days;
    }

    static bool IsDate1LessThanDate2(clsDate d1, clsDate d2)
    {
        return (d1._year < d2._year) ? true : (d2._year < d1._year) ? false : (d1._month < d2._month) ? true : (d2._month < d1._month) ? false : (d1._day < d2._day) ? true : false;
    }

    bool IsDateLessThanDate2(clsDate d2)
    {
        return ((*this)._year < d2._year) ? true : (d2._year < (*this)._year) ? false : ((*this)._month < d2._month) ? true : (d2._month < (*this)._month) ? false : ((*this)._day < d2._day) ? true : false;
    }

    bool IsDayIsLastInMonth()
    {
        return _day == CountDaysInMonth(_month, _year);
    }

    bool IsMonthIsLastInYear()
    {
        return (_month == 12);
    }

    static bool IsDayIsLastInMonth(clsDate d)
    {
        return d.IsDayIsLastInMonth();
    }

    static bool IsMonthIsLastInYear(short month)
    {
        return (month == 12);
    }


    static void IncreaseDateByOneDay(clsDate d)
    {
        d.IncreaseDateByOneDay();
    }

    static bool IsDate1EqualDate2(clsDate d1, clsDate d2)
    {
        return (d1._year != d2._year) ? false : (d2._month != d1._month) ? false : (d1._day != d2._day) ? false : true;
    }

    static bool IsDate1AfterDate2(clsDate d1, clsDate d2)
    {
        return (d1._year > d2._year ? true : (d1._year == d2._year ? (d1._month > d2._month ? true : (d1._month == d2._month ? (d1._day > d2._day ? true : false) : false)) : false));
    }

    static bool IsDate1BeforDate2(clsDate d1, clsDate d2)
    {
        return !IsDate1AfterDate2(d1, d2) && !IsDate1EqualDate2(d1, d2);
    }

    bool IsDate1EqualDate2(clsDate d2)
    {
        return d2.IsDate1EqualDate2((*this), d2);
    }

    bool IsDate1AfterDate2(clsDate d2)
    {
        return d2.IsDate1AfterDate2((*this), d2);
    }

    bool IsDate1BeforDate2(clsDate d2)
    {
        return !IsDate1AfterDate2((*this), d2) && !IsDate1EqualDate2((*this), d2);
    }

    void IncreaseDateByOneDay()
    {
        if ((*this).IsDayIsLastInMonth())
        {
            _day = 1;
            if (IsMonthIsLastInYear(_month))
            {
                (*this)._year++;
                (*this)._month = 1;
            }
            else
                this->_month++;
        }
        else
            this->_day++;

        return;
    }

    void DecreaseDateByOneDay()
    {
        if (this->_day == 1)
        {
            if (this->_month == 1)
            {
                this->_year--;
                this->_month = 12;
                _day = 31;
            }
            else

                (*this)._month--;
            this->_day = CountDaysInMonth(_year, _month);
        }
        else
            (*this)._day--;

        return;
    }

    bool IsDayWeekEnd()
    {
        return DayOfWeekOrder((*this)) == 6 || DayOfWeekOrder((*this)) == 5;
    }

    static bool IsDayWeekEnd(clsDate date)
    {
        return date.IsDayWeekEnd();
    }

    short CalculatVecationDays(clsDate enddate, bool including = false)
    {
        short diff = 0;
        while ((*this).IsDateLessThanDate2(enddate))
        {
            if (!IsDayWeekEnd(enddate))
            {
                diff++;
            }
            enddate.DecreaseDateByOneDay();
        }
        return including ? ++diff : diff;
    }

    bool IsBusinessDay()
    {
        return !IsDayWeekEnd((*this));
    }

    short DayUntilEndOfWeek()
    {
        return 6 - DayOfWeekOrder((*this));
    }

    short DayUntilEndOfMonth()
#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

class clsDate
{
  private:
    short _year, _month, _day;

    vector<string> split(string str, string space = "/")
    {
        string sword = "";
        vector<string> strInfo;
        short pos = 0;

        // find the separator and save index in pos
        while ((pos = str.find(space)) != std ::string ::npos)
        {
            //  cut a word and save it in vector
            sword = str.substr(0, pos);
            if (sword != "")
            {
                strInfo.push_back(sword);
            }
            str.erase(0, pos + space.length());
        }
        if (str != "")
            strInfo.push_back(str);

        return strInfo;
    }

    string Tap(short n)
    {
        string tap = "";
        for (short i = 0; i < n; i++)
        {
            tap += "     ";
        }
        return tap;
    }

    short DayOfWeekOrder(clsDate date)
    {
        short a = (14 - date._month) / 12;
        short y = date._year - a;
        short m = date._month + 12 * a - 2;

        short d = (date._day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;

        return d;
    }

  public:
    clsDate()
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        _year = now->tm_year + 1900;
        _month = now->tm_mon + 1;
        _day = now->tm_mday;
    }

    clsDate(string date)
    {
        vector<string> vstr = split(date, "/");
        _day = stoi(vstr[0]);
        _month = stoi(vstr[1]);
        _year = stoi(vstr[2]);
    }
    clsDate(short day, short month, short year)
    {
        _day = day;
        _month = month;
        _year = year;
    }
    clsDate(short days, short year)
    {
        _year = year;
        _month = 1;
        short daysinmonth = 0;
        short remenderdays = days;

        while (true)
        {
            daysinmonth = (*this).CountDaysInMonth();
            if (remenderdays > daysinmonth)
            {
                if (_month > 12)
                {
                    _month = 1;
                    _year++;
                }
                else
                {
                    remenderdays -= daysinmonth;
                    _month++;
                }
            }
            else
            {
                _day = remenderdays;
                break;
            }
        }
    }

    static bool LeapYear(short year)
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    bool LeapYear()
    {
        return (_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0;
    }

    short CountDaysInMonth()
    {
        short days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (_month == 2) ? ((*this).LeapYear() ? 29 : 28) : days[_month];
    }

    static short CountDaysInMonth(short month, short year)
    {
        short days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (month == 2) ? (LeapYear(year) ? 29 : 28) : days[month];
    }

    static short CalculatDayInYear(short year, short month, short day)
    {
        short a = (14 - month) / 12;
        short y = year - a;
        short m = month + 12 * a - 2;

        short d = (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;

        return d;
    }

    short CalculateDayInYear()
    {
        short a = (14 - _month) / 12;
        short y = _year - a;
        short m = _month + 12 * a - 2;

        short d = (_day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;

        return d;
    }

    static string GetDayName(short dayNumber)
    {
        string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        if (dayNumber < 0 || dayNumber > 6)
            return "Inv";

        return days[dayNumber];
    }

    string GetDayName()
    {
        short dayNumber = (*this).CalculateDayInYear();
        string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        if (dayNumber < 0 || dayNumber > 6)
            return "Inv";

        return days[dayNumber];
    }

    static string PrintMon(short daynumber)
    {
        string months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Agu", "Sep", "Oct", "Nov", "Dec"};

        return months[daynumber];
    }

    string PrintMon()
    {
        string months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Agu", "Sep", "Oct", "Nov", "Dec"};

        return months[_month];
    }

    static void MonthCalendar(short month, short year)
    {
        clsDate d;

        cout << "\n________________" << PrintMon(month) << "________________\n\n";

        cout << setw(5) << "Sun"; //<<  "  " ;
        cout << setw(5) << "Mon"; //<< "  ";
        cout << setw(5) << "Tue"; //<<  "  " ;
        cout << setw(5) << "Wed"; //<<  "  " ;
        cout << setw(5) << "Thu"; // <<  "  " ;
        cout << setw(5) << "Fri"; //<<  "  " ;
        cout << setw(5) << "Sat"; // <<  "  " ;
        cout << endl;

        cout << d.Tap(CalculatDayInYear(year, month, 1));
        short DaysOfMonth = d.CountDaysInMonth(month, year);

        for (short i = 1; i <= DaysOfMonth; i++)
        {
            if (d.CalculatDayInYear(year, month, i - 1) == 6)
                cout << endl;

            cout << setw(5) << i;
        }
        cout << "\n___________________________________\n";
    }

    void MonthCalendar()
    {
        cout << "\n________________" << PrintMon(_month) << "________________\n\n";

        cout << setw(5) << "Sun"; //<<  "  " ;
        cout << setw(5) << "Mon"; //<< "  ";
        cout << setw(5) << "Tue"; //<<  "  " ;
        cout << setw(5) << "Wed"; //<<  "  " ;
        cout << setw(5) << "Thu"; // <<  "  " ;
        cout << setw(5) << "Fri"; //<<  "  " ;
        cout << setw(5) << "Sat"; // <<  "  " ;
        cout << endl;

        cout << Tap(CalculatDayInYear(_year, _month, 1));
        short DaysOfMonth = (*this).CountDaysInMonth();

        for (short i = 1; i <= DaysOfMonth; i++)
        {
            if (CalculatDayInYear(_year, _month, i - 1) == 6)
                cout << endl;

            cout << setw(5) << i;
        }
        cout << "\n___________________________________\n";
    }

    static void YearCalendar(short year)
    {
        cout << "\n________________ Calendar -" << year << "________________\n\n";

        for (short month = 1; month <= 12; month++)
        {
            MonthCalendar(month, year);
            cout << "\n________________________________________\n";
        }
    }

    void YearCalendar()
    {
        cout << "\n________________ Calendar -" << _year << "________________\n\n";

        for (short month = 1; month <= 12; month++)
        {
            MonthCalendar(month, _year);
            cout << "\n________________________________________\n";
        }
    }

    static short DayFromBeginingTheYear(short y, short m, short d)
    {
        short Total_Days = d;
        clsDate date;

        for (short i = 1; i < m; i++)
        {
            Total_Days += date.CountDaysInMonth(i, y);
        }
        return Total_Days;
    }

    short DayFromBeginingTheYear()
    {
        short Total_Days = _day;

        for (short i = 1; i < _month; i++)
        {
            Total_Days += CountDaysInMonth(i, _year);
        }
        return Total_Days;
    }

    static bool IsDate1LessThanDate2(clsDate d1, clsDate d2)
    {
        return (d1._year < d2._year) ? true : (d2._year < d1._year) ? false : (d1._month < d2._month) ? true : (d2._month < d1._month) ? false : (d1._day < d2._day) ? true : false;
    }

    bool IsDateLessThanDate2(clsDate d2)
    {
        return ((*this)._year < d2._year) ? true : (d2._year < (*this)._year) ? false : ((*this)._month < d2._month) ? true : (d2._month < (*this)._month) ? false : ((*this)._day < d2._day) ? true : false;
    }

    bool IsDayIsLastInMonth()
    {
        return _day == CountDaysInMonth(_month, _year);
    }

    bool IsMonthIsLastInYear()
    {
        return (_month == 12);
    }

    static bool IsDayIsLastInMonth(clsDate d)
    {
        return d.IsDayIsLastInMonth();
    }

    static bool IsMonthIsLastInYear(short month)
    {
        return (month == 12);
    }


    static void IncreaseDateByOneDay(clsDate d)
    {
        d.IncreaseDateByOneDay();
    }

    static bool IsDate1EqualDate2(clsDate d1, clsDate d2)
    {
        return (d1._year != d2._year) ? false : (d2._month != d1._month) ? false : (d1._day != d2._day) ? false : true;
    }

    static bool IsDate1AfterDate2(clsDate d1, clsDate d2)
    {
        return (d1._year > d2._year ? true : (d1._year == d2._year ? (d1._month > d2._month ? true : (d1._month == d2._month ? (d1._day > d2._day ? true : false) : false)) : false));
    }

    static bool IsDate1BeforDate2(clsDate d1, clsDate d2)
    {
        return !IsDate1AfterDate2(d1, d2) && !IsDate1EqualDate2(d1, d2);
    }

    bool IsDate1EqualDate2(clsDate d2)
    {
        return d2.IsDate1EqualDate2((*this), d2);
    }

    bool IsDate1AfterDate2(clsDate d2)
    {
        return d2.IsDate1AfterDate2((*this), d2);
    }

    bool IsDate1BeforDate2(clsDate d2)
    {
        return !IsDate1AfterDate2((*this), d2) && !IsDate1EqualDate2((*this), d2);
    }

    void IncreaseDateByOneDay()
    {
        if ((*this).IsDayIsLastInMonth())
        {
            _day = 1;
            if (IsMonthIsLastInYear(_month))
            {
                (*this)._year++;
                (*this)._month = 1;
            }
            else
                this->_month++;
        }
        else
            this->_day++;

        return;
    }

    void DecreaseDateByOneDay()
    {
        if (this->_day == 1)
        {
            if (this->_month == 1)
            {
                this->_year--;
                this->_month = 12;
                _day = 31;
            }
            else

                (*this)._month--;
            this->_day = CountDaysInMonth(_year, _month);
        }
        else
            (*this)._day--;

        return;
    }

    bool IsDayWeekEnd()
    {
        return DayOfWeekOrder((*this)) == 6 || DayOfWeekOrder((*this)) == 5;
    }

    static bool IsDayWeekEnd(clsDate date)
    {
        return date.IsDayWeekEnd();
    }

    short CalculatVecationDays(clsDate enddate, bool including = false)
    {
        short diff = 0;
        while ((*this).IsDateLessThanDate2(enddate))
        {
            if (!IsDayWeekEnd(enddate))
            {
                diff++;
            }
            enddate.DecreaseDateByOneDay();
        }
        return including ? ++diff : diff;
    }

    bool IsBusinessDay()
    {
        return !IsDayWeekEnd((*this));
    }

    short DayUntilEndOfWeek()
    {
        return 6 - DayOfWeekOrder((*this));
    }

    short DayUntilEndOfMonth()
    {
        return CountDaysInMonth(_year, _month) - _day;
    }

    short DayUntilEndOfYear()
    {
        short total_days = DayFromBeginingTheYear(_year, _month, _day);
        return LeapYear(_year) ? 366 - total_days : 365 - total_days;
    }

    static bool IsBusinessDay(clsDate d)
    {
        return !IsDayWeekEnd(d);
    }

    short DayUntilEndOfWeek(clsDate d)
    {
        return 6 - DayOfWeekOrder(d);
    }

    short DayUntilEndOfMonth(clsDate date)
    {
        return CountDaysInMonth(date._year, date._month) - date._day;
    }

    short DayUntilEndOfYear(clsDate date)
    {
        short total_days = DayFromBeginingTheYear(date._year, date._month, date._day);
        return LeapYear(date._year) ? 366 - total_days : 365 - total_days;
    }

    //            void  CalculatVacationDate ( short days){
    //
    //                clsDate date = (*this);
    //                while (days > 0 ){
    //
    //                    if (! IsDayWeekEnd (date)){
    //                        days-- ;
    //                    }
    //                    date.IncreaseDateByOneDay();
    //                }
    //                date.print();
    //            }
    //
    //            static void  CalculatVacationDate ( clsDate date , short days){
    //                      }
    //                date.CalculatVacationDate(days);
    //            }

    void Swap(clsDate &d2)
    {
        clsDate temp;

        temp._year = (*this)._year;
        temp._month = (*this)._month;
        temp._day = (*this)._day;

        (*this)._year = d2._year;
        (*this)._month = d2._month;
        (*this)._day = d2._day;

        d2._year = temp._year;
        d2._month = temp._month;
        d2._day = temp._day;
    }

    static void Swap(clsDate &d1, clsDate &d2)
    {
        d1.Swap(d2);
    }
    bool IsDateInPeriod(clsDate from, clsDate to)
    {
        if (IsDate1AfterDate2(from, to))
        {
            Swap(from, to);
        }

        return !(IsDate1AfterDate2(clsDate(this->_day, this->_month, this->_year), from) || IsDate1BeforDate2(clsDate(this->_day, this->_month, this->_year), to));
    }

    static bool IsDateInPeriod(clsDate date, clsDate from, clsDate to)
    {
        date.IsDateInPeriod(from, to);
    }

    bool IsValidateDate()
    {
        bool isdayok;
        if (LeapYear((*this)._year))
        {
            isdayok = (*this)._day < 30 && (*this)._day > 0;
        }
        else
        {
            isdayok = (*this)._day < 29 && (*this)._day > 0;
        }
        return isdayok && ((*this)._month > 0 && (*this)._month < 13) && ((*this)._year > 0);
    }

    static bool IsValidateDate(clsDate date){
            return date.IsValidateDate();
        }
        

    static string GetCurrentDateTime(){
        time_t now = time(0);
        tm *timeinfo = localtime(&now);
        
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        
        return string(buffer);
    }
    

    void print()
    {
        
           cout  << _day << "/" << _month << "/" << _year << endl;
    }
#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

class clsDate
{
  private:
    short _year, _month, _day;

    vector<string> split(string str, string space = "/")
    {
        string sword = "";
        vector<string> strInfo;
        short pos = 0;

        // find the separator and save index in pos
        while ((pos = str.find(space)) != std ::string ::npos)
        {
            //  cut a word and save it in vector
            sword = str.substr(0, pos);
            if (sword != "")
            {
                strInfo.push_back(sword);
            }
            str.erase(0, pos + space.length());
        }
        if (str != "")
            strInfo.push_back(str);

        return strInfo;
    }

    string Tap(short n)
    {
        string tap = "";
        for (short i = 0; i < n; i++)
        {
            tap += "     ";
        }
        return tap;
    }

    short DayOfWeekOrder(clsDate date)
    {
        short a = (14 - date._month) / 12;
        short y = date._year - a;
        short m = date._month + 12 * a - 2;

        short d = (date._day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;

        return d;
    }

  public:
    clsDate()
    {
        time_t t = time(0);
        tm *now = localtime(&t);
        _year = now->tm_year + 1900;
        _month = now->tm_mon + 1;
        _day = now->tm_mday;
    }

    clsDate(string date)
    {
        vector<string> vstr = split(date, "/");
        _day = stoi(vstr[0]);
        _month = stoi(vstr[1]);
        _year = stoi(vstr[2]);
    }
    clsDate(short day, short month, short year)
    {
        _day = day;
        _month = month;
        _year = year;
    }
    clsDate(short days, short year)
    {
        _year = year;
        _month = 1;
        short daysinmonth = 0;
        short remenderdays = days;

        while (true)
        {
            daysinmonth = (*this).CountDaysInMonth();
            if (remenderdays > daysinmonth)
            {
                if (_month > 12)
                {
                    _month = 1;
                    _year++;
                }
                else
                {
                    remenderdays -= daysinmonth;
                    _month++;
                }
            }
            else
            {
                _day = remenderdays;
                break;
            }
        }
    }

    static bool LeapYear(short year)
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    bool LeapYear()
    {
        return (_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0;
    }

    short CountDaysInMonth()
    {
        short days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (_month == 2) ? ((*this).LeapYear() ? 29 : 28) : days[_month];
    }

    static short CountDaysInMonth(short month, short year)
    {
        short days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return (month == 2) ? (LeapYear(year) ? 29 : 28) : days[month];
    }

    static short CalculatDayInYear(short year, short month, short day)
    {
        short a = (14 - month) / 12;
        short y = year - a;
        short m = month + 12 * a - 2;

        short d = (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;

        return d;
    }

    short CalculateDayInYear()
    {
        short a = (14 - _month) / 12;
        short y = _year - a;
        short m = _month + 12 * a - 2;

        short d = (_day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;

        return d;
    }

    static string GetDayName(short dayNumber)
    {
        string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        if (dayNumber < 0 || dayNumber > 6)
            return "Inv";

        return days[dayNumber];
    }

    string GetDayName()
    {
        short dayNumber = (*this).CalculateDayInYear();
        string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        if (dayNumber < 0 || dayNumber > 6)
            return "Inv";

        return days[dayNumber];
    }

    static string PrintMon(short daynumber)
    {
        string months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Agu", "Sep", "Oct", "Nov", "Dec"};

        return months[daynumber];
    }

    string PrintMon()
    {
        string months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Agu", "Sep", "Oct", "Nov", "Dec"};

        return months[_month];
    }

    static void MonthCalendar(short month, short year)
    {
        clsDate d;

        cout << "\n________________" << PrintMon(month) << "________________\n\n";

        cout << setw(5) << "Sun"; //<<  "  " ;
        cout << setw(5) << "Mon"; //<< "  ";
        cout << setw(5) << "Tue"; //<<  "  " ;
        cout << setw(5) << "Wed"; //<<  "  " ;
        cout << setw(5) << "Thu"; // <<  "  " ;
        cout << setw(5) << "Fri"; //<<  "  " ;
        cout << setw(5) << "Sat"; // <<  "  " ;
        cout << endl;

        cout << d.Tap(CalculatDayInYear(year, month, 1));
        short DaysOfMonth = d.CountDaysInMonth(month, year);

        for (short i = 1; i <= DaysOfMonth; i++)
        {
            if (d.CalculatDayInYear(year, month, i - 1) == 6)
                cout << endl;

            cout << setw(5) << i;
        }
        cout << "\n___________________________________\n";
    }

    void MonthCalendar()
    {
        cout << "\n________________" << PrintMon(_month) << "________________\n\n";

        cout << setw(5) << "Sun"; //<<  "  " ;
        cout << setw(5) << "Mon"; //<< "  ";
        cout << setw(5) << "Tue"; //<<  "  " ;
        cout << setw(5) << "Wed"; //<<  "  " ;
        cout << setw(5) << "Thu"; // <<  "  " ;
        cout << setw(5) << "Fri"; //<<  "  " ;
        cout << setw(5) << "Sat"; // <<  "  " ;
        cout << endl;

        cout << Tap(CalculatDayInYear(_year, _month, 1));
        short DaysOfMonth = (*this).CountDaysInMonth();

        for (short i = 1; i <= DaysOfMonth; i++)
        {
            if (CalculatDayInYear(_year, _month, i - 1) == 6)
                cout << endl;

            cout << setw(5) << i;
        }
        cout << "\n___________________________________\n";
    }

    static void YearCalendar(short year)
    {
        cout << "\n________________ Calendar -" << year << "________________\n\n";

        for (short month = 1; month <= 12; month++)
        {
            MonthCalendar(month, year);
            cout << "\n________________________________________\n";
        }
    }

    void YearCalendar()
    {
        cout << "\n________________ Calendar -" << _year << "________________\n\n";

        for (short month = 1; month <= 12; month++)
        {
            MonthCalendar(month, _year);
            cout << "\n________________________________________\n";
        }
    }

    static short DayFromBeginingTheYear(short y, short m, short d)
    {
        short Total_Days = d;
        clsDate date;

        for (short i = 1; i < m; i++)
        {
            Total_Days += date.CountDaysInMonth(i, y);
        }
        return Total_Days;
    }

    short DayFromBeginingTheYear()
    {
        short Total_Days = _day;

        for (short i = 1; i < _month; i++)
        {
            Total_Days += CountDaysInMonth(i, _year);
        }
        return Total_Days;
    }

    static bool IsDate1LessThanDate2(clsDate d1, clsDate d2)
    {
        return (d1._year < d2._year) ? true : (d2._year < d1._year) ? false : (d1._month < d2._month) ? true : (d2._month < d1._month) ? false : (d1._day < d2._day) ? true : false;
    }

    bool IsDateLessThanDate2(clsDate d2)
    {
        return ((*this)._year < d2._year) ? true : (d2._year < (*this)._year) ? false : ((*this)._month < d2._month) ? true : (d2._month < (*this)._month) ? false : ((*this)._day < d2._day) ? true : false;
    }

    bool IsDayIsLastInMonth()
    {
        return _day == CountDaysInMonth(_month, _year);
    }

    bool IsMonthIsLastInYear()
    {
        return (_month == 12);
    }

    static bool IsDayIsLastInMonth(clsDate d)
    {
        return d.IsDayIsLastInMonth();
    }

    static bool IsMonthIsLastInYear(short month)
    {
        return (month == 12);
    }


    static void IncreaseDateByOneDay(clsDate d)
    {
        d.IncreaseDateByOneDay();
    }

    static bool IsDate1EqualDate2(clsDate d1, clsDate d2)
    {
        return (d1._year != d2._year) ? false : (d2._month != d1._month) ? false : (d1._day != d2._day) ? false : true;
    }

    static bool IsDate1AfterDate2(clsDate d1, clsDate d2)
    {
        return (d1._year > d2._year ? true : (d1._year == d2._year ? (d1._month > d2._month ? true : (d1._month == d2._month ? (d1._day > d2._day ? true : false) : false)) : false));
    }

    static bool IsDate1BeforDate2(clsDate d1, clsDate d2)
    {
        return !IsDate1AfterDate2(d1, d2) && !IsDate1EqualDate2(d1, d2);
    }

    bool IsDate1EqualDate2(clsDate d2)
    {
        return d2.IsDate1EqualDate2((*this), d2);
    }

    bool IsDate1AfterDate2(clsDate d2)
    {
        return d2.IsDate1AfterDate2((*this), d2);
    }

    bool IsDate1BeforDate2(clsDate d2)
    {
        return !IsDate1AfterDate2((*this), d2) && !IsDate1EqualDate2((*this), d2);
    }

    void IncreaseDateByOneDay()
    {
        if ((*this).IsDayIsLastInMonth())
        {
            _day = 1;
            if (IsMonthIsLastInYear(_month))
            {
                (*this)._year++;
                (*this)._month = 1;
            }
            else
                this->_month++;
        }
        else
            this->_day++;

        return;
    }

    void DecreaseDateByOneDay()
    {
        if (this->_day == 1)
        {
            if (this->_month == 1)
            {
                this->_year--;
                this->_month = 12;
                _day = 31;
            }
            else

                (*this)._month--;
            this->_day = CountDaysInMonth(_year, _month);
        }
        else
            (*this)._day--;

        return;
    }

    bool IsDayWeekEnd()
    {
        return DayOfWeekOrder((*this)) == 6 || DayOfWeekOrder((*this)) == 5;
    }

    static bool IsDayWeekEnd(clsDate date)
    {
        return date.IsDayWeekEnd();
    }

    short CalculatVecationDays(clsDate enddate, bool including = false)
    {
        short diff = 0;
        while ((*this).IsDateLessThanDate2(enddate))
        {
            if (!IsDayWeekEnd(enddate))
            {
                diff++;
            }
            enddate.DecreaseDateByOneDay();
        }
        return including ? ++diff : diff;
    }

    bool IsBusinessDay()
    {
        return !IsDayWeekEnd((*this));
    }

    short DayUntilEndOfWeek()
    {
        return 6 - DayOfWeekOrder((*this));
    }

    short DayUntilEndOfMonth()
    {
        return CountDaysInMonth(_year, _month) - _day;
    }

    short DayUntilEndOfYear()
    {
        short total_days = DayFromBeginingTheYear(_year, _month, _day);
        return LeapYear(_year) ? 366 - total_days : 365 - total_days;
    }

    static bool IsBusinessDay(clsDate d)
    {
        return !IsDayWeekEnd(d);
    }

    short DayUntilEndOfWeek(clsDate d)
    {
        return 6 - DayOfWeekOrder(d);
    }

    short DayUntilEndOfMonth(clsDate date)
    {
        return CountDaysInMonth(date._year, date._month) - date._day;
    }

    short DayUntilEndOfYear(clsDate date)
    {
        short total_days = DayFromBeginingTheYear(date._year, date._month, date._day);
        return LeapYear(date._year) ? 366 - total_days : 365 - total_days;
    }

    //            void  CalculatVacationDate ( short days){
    //
    //                clsDate date = (*this);
    //                while (days > 0 ){
    //
    //                    if (! IsDayWeekEnd (date)){
    //                        days-- ;
    //                    }
    //                    date.IncreaseDateByOneDay();
    //                }
    //                date.print();
    //            }
    //
    //            static void  CalculatVacationDate ( clsDate date , short days){
    //                      }
    //                date.CalculatVacationDate(days);
    //            }

    void Swap(clsDate &d2)
    {
        clsDate temp;

        temp._year = (*this)._year;
        temp._month = (*this)._month;
        temp._day = (*this)._day;

        (*this)._year = d2._year;
        (*this)._month = d2._month;
        (*this)._day = d2._day;

        d2._year = temp._year;
        d2._month = temp._month;
        d2._day = temp._day;
    }

    static void Swap(clsDate &d1, clsDate &d2)
    {
        d1.Swap(d2);
    }
    bool IsDateInPeriod(clsDate from, clsDate to)
    {
        if (IsDate1AfterDate2(from, to))
        {
            Swap(from, to);
        }

        return !(IsDate1AfterDate2(clsDate(this->_day, this->_month, this->_year), from) || IsDate1BeforDate2(clsDate(this->_day, this->_month, this->_year), to));
    }

    static bool IsDateInPeriod(clsDate date, clsDate from, clsDate to)
    {
        date.IsDateInPeriod(from, to);
    }

    bool IsValidateDate()
    {
        bool isdayok;
        if (LeapYear((*this)._year))
        {
            isdayok = (*this)._day < 30 && (*this)._day > 0;
        }
        else
        {
            isdayok = (*this)._day < 29 && (*this)._day > 0;
        }
        return isdayok && ((*this)._month > 0 && (*this)._month < 13) && ((*this)._year > 0);
    }

    static bool IsValidateDate(clsDate date){
            return date.IsValidateDate();
        }
        

    static string GetCurrentDateTime(){
        time_t now = time(0);
        tm *timeinfo = localtime(&now);
        
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        
        return string(buffer);
    }
    

    void print()
    {
        
           cout  << _day << "/" << _month << "/" << _year << endl;
    }
};Enter};Enter    {
        return CountDaysInMonth(_year, _month) - _day;
    }

    short DayUntilEndOfYear()
    {
        short total_days = DayFromBeginingTheYear(_year, _month, _day);
        return LeapYear(_year) ? 366 - total_days : 365 - total_days;
    }

    static bool IsBusinessDay(clsDate d)
    {
        return !IsDayWeekEnd(d);
    }

    short DayUntilEndOfWeek(clsDate d)
    {
        return 6 - DayOfWeekOrder(d);
    }

    short DayUntilEndOfMonth(clsDate date)
    {
        return CountDaysInMonth(date._year, date._month) - date._day;
    }

    short DayUntilEndOfYear(clsDate date)
    {
        short total_days = DayFromBeginingTheYear(date._year, date._month, date._day);
        return LeapYear(date._year) ? 366 - total_days : 365 - total_days;
    }

    //            void  CalculatVacationDate ( short days){
    //
    //                clsDate date = (*this);
    //                while (days > 0 ){
    //
    //                    if (! IsDayWeekEnd (date)){
    //                        days-- ;
    //                    }
    //                    date.IncreaseDateByOneDay();
    //                }
    //                date.print();
    //            }
    //
    //            static void  CalculatVacationDate ( clsDate date , short days){
    //                      }
    //                date.CalculatVacationDate(days);
    //            }

    void Swap(clsDate &d2)
    {
        clsDate temp;

        temp._year = (*this)._year;
        temp._month = (*this)._month;
        temp._day = (*this)._day;

        (*this)._year = d2._year;
        (*this)._month = d2._month;
        (*this)._day = d2._day;

        d2._year = temp._year;
        d2._month = temp._month;
        d2._day = temp._day;
    }

    static void Swap(clsDate &d1, clsDate &d2)
    {
        d1.Swap(d2);
    }
    bool IsDateInPeriod(clsDate from, clsDate to)
    {
        if (IsDate1AfterDate2(from, to))
        {
            Swap(from, to);
