#pragma once
#include "myoptional.h"

MyOptional<double> divide(double numerator, double denominator) noexcept
{
	if (denominator == 0.0)
	{
		return MyOptional<double>();
	}
		
	return MyOptional<double>(numerator/ denominator);
}