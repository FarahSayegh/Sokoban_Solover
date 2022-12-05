#include "CompareCost.h"

template <class T>
bool CompareCost<T>::operator()(const T& x1, const T& x2) const
{
	return x1.getCost() < x2.getCost();
}