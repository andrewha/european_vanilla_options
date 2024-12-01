### European Vanilla Options

This is an example implementation in C++ of European vanilla call and put options. This example is an adaption from the book "C++ for Quantitative Finance" by (C) Michael Halls-Moore, 2010.

Price of a European vanilla option can be described by 5 parameters:
Parameter  | Type          | Description
:---------:|:--------------|:---------
$K$        | double (real) | Strike price of the option
$r$        | double (real) | Risk-free interest rate
$T$        | double (real) | Time to maturity (in years)
$S$        | double (real) | Current price of the underlying asset
$\sigma$   | double (real) | Volatility of the underlying asset's returns

Then the prices can be calculated using the known closed-form solution of the Black-Scholes equation as follows:
- Call: $C(S) = S N(d_1) - K e^{-r T} N(d_2)$, where $N = CDF_{\mathcal{N}(0, 1)}$;
- Put: $P(S) = K e^{-r T} N(-d_2) - S N(-d_1)$.

You can build a sample option price calculator such as [main.cpp](src/main.cpp) using the [CMakeLists.txt](CMakeLists.txt). No external libraries are required, only the C++ Standard Library.

Examples of price calculation:

```
.............................................
: European Vanilla Options Price Calculator :
.............................................

Option with some default parameters: K = $100.00, r = 5%, T = 1 year, S = $100.00, sigma = 20%
Call price: $10.45
Put  price: $ 5.57

Option with user-defined parameters: K = $1,000.00, r = 2.5%, T = 2 years, S = $1,000.00, sigma = 10%
Call price: $82.78
Put  price: $34.01
```