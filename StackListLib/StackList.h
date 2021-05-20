#pragma once
#include "List.h"
#include "ExceptionLib.h"

template <class T>
class TStackList : public TList<T>
{
protected:
  int size;
public:
  TStackList<T>(int _size = 10);
  TStackList<T>(TStackList<T> &A);
  ~TStackList();
  void Put(T A);
  T Get();
  int GetMaxSize();
  int GetSize();
  T MaxElem();
  T MinElem();
  bool IsEmpty();
  bool IsFull();
  void Print();
  void file();
};

template <class T>
TStackList<T>::TStackList(int _size) : TList<T>()
{
  if (_size <= 0)
    throw MyException("Error size");
  size = _size;
}

template <class T>
TStackList<T>::TStackList(TStackList<T> &A) : TList<T>(A)
{
  TList<T>::count = A.count;
}

template<class T>
TStackList<T>::~TStackList() 
{}

template <class T>
void TStackList<T>::Put(T A)
{
  if (this->IsFull())
    throw MyException("StackList is Full");
  TList<T>::PutBegin(A);
}

template <class T>
T TStackList<T>::Get() 
{
  if (this->IsEmpty())
    throw MyException("StackList is Empty");
  return TList<T>::GetBegin();
}
template <class T>
int TStackList<T>::GetMaxSize() 
{
  return size;
}

template<class T>
inline int TStackList<T>::GetSize()
{
  return TList<T>::count;
}

template <class T>
bool TStackList<T>::IsEmpty() 
{
  if (TList<T>::count == 0)
    return true;
  return false;
}

template<class T>
bool TStackList<T>::IsFull()
{
  if (TList<T>::count == size)
    return true;
  return false;
}

template<class T>
void TStackList<T>::Print()
{
  if (this->IsEmpty())
    throw MyException("StackList is Empty");
  TList<T>::Print();
}

template<class T>
void TStackList<T>::file()
{
  ofstream out;
  out.open("StackList.txt", ios::app);
  if (out.is_open())
  {
    TList<T>::filel(out);
  }
  cout << endl << endl << "File written" << endl;
}

template<class T>
inline T TStackList<T>::MinElem()
{
  TElem<T>* a = this->begin;
  T tmp = a->GetData();
  while (a->GetNext() != 0)
  {
    T tmp_for = a->GetData();
    if (tmp > tmp_for)
      tmp = tmp_for;
    a = a->GetNext();
  }
  T tmp_for = a->GetData();
  if (tmp > tmp_for)
    tmp = tmp_for;
  return tmp;
}

template<class T>
inline T TStackList<T>::MaxElem()
{
  TElem<T>* a = this->begin;
  T tmp = a->GetData();
  while (a->GetNext() != 0)
  {
    T tmp_for = a->GetData();
    if (tmp < tmp_for)
      tmp = tmp_for;
    a = a->GetNext();
  }
  return tmp;
}
