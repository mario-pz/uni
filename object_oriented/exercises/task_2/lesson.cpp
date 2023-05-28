#include "./lesson.h"

Lesson::Lesson(const string &l_id, const string &l_n, const unsigned int &l_s) {
  this->lesson_id = l_id;
  this->lesson_name = l_n;
  this->lesson_semester = l_s;
}

Lesson::~Lesson() {}

const string &Lesson::get_lesson_id(void) const { return lesson_id; }

const string &Lesson::get_lesson_name(void) const { return lesson_name; }

const unsigned int &Lesson::get_semester(void) const { return lesson_semester; }
