#pragma once

template <class T>
class CompareCost 
{
public:
	bool operator()(const T& x1, const T& x2)const;
};