/*myFile1b.h, Ex1 a4 CSI2372A
Ayman Naciri
300143727
anaci032@uottawa.ca*/

#ifndef MYFILE1B_H
#define MYFILE1B_H
#include <iostream>
#include "myFile1a.h" // add header 1a
using namespace std;

class Student {
	int numID;
	int nbCourses;
	int maxCourses;
	int* List_grades;
	Course** List_courses;
public:
    Student(int id, int maxCoursesAllowed) : numID(id), nbCourses(0), maxCourses(maxCoursesAllowed) {
        List_grades = new int[maxCourses];
        List_courses = new Course*[maxCourses];
    }
    ~Student() {
        delete[] List_grades;
        delete[] List_courses;
    }
    double average() {
        int sum = 0;
        for (int i = 0; i < nbCourses; i++) {
            sum += List_grades[i];
        }
        return nbCourses > 0 ? static_cast<double>(sum) / nbCourses : 0;
    }
    int totalHours() {
        int total = 0;
        for (int i = 0; i < nbCourses; i++) {
            total += List_courses[i]->getHours();
        }
        return total;
    }
    bool addCourse(Course* course, int grade) {
        if (nbCourses < maxCourses) {
            List_courses[nbCourses] = course;
            List_grades[nbCourses] = grade;
            nbCourses++;
            return true;
        }
        return false;
    }
};

#endif

