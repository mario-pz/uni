#include <math.h>
#include <stdio.h>

// Να γραφεί συνάρτηση η οποία θα λύνει τη δευτεροβάθμια εξίσωση (με παρόμοια
// λογική με την προηγούμενη άσκηση).
int quadratic_equation(double, double, double, double *, double *);

int main(void) {
  double a = 1, b = -5, c = 6;
  double x1, x2;
  int result = quadratic_equation(a, b, c, &x1, &x2);
  return 0;
}

int quadratic_equation(double a, double b, double c, double *x1, double *x2) {
  double discriminant = b * b - 4 * a * c;

  if (a == 0) {
    return 2;
  } else if (discriminant < 0) {
    return 1;
  } else if (discriminant == 0) {
    *x1 = -b / (2 * a);
    return 0;
  } else {
    *x1 = (-b + sqrt(discriminant)) / (2 * a);
    *x2 = (-b - sqrt(discriminant)) / (2 * a);
    return 0;
  }
}
