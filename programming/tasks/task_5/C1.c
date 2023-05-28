// ice21390179
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define pi 3.141593653

double deg2rad(double d), sine(double r), cosine(double r);
void check(double a, double b, double r);

int main(int argc, char const *argv[]) {
  double d, r;
  printf("Εισάγετε μία γωνία σε μοίρες: ");
  scanf("%lf", &d);
  r = deg2rad(d);
  printf("Γωνία σε rad: %lf\n", r);
  check(sin(r), sine(r), r);
  check(cos(r), cosine(r), r);
  return 0;
}

double sine(double r) {
  int i = 3, sign = -1;
  double x1, x2 = r, sum = r;
  do {
    x1 = x2;
    x2 = x1 * pow(r, 2) / (i * (i - 1));
    sum = sum + sign * x2;
    sign = sign * (-1);
    i = i + 2;
  } while (fabs(x2 - x1) >= 0.000001);
  return sum;
}

void check(double a, double b, double r) {
  if (fabs(a - b) <= 0.000001) {
    printf("Οι συναρτήσεις βγάζουν το ίδιο αποτέλεσμα\n");

  } else {
    printf("Οι συναρτήσεις δεν βγάζουν το ίδιο αποτέλεσμα\n");
  }
  if (a == sin(r)) {
    printf("Το ημίτονο της γωνίας με χρήση της συνάρτησης sin() είναι %lf\n",
           sin(r));
    printf("Το ημίτονο της γωνίας με χρήση σειράς Τέιλορ είναι: %lf\n",
           sine(r));

  } else {
    printf("Το συνημίτονο της γωνίας με χρήση της συνάρτησης cos() είναι %lf\n",
           cos(r));
    printf("Το συνημίτονο της γωνίας με χρήση σειράς Τέιλορ είναι: %lf\n",
           cosine(r));
  }
}
double cosine(double r) {
  int i = 2, sign = -1;
  double x1, x2 = 1, sum = 1;
  do {
    x1 = x2;
    x2 = x1 * pow(r, 2) / (i * (i - 1));
    sum = sum + sign * x2;
    sign = sign * (-1);
    i = i + 2;
  } while (fabs(x2 - x1) >= 0.000001);
  return sum;
}

double deg2rad(double d) {
  double r;
  r = d * pi / 180;
  return r;
}
