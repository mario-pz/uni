
#ifndef LESSON_H
#define LESSON_H
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

class Lesson {
private:
  string lesson_id;
  string lesson_name;
  unsigned int lesson_semester;

public:
  Lesson(const string &, const string &, const unsigned int &);
  virtual ~Lesson();

  const string &get_lesson_id(void) const;

  const string &get_lesson_name(void) const;

  const unsigned int &get_semester(void) const;
};

#endif
