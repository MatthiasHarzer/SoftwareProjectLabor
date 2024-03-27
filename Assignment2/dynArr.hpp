#ifndef __DYNARR__
#define __DYNARR__

#include <iostream>
using namespace std;

template<typename T>
void copy_(T* s, int n, T* t) {
  int i = 0;
  while(i < n) {
    t[i] = s[i];
    i++;
  }
}


template<typename T>
class DynArr {
  int len;
  T* p;

public:

  DynArr() {
    this->len = 0;
    this->p = nullptr;
  }
  DynArr(T x, int size) {
    this->len = size;
    this->p = new T[size];

    for(int i=0; i<size; i++) {
      this->p[i] = x;
    }
  }
  DynArr(const DynArr<T>& src) {
    this->len = src.len;
    this->p = new T[src.len];
    copy_(src.p, src.len, this->p);
  }
   DynArr<T>& operator=(const DynArr<T>& src) {
   // TODO
  }
  DynArr(DynArr<T>&& src) {
      this->len = src.p;
      this->p = src.p;
  }
  DynArr<T>& operator=(DynArr<T>&& src) {

      if(this != &src){
          delete this->len;
          delete[] this->p;

          this.
      }
  }


  ~DynArr() { delete[] p; }

  T& operator[](int index) {
    return p[index];
  }


  int size() const {
      return this->len;
  }

  string show() {
    string s;
    for(int i=0; i<this->len; i++) {
      s = s + to_string(p[i]);
    }
    return s;
  }


  void add(T x) {
   // TODO
  }

  void reverse() {
  // TODO
  }

  void append(const DynArr<T>& src) {
  // TODO
  }

};


#endif
