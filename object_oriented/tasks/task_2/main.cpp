#include "student.h"

int main() {
  setlocale(LC_ALL, "");

  vector<Lesson> database;
  database.push_back(Lesson("390", "Εισαγωγή Υπολογιστών", 1));
  database.push_back(Lesson("391", "Προγραμματισμός Υπολογιστών", 1));
  database.push_back(Lesson("392", "Διακριτά μαθηματικά", 1));
  database.push_back(Lesson("393", "Γραμμική Άλγεβρα", 1));
  database.push_back(Lesson("394", "Μαθηματική Ανάλυση Ι", 1));

  srand(time(NULL));

  vector<pair<Lesson, float>> pand_lessons;

  for (size_t i = 0; i < 4; i++)
    pand_lessons.push_back(make_pair(database[i], (float)(rand() % 10)));

  Student Pand("ice12312345", "Παντελίδις", 3, pand_lessons);

  Pand << cout;

  Pand.save_2_file("Παντελής775");

  cout << endl << "Αντιγραφή φοιτητή Παντελή στην φοιτήτρια Μαρία\n";

  Student Maria(Pand);

  Maria.set_AM("ice21012356");
  Maria.set_fullname("Μαρία Ηλιοπούλου");
  Maria.set_semester(4);
  Maria += make_pair(Lesson("401", "Βάσεις Δεδομένων Ι", 2), 4.38f);
  Maria << cerr;
  Maria.save_2_file("Μάρια335");

  cout << endl << endl;

  if (Pand != Maria)
    cout << "Η Mαρία και ο Παντελίς είναι σε διαφορετικά εξάμηνα" << endl;

  if (Pand > Maria)
    cout << "Ο Παντελίς έχει μεγαλύτερο εξάμηνο" << endl;

  if (Pand < Maria)
    cout << "Ο Παντελίς έχει μικρότερο εξάμηνο" << endl;

  if (Pand >= Maria)
    cout << "Ο Παντελίς έχει μεγαλύτερο ίσο εξάμηνο με την Μαρία" << endl;

  if (Pand <= Maria)
    cout << "Ο Παντελίς έχει μικρότερο ίσο εξάμηνο με την Μαρία" << endl;
}
