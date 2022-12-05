#pragma once

template <class T>
class CompareDistance
{
public:
	bool operator()(const T& x1, const T& x2)const;
};
