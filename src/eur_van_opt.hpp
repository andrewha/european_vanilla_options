/**
 * @file eur_van_opt.hpp
 * @author Andrei Batyrov
 * @brief European Vanilla Call and Put Options implementation
 * @version 0.1
 * @date 2024-12-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef EUR_VAN_OPT_HPP
#define EUR_VAN_OPT_HPP

#include "std_norm.hpp"

class EuropeanVanillaOption
{

public:
    
    /**
     * @brief Default constructor of a new European Vanilla Option object.
     *
     */
    EuropeanVanillaOption()
        // Init option with some default parameters
        : K_(100.0)   // $100
        , r_(0.05)    // 5% interest rate
        , T_(1.0)     // 1-year maturity
        , S_(100.0)   // Option is "at the money" as spot equals the strike
        , sigma_(0.2) // Volatility is 20%
    {
        calc_d_();
    }

    /**
     * @brief Parametric constructor of a new European Vanilla Option object.
     *
     * @param K Strike price of the option
     * @param r Risk-free interest rate
     * @param T Time to maturity (in years)
     * @param S Current price of the underlying asset
     * @param sigma Volatility of the underlying asset's returns
     */
    EuropeanVanillaOption(const double &K,
                          const double &r,
                          const double &T,
                          const double &S,
                          const double &sigma)
        : K_(K), r_(r), T_(T), S_(S), sigma_(sigma)
    {
        calc_d_();
    }

    /**
     * @brief Calculate Call option price:
     * 
     * \f$ \displaystyle C(S) = S N(d_1) - K e^{-r T} N(d_2) \f$, where
     * \f$ \displaystyle N = CDF_{\mathcal{N}(0, 1)} \f$.
     *
     * @return double
     */
    double callPrice() const
    {
        return S_ * std_norm::cdf(d_1_) - K_ * std::exp(-r_ * T_) * std_norm::cdf(d_2_);
    }

    /**
     * @brief Calculate Put option price:
     * 
     * \f$ \displaystyle P(S) = K e^{-r T} N(-d_2) - S N(-d_1) \f$, where
     * \f$ \displaystyle N = CDF_{\mathcal{N}(0, 1)} \f$.
     *
     * @return double
     */
    double putPrice() const
    {
        return K_ * std::exp(-r_ * T_) * std_norm::cdf(-d_2_) - S_ * std_norm::cdf(-d_1_);
    }

private:
    
    double K_, r_, T_, S_, sigma_, d_1_, d_2_;

    /**
     * @brief Calculate intermediate variables:
     * 
     * \f$ \displaystyle d_1 = \frac{ln(S/K) + (r + \sigma^2 / 2)T}{\sigma \sqrt{T}} \f$, 
     * represents a standardized measure of how far the current price S is from the strike price K 
     * after accounting for the time to maturity, risk-free rate, and volatility.
     * 
     * \f$ \displaystyle d_2 = d_1 - \sigma \sqrt{T} \f$, reflects the uncertainty (volatility) over the time to maturity.
     *
     */
    void calc_d_()
    {
        auto sigma_sqrt_T = sigma_ * std::pow(T_, 0.5);
        d_1_ = (std::log(S_ / K_) + (r_ + sigma_ * sigma_ * 0.5) * T_) / sigma_sqrt_T;
        d_2_ = d_1_ - sigma_sqrt_T;
    }
};

#endif // EUR_VAN_OPT_HPP