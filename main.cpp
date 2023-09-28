#include <iostream>
#include "myoptional.h"
#include "functions.h"

int main()
{
    std::cout << "TEST MYOPTIONAL 1.0\n\n";

	try
	{
		MyOptional<int> opt1(1);
		std::cout << opt1.value() << "\n";
		opt1.reset();
		std::cout << opt1.value_or(5) << "\n";

		auto opt2 = divide(3, 2);

		if (opt2.has_value())
		{
			std::cout << opt2.value() << "\n";
		}

		auto opt3 = divide(1, 0);

		std::cout << opt3.value_or(99) << "\n";
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Something went wrong\n";
	}
    

    return 0;
}
