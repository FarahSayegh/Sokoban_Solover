#include "CompareF.h"

template <class T>
bool CompareF<T>::operator()(const T& x1, const T& x2) const
{
	return x1.getF() < x2.getF();
}