#ifndef __DYNARR__
#define __DYNARR__

#include <iostream>

using namespace std;

template<typename T>
void copy_(T *s, int n, T *t) {
    int i = 0;
    while (i < n) {
        t[i] = s[i];
        i++;
    }
}


template<typename T>
class DynArr {
    int len;
    T *p;

public:

    DynArr() {
        this->len = 0;
        this->p = nullptr;
    }

    DynArr(T x, int size) {
        this->len = size;
        this->p = new T[size];

        for (int i = 0; i < size; i++) {
            this->p[i] = x;
        }
    }

    DynArr(const DynArr<T> &src) {
        this->len = src.len;
        this->p = new T[src.len];
        copy_(src.p, src.len, this->p);
    }
    DynArr<T> &operator=(const DynArr<T> &src) {
        if (this != &src) {
            delete[] this->p;
            this->len = src.len;
            this->p = new T[src.len];
            copy_(src.p, src.len, this->p);
        }
        return *this;
    }

    DynArr(DynArr<T> &&src) {
        this->len = src.len;
        this->p = src.p;
        src.p = nullptr;
        src.len = 0;
    }

    DynArr<T> &operator=(DynArr<T> &&src) {

        if (this != &src) {
            delete[] this->p;
            this->len = src.len;
            this->p = src.p;
            src.p = nullptr;
            src.len = 0;
        }
        return *this;
    }


    ~DynArr() {
        delete[] p;
    }

    T &operator[](int index) {
        return p[index];
    }


    int size() const {
        return this->len;
    }

    string show() {
        string s;
        for (int i = 0; i < this->len; i++) {
            s = s + to_string(p[i]);
        }
        return s;
    }


    void add(T x) {
        T *temp = new T[this->len + 1];
        copy_(this->p, this->len, temp);
        temp[this->len] = x;
        delete[] this->p;
        this->p = temp;
        this->len++;
    }

    void reverse() {
        T *temp = new T[this->len];
        for (int i = 0; i < this->len; i++) {
            temp[i] = this->p[this->len - i - 1];
        }
        delete[] this->p;
        this->p = temp;
    }

    void append(const DynArr<T> &src) {
        T *temp = new T[this->len + src.len];
        copy_(this->p, this->len, temp);

        for (int i = 0; i < src.len; i++) {
            temp[this->len + i] = src.p[i];
        }

        delete[] this->p;
        this->p = temp;
        this->len += src.len;
    }

};


#endif
