# Pricer-for-BSmodel

build file is `./pricer`

# How to calculate
This code calculates the (European) option value based on Black-Scholes model

* call option value = `e^{-rT} E(（S exp{(r-sigma^2/2)T + sigma * sqrt(T) * W} - K)^{+}]`
* put option value = `e^{-rT} E(（K -S exp{(r-sigma^2/2)T + sigma * sqrt(T) * W})^{+}]`

In this code, we calculate option value by using `monte carlo method` (<- the reason why I don't use the analytical solution is ... just for my exercise (^_^;)).  
And we get random numbers by using box-muller method.  
  
input is following
* type: 'call' or 'put'
* Expiry
* Strike
* Spot
* Vol
* r
* number of path