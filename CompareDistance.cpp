#include "CompareDistance.h"

template <class T>
bool CompareDistance<T>::operator()(const T& x1, const T& x2) const
{
	return x1.getDistance() < x2.getDistance();
}