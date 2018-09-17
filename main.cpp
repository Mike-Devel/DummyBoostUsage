
#include <boost/system/error_code.hpp>

#include <iostream>

int main()
{
	auto err = boost::system::errc::make_error_condition(boost::system::errc::invalid_argument);
	std::cout << "Invalid argument error message: " << err.message() << '\n';
}