#include <iostream>
#include <iomanip>
#include "eur_van_opt.hpp"

int main()
{
    std::cout << std::setfill('.') << std::setw(46) << '\n' << std::setfill(' ');
    std::cout << ": European Vanilla Options Price Calculator :" << std::endl;
    std::cout << std::setfill('.') << std::setw(46) << '\n' << std::setfill(' ');
    std::cout << std::fixed << std::setprecision(2);

    // Create a default option
    std::cout << "\nOption with some default parameters: K = $100.00, r = 5%, T = 1 year, S = $100.00, sigma = 20%" << std::endl;
    const auto default_option = EuropeanVanillaOption();
    std::cout << "Call price: $" << std::right << std::setw(5) << default_option.callPrice() << std::endl;
    std::cout << "Put  price: $" << std::right << std::setw(5) << default_option.putPrice() << std::endl;

    // Create a non-default option
    std::cout << "\nOption with user-defined parameters: K = $1000.00, r = 2.5%, T = 2 years, S = $1000.00, sigma = 10%" << std::endl;
    const auto non_default_option = EuropeanVanillaOption(1000.0, 0.025, 2.0, 1000.0, 0.1);
    std::cout << "Call price: $" << std::right << std::setw(5) << non_default_option.callPrice() << std::endl;
    std::cout << "Put  price: $" << std::right << std::setw(5) << non_default_option.putPrice() << std::endl;

    return EXIT_SUCCESS;
}
