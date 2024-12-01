/**
 * @file std_norm.hpp
 * @author Andrei Batyrov
 * @brief Standard normal distribution basic functions implementation
 * @version 0.1
 * @date 2024-12-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef STD_NORM_HPP
#define STD_NORM_HPP

#include <cmath>

namespace std_norm
{
    const auto norm_coeff = 1.0 / std::pow(2.0 * M_PI, 0.5);

    /**
     * @brief Probability density function (PDF) for \f$ \mathcal{N}(0, 1) \f$:
     * 
     * \f$ \displaystyle f(x) = \frac{1}{\sqrt{2 \pi}} e^{-x^2 / 2} \f$.
     *
     * @param x
     * @return double
     */
    double pdf(double x)
    {
        return norm_coeff * std::exp(-0.5 * x * x);
    }

    /**
     * @brief Cumulative distribution function (CDF) for \f$ \mathcal{N}(0, 1) \f$:
     * 
     * \f$ \displaystyle \Phi(x) = \frac{1}{\sqrt{2 \pi}} \int_{-\infty}^{x} e^{-t^2 / 2} dt \f$.
     *
     * The definite integral calculation is adapted from 
     * [Michael Halls-Moore. C++ for Quantitative Finance, 2010](https://www.quantstart.com/cpp-for-quantitative-finance-ebook/) 
     * which in turn is an adaptation from
     * [Mark S. Joshi. C++ Design Patterns and Derivatives Pricing, 2nd Ed. Cambridge University Press, 2008](https://www.amazon.com/Patterns-Derivatives-Pricing-Mathematics-Finance/dp/0521721628/).
     *
     * @param x
     * @return double
     */
    double cdf(double x)
    {
        auto x_abs = std::abs(x);
        auto k = 1.0 / (1.0 + 0.2316419 * x_abs);
        auto k_sum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));
        if (x >= 0.0)
            return 1.0 - pdf(x_abs) * k_sum;
        else
            return pdf(x_abs) * k_sum;
    }
}

#endif // STD_NORM_HPP