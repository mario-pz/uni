#include <iostream>

void swap(int &, int &);
int divide(int, int = 2);
float divide(float, float = 2.0f);

int main(void) {
  // Η αλλαγή τιμής σε const double.
  const double A = 1.0;

  double *B = (double *)&A;

  *B = 2.0;

  std::cout << "A:" << A << " στην θέση:" << &A << std::endl;
  std::cout << "Δείκτης B:" << *B << " στην θέση" << B << std::endl
            << std::endl;

  // χρήση των τελεστών new, new[], delete και delete[].

  double *d_number = new double(10.6);

  char *msg = new char[5 + 1];
  strcpy(msg, "hello");

  std::cout << msg << std::endl;
  std::cout << *d_number << std::endl;

  std::cout << "ελευθέρωση πραγματικού αριθμού.\n";

  std::cout << "ελευθέρωση δείκτη σταθερού χαρακτήρα." << std::endl
            << std::endl;

  delete d_number;
  delete[] msg;

  // Η χρήση της αναφοράς στις παραμέτρους και τον τύπο επιστροφής των
  // συναρτήσεων (δύο συναρτήσεις)

  int n1 = 5;
  int n2 = 4;

  std::cout << "Πρίν την μετακίνηση Ν1 Ν2\n";
  std::cout << n1 << " " << n2 << std::endl;

  swap(n1, n2);

  std::cout << "Μετά την μετακίνηση Ν1 Ν2\n";
  std::cout << n1 << " " << n2 << std::endl << std::endl;

  // Η υπερφόρτωση συνάρτησης και οι συναρτήσεις με παραμέτρους οι οποίες έχουν
  // default τιμές.

  float f1 = divide(5.0f, 1.5f);

  int i1 =
      divide(4); // Δεν έδωσα δεύτερο όρισμα άρα αυτόματα θα διαιρέσει διά 2

  std::cout << "Αποτέλεσμα F1:" << f1 << "\n"
            << "Αποτέλεσμα I1:" << i1 << std::endl;
}

float divide(float a, float b) { return a / b; }

int divide(int a, int b) { return a / b; }

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
