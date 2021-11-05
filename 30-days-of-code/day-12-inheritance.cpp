/*
 * File: /day-12-inheritance.cpp
 * Project: 30-days-of-code
 * Created Date: Friday November 5th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Friday November 5th 2021 1:04:29 am
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Person {
 protected:
  string firstName;
  string lastName;
  int id;

 public:
  Person(string firstName, string lastName, int identification) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = identification;
  }
  void printPerson() {
    cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n";
  }
};

class Student : public Person {
 private:
  vector<int> testScores;

 public:
  /*
   *   Class Constructor
   *
   *   Parameters:
   *   firstName - A string denoting the Person's first name.
   *   lastName - A string denoting the Person's last name.
   *   id - An integer denoting the Person's ID number.
   *   scores - An array of integers denoting the Person's test scores.
   */
  Student(string &firstName, string &lastName, int &id, vector<int> scores)
      : Person(firstName, lastName, id), testScores(scores) {}

  /*
   *   Function Name: calculate
   *   Return: A character denoting the grade.
   */
  char calculate() {
    double avg_score = 0;
    
    for (const auto& score : testScores) {
      avg_score += score;
    }

    avg_score = avg_score / testScores.size();
    
    if (avg_score >= 90) return 'O';
    else if (avg_score >= 80) return 'E';
    else if (avg_score >= 70) return 'A';
    else if (avg_score >= 55) return 'P';
    else if (avg_score >= 40) return 'D';
    else return 'T';
  }
};

int main() {
  string firstName;
  string lastName;
  int id;
  int numScores;
  cin >> firstName >> lastName >> id >> numScores;
  vector<int> scores;
  for (int i = 0; i < numScores; i++) {
    int tmpScore;
    cin >> tmpScore;
    scores.push_back(tmpScore);
  }
  Student *s = new Student(firstName, lastName, id, scores);
  s->printPerson();
  cout << "Grade: " << s->calculate() << "\n";
  return 0;
}