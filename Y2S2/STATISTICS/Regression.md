**Regression** is a method of inference, which tries to explain some variable $Y$ with a linear relation (in our case with two parameters,  the intercept and the slope of the line) to $X$, mathematically: $$\hat{Y}=b_0+b_1\hat{X}$$

Our aim is finding the *parameters* of the line in the population, and through inference it is possible to approximate the real $Y$ value which is $$Y = \beta_0+\beta_1X+\epsilon$$
Where $$\epsilon\sim N(0,\sigma^2) $$
The accuracy of a given regression line is maximized when the **Mean squared error** (MSE) is minimized, or $\frac{1}{n-2} SSE$ , where $SSE = \sum(\hat{y}_i-y_i)^2$. MSE is the sample variance of the errors and estimates $\sigma^2$. This means that $\sqrt{E(MSE)}=s$, or the average deviation of the datapoints form their prediction on the line.

To quantify how good a model is we must minimize its $R^2$ factor, or *the fraction of variations in $\hat{Y}$ which are explained by $\hat{X}$* which is: $$R^2=\frac{SST-SSE}{SST}$$
where: $$SST = \sum(y_i-\bar{y})^2$$
keep in mind that $\sqrt{R^2} = r$ which is the correlation coefficient.