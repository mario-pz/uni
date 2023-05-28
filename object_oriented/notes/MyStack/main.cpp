#include <fstream>
#include <iostream>

template <class T> class MyStack {
  T *items;
  unsigned int item_size;

public:
  MyStack(const int & = 0);

  ~MyStack();

  unsigned int get_size() const;

  void pop();

  void add(const T &);

  void save();
};

template <class T> MyStack<T>::~MyStack() { delete[] items; }

template <class T> MyStack<T>::MyStack(const int &size) {
  items = new T[size];
  item_size = size;
}

template <class T> void MyStack<T>::pop() {

  try {
    if (item_size == 0) {
      throw "Η στοίβα είναι άδεια!";
    } else {

      std::cout << "-------------------------------------" << std::endl;
      std::cout << items[item_size] << " διαγράφετε." << std::endl;

      T *temp = new T[--item_size];
      for (int i = 0; i < item_size; i++)
        temp[i] = items[i];

      if (!items)
        delete[] items;

      items = new T[item_size];
      for (int i = 0; i < item_size; i++)
        items[i] = temp[i];

      delete[] temp;
    }
  } catch (const char *e) {
    std::cout << e << std::endl;
  }
}

template <class T> void MyStack<T>::add(const T &nt) {
  items[++item_size] = nt;
}

template <class T> unsigned int MyStack<T>::get_size() const {
  return item_size;
}

template <class T> void MyStack<T>::save() {

  std::ofstream file;

  file.open("δεδομένα.txt");

  if (file.is_open()) {
    for (int i = 0; i < item_size; i++)
      file << items[i] << std::endl;
  } else {
    std::cerr << "Απέτυχε η αποθήκευση της στοίβας" << std::endl;
  }
}

int main() {

  MyStack<float> floats;

  floats.add(15.4f);
  floats.add(12.3f);
  floats.add(4.2f);
  floats.add(210.4f);
  floats.pop();
  floats.add(120.5f);

  std::cout << floats.get_size() << std::endl;

  floats.save();

  return 0;
}
