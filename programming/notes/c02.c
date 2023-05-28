#include <math.h>
#include <stdio.h>

// Να γραφεί συνάρτηση η οποία θα λύνει την πρωτοβάθμια εξίσωση. Η συνάρτηση θα
// επιστρέφει (στο όνομά της) 0 αν έχει λύση, 1 αν είναι αδύνατη και δύο αν
// είναι αόριστη. Σε περίπτωση που έχει λύση θα επιστρέφει και τη ρίζα.
int primary_equation(double, double, double, double *);

int main(void) {
  double a = 1, b = -5, c = 6;
  double root;
  int result = primary_equation(a, b, c, &root);
  if (result == 0) {
    printf("Η εξίσωση έχει μια πραγματική λύση:%f.\n", root);
  } else if (result == 1) {
    printf("Η εξίσωση δεν έχει πραγματικές λύσεις.\n");
  } else {
    printf("Η εξίσωση δεν είναι τετραγωνική.\n");
  }
  return 0;
}

int primary_equation(double a, double b, double c, double *root) {
  double discriminant = b * b - 4 * a * c;
  if (a == 0) {
    // Equation is not quadratic
    if (b == 0)
      return 2;
    else {
      *root = -c / b;
      return 0;
    }
  } else if (discriminant < 0) {
    // Complex roots
    return 1;
  } else if (discriminant == 0) {
    // One real root
    *root = -b / (2 * a);
    return 0;
  } else {
    // Two real roots
    double sqrt_disc = sqrt(discriminant);
    *root = (-b + sqrt_disc) / (2 * a);
    printf("Η εξίσωση έχει δύο ρίζες\n");
    return 0;
  }
}
