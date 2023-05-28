#include "student.h"
#include <ostream>

Student::Student(const char *n_am, string str, unsigned int sm,
                 const vector<pair<Lesson, float>> &lessons) {
  set_AM(n_am);
  full_name = str;
  semester = sm;
  this->lessons = lessons;
}

Student::~Student() {
  if (!AM)
    delete[] AM;
}

char *Student::get_AM() const { return AM; }

string Student::get_fullname() const { return full_name; }

unsigned int Student::get_semester() { return semester; }

void Student::increase_semester() { semester++; }

void Student::set_AM(const char *chr) {
  if (!AM)
    delete[] AM;

  AM = new char[strlen(chr) + 1];
  strcpy(AM, chr);
}

void Student::set_fullname(const string str) { full_name = str; }

void Student::set_semester(const int smt) { semester = smt; }

void Student::operator=(const Student &other) {
  this->AM = other.AM;
  this->full_name = other.full_name;
  this->lessons = other.lessons;
  this->semester = other.semester;
}

void Student::operator+=(const pair<Lesson, float> &lesson_pair) {
  this->lessons.push_back(lesson_pair);
}

bool Student::operator==(const Student &other) {
  return this->semester == other.semester;
}

bool Student::operator!=(const Student &other) {
  return this->semester != other.semester;
}

bool Student::operator<(const Student &other) {
  return this->semester < other.semester;
}

bool Student::operator>(const Student &other) {
  return this->semester > other.semester;
}

bool Student::operator<=(const Student &other) {
  return this->semester <= other.semester;
}

bool Student::operator>=(const Student &other) {
  return this->semester >= other.semester;
}

void Student::operator<<(ostream &stream) {
  float sum = 0;
  stream << "-----------------------------" << endl;
  stream << get_fullname() << " | " << get_AM() << endl;

  for (size_t i = 0; i < this->lessons.size(); i++) {
    sum += lessons[i].second;
    stream << lessons[i].first.get_lesson_name() << ": " << lessons[i].second
           << endl;
  }
  stream << "Μέσος Όρος: " << sum / lessons.size() << endl;
}

const vector<pair<Lesson, float>> &Student::get_lessons() const {
  return this->lessons;
}

const unsigned int &Student::get_semester() const { return semester; }

ostream &operator<<(ostream &stream, const Student &stud) {
  stream << stud.get_fullname() << " | " << stud.get_AM() << endl;

  for (size_t i = 0; i < stud.get_lessons().size(); i++)
    stream << stud.get_lessons()[i].first.get_lesson_name() << ": "
           << stud.get_lessons()[i].second << endl;

  return stream << stud.get_semester();
}

void Student::save_2_file(const string &name) {
  std::ofstream file(name + ".txt");
  if (file.is_open()) {
    file << *this;
    file.close();
  }
}
