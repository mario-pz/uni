#include <cstring>
#include <iostream>

class MyString {

  char *string_data;

public:
  MyString();

  MyString(const char *);

  ~MyString();

  MyString operator+(const char *);

  MyString &operator+=(const char *);

  char *get_string();

  unsigned int length();

  bool operator==(const MyString &);

  bool operator!=(const MyString &);

  bool operator<(const MyString &);

  bool operator>(const MyString &);
};

MyString::MyString() {
  string_data = new char;
  strcpy(string_data, " ");
}

MyString::~MyString() {
  if (!string_data)
    delete[] string_data;
}

MyString::MyString(const char *nstring) {
  string_data = new char[strlen(nstring) + 1];
  strcpy(string_data, nstring);
}

unsigned int MyString::length() { return strlen(string_data); }

bool MyString::operator!=(const MyString &nstring) {
  bool is_right = true;

  for (int i = 0; i < strlen(nstring.string_data); i++) {
    if (string_data[i] == nstring.string_data[i])
      is_right = false;
  }

  return is_right;
}

bool MyString::operator==(const MyString &nstring) {
  return strcmp(string_data, nstring)
}

bool MyString::operator<(const MyString &nstring) {
  return string_data[0] < nstring.string_data[0];
}

bool MyString::operator>(const MyString &nstring) {
  return string_data[0] > nstring.string_data[0];
}

char *MyString::get_string() { return string_data; }

MyString MyString::operator+(const char *str) {
  int new_size = length() + strlen(str);

  char *temp = new char[new_size + 1];
  strcpy(temp, string_data);

  for (uint_fast8_t i = length(); i < new_size; i++)
    *(temp + i) = *(str + i - length());

  temp[new_size] = '\0';

  MyString new_string(temp);
  delete[] temp;
  return new_string;
}

MyString &MyString::operator+=(const char *str) {
  *this = *this + str;
  return *this;
}

int main() {
  MyString bob("Yes.");

  bob += " No.";

  std::cout << bob.get_string() << " Len: " << bob.length() << std::endl;
}
