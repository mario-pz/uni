#include <cstring>
#include <iostream>

class BigInt {
private:
  char *numb;
  mutable int size;

public:
  BigInt();

  BigInt(const char *);

  BigInt(int);

  BigInt(const BigInt &);

  ~BigInt();

  void print() const;
};

BigInt::BigInt() {
  numb = new char[1];
  *numb = 0;
  size = 4;
}

BigInt::BigInt(const char *s) {
  int i;
  int l = strlen(s);
  if (l) {
    numb = new char[l];
    for (int i = 0; i < l; i++)
      *(numb + i) = *(s + l - i - 1) - 48;
    size = l;
  }
}

BigInt::BigInt(int n) {
  char *s = new char[n];
  sprintf(s, "%d", n);
  int i;
  int l = strlen(s);

  delete[] s;
}

BigInt::BigInt(const BigInt &x) {
  int i;
  size = x.size;
  numb = new char[size] for (int k = 0; k < size; k++) * (numb + k) = x.numb[k];
}

BigInt::~BigInt() { delete[] numb; }

void BigInt::print() const {
  for (int i = size - 1; i >= 0; i--)
    // χαρακτήρας + 48 = μετατροπή από πχ 1 -> '1'
    std::cout << *(numb + i) + 48 << std::endl;
}

// functions
void xyz() {
  BigInt A;
  A.print();

  BigInt B("123456");

  BigInt C(530);

  BigInt D = B;
}
