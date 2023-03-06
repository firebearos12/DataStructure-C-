#include <iostream>
using namespace std;

template <class T> class Stack {
private:
  T *data;
  int top;
  int capacity;

public:
  Stack(int capacity = 2) {
    if (capacity < 0)
      throw "capacity must > 0";
    data = new T[capacity];
    this->capacity = capacity;
    top = -1;
  }
  ~Stack() {
    delete[] data;
    top = -1;
  }
  bool isEmpty() { return top == -1 ? true : false; }
  void push(T input) {
    if (top == capacity - 1) {
      cout << "\n<Stack is full... trying to load bigger Stack>\n";
      T *temp = new T[capacity + 10];
      for (int i = 0; i < capacity; i++) {
        temp[i] = data[i];
      }
      capacity += 10;
      delete[] data;
      data = temp;
    }
    top += 1;
    data[top] = input;
  };
  T pop() {
    if (isEmpty())
      throw "Stack is empty";
    return data[top--];
  };
};
