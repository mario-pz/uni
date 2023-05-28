
#ifndef STUDENT_H
#define STUDENT_H
#include "./lesson.h"

using namespace std;
class Student {
protected:
  char *AM;
  string full_name;
  unsigned int semester;
  vector<pair<Lesson, float>> lessons;

public:
  /* Constructor */
  Student(const char *, string, unsigned int,
          const vector<pair<Lesson, float>> &);

  /* Destructor */
  ~Student();

  /* Getters */
  char *get_AM() const;
  string get_fullname() const;
  unsigned int get_semester();

  /* Setters */
  void increase_semester();
  void set_AM(const char *);
  void set_fullname(const string);
  void set_semester(const int);

  void operator=(const Student &);

  void operator+=(const pair<Lesson, float> &);

  bool operator==(const Student &);
  bool operator!=(const Student &);
  bool operator<(const Student &);
  bool operator>(const Student &);
  bool operator<=(const Student &);
  bool operator>=(const Student &);

  void operator<<(ostream &);

  ostream &operator<<(const Student &);

  const vector<pair<Lesson, float>> &get_lessons() const;
  const unsigned int &get_semester() const;

  void save_2_file(const string &);
};

#endif
