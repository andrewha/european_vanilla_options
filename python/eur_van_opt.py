"""
European Vanilla Call and Put Options implementation
author: Andrei Batyrov
version: 0.1
date: 2024-12-01
copyright: Copyright (c) 2024
"""
import numpy as np
from scipy.stats import norm

class EuropeanVanillaOption():
    """
    Constructor a new European Vanilla Option object.
    """

    def __init__(self, K: float=100.0, r: float=0.05, T: float=1.0, S: float=100.0, sigma: float=0.2):
        """
        Init with some default values.

        Parameters
        ----------
        K : float, optional
            Strike price of the option, by default 100.0
        r : float, optional
            Risk-free interest rate, by default 0.05
        T : float, optional
            Time to maturity (in years), by default 1.0
        S : float, optional
            Current price of the underlying asset, by default 100.0
        sigma : float, optional
            Volatility of the underlying asset's returns, by default 0.2
        """
        self.K_ = K
        self.r_ = r
        self.T_ = T
        self.S_ = S
        self.sigma_ = sigma
        # Calculate intermediate variables
        sigma_sqrt_T = self.sigma_ * np.sqrt(self.T_)
        self.d_1_ = (np.log(self.S_ / self.K_) + (self.r_ + self.sigma_ * self.sigma_ * 0.5) * self.T_) / sigma_sqrt_T
        self.d_2_ = self.d_1_ - sigma_sqrt_T


    def call_price(self):
        """
        Calculate Call option price.
        """
        return self.S_ * norm.cdf(self.d_1_) - self.K_ * np.exp(-self.r_ * self.T_) * norm.cdf(self.d_2_)


    def put_price(self):
        """
        Calculate Put option price.
        """
        return self.K_ * np.exp(-self.r_ * self.T_) * norm.cdf(-self.d_2_) - self.S_ * norm.cdf(-self.d_1_)
