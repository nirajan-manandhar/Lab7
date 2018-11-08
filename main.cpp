#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule(vector<Course> v)
{
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
    ostream_iterator<Course> out_it (cout,"\n");
    copy( v.begin(), v.end(), out_it);
}

int main () {
    //TODO read from courses.txt
    string line;
    string name;
    char cDay;
    Course::dayOfWeek day;
    unsigned int sTime;
    unsigned int fTime;

    ifstream fin;
    fin.open("../courses.txt");
    vector<Course> courses;

    //TODO store data in an STL container
    while (getline(fin, line)) {
        istringstream iss(line);
        iss >> name >> cDay >> sTime >> fTime;
        cout << "cDay " << cDay << endl;
        switch (cDay) {
            case 'M':
                day = Course::MON;
                break;
            case 'T':
                day = Course::TUE;
                break;
            case 'W':
                day = Course::WED;
                break;
            case 'R':
                day = Course::THUR;
                break;
            case 'F':
                day = Course::FRI;
                break;
            case 'S':
                day = Course::SAT;
                break;
            case 'U':
                day = Course::SUN;
                break;
        }

        Course c{name, day, sTime, fTime};
        courses.push_back(c);
    }
    //TODO sort your STL container with the sort algorithm
    sort(courses.begin(), courses.end());


    //TODO implement code to determine schedule conflicts
    for (auto i = courses.begin(); i != courses.end()-1; ++i) {
        for (auto x = i+1; x != courses.end(); ++x) {

            int firstStart = i->start_time;
            int secondStart = x->start_time;
            int firstFinish = i->finish_time;
            int secondFinish = x->finish_time;

            if ((i->day == x->day) && (firstStart >= secondStart & firstStart <= secondFinish || firstFinish <= secondFinish & firstFinish >= secondStart)) {
                cout << "Conflict:" << endl;
                cout << *i << endl;
                cout << *x << endl;
                cout << endl;
            }


        }
    }
    //TODO print out schedule conflicts


    //TODO print out schedule
    //Prints the entire schedule
    printSchedule(courses);
    cout << "Find the TODOs in the code and implement them." << endl;
    cout << "Add/modify any functions/code you need to complete your task." << endl;
    return 0;
}