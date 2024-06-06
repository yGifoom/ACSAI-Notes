The mean of a sample distribution, or the median will give us what's called a **point estimate** of the underlying distribution. These **estimators** must have two important properties:
- they must have no bias: they should be centered around the center of the distribution
- they must have low deviation

however, point estimators do not grant us any kind of parameter regarding the robustness of this estimation.

A confidence interval gives us an estimation of the confidence that the real parameter of a distribution falls not so far off from our estimator, and is defined thusly:

$CI = p+-z*s/sqrt(n)$

where p is the proportion of the sample distribution, s is its standard deviation and z is the confidence needed: for a 95% confidence z = 1.96, for 99% z = 2.576. 
To have more confidence we need to increase the error allowed in our estimation, which is not always desirable.

The  **standard error** (se) is just the standard deviation of the sample distribution, and represents how precise is our estimation of the real parameter of the population, *the bigger a sample is the lower the se will be*. 

What to do with a small n? If the underlying distribution of the population is normal, you can use the t distribution critical points instead of the normal one. The t distribution is just like a normal distribution but with higher variance, the more **degrees of freedom** (aka n-1) your dataset has the closer it will resemble a normal distribution, in fact when $n-> inf$ the t distribution becomes normal