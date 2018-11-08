#include "Course.hpp"

using namespace std;

Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

Course & Course::operator =(const Course & m) {
    title = m.title;
    day = m.day;
    start_time = m.start_time;
    finish_time = m.finish_time;
    return *this;
}
bool Course::operator == (const Course & m) const {
    return title == m.title &&
        day == m.day &&
        start_time == m.start_time &&
        finish_time == m.finish_time;
}

bool Course::operator < (const Course & m) const
{

    if(day < m.day)
        return true;
    if(day == m.day && start_time < m.start_time)
        return true;
    return day == m.day && start_time == m.start_time && finish_time < m.finish_time;

}

ostream & operator << (ostream &os, const Course & m)
{

    char day;
    switch(m.day) {
        case 0:
            day = 'M';
            break;
        case 1:
            day = 'T';
            break;
        case 2:
            day = 'W';
            break;
        case 3:
            day = 'R';
            break;
        case 4:
            day = 'F';
            break;
        case 5:
            day = 'S';
            break;
        case 6:
            day = 'U';
            break;
        default:
            cout << "Default" << endl;
    }

    os << m.title << " " << day << " " << m.start_time << " " << m.finish_time << endl;
    return os;
}