By constructing a [[Sample Distrtibution|SD]] from a population we can evaluate some statistics, which could evaluate the parameters of  the population and allow us to draw conclusions about some event. This update of belief works in 5 stages:
- **Assumptions**: what we assume is true about the population, (`E.g. like normality or magnitude of the samples`)
- **Hypothesis**: two hypothesis are formulated and as the likelihood that one will explain the population better will be compared and the most likely picked. One is the **Null Hypothesis** (or  $H_0$ ), which  supports the status quo, the previous knowledge (`E.g. does smoking reduce life expectancy? $H_0$ supports the no, we have no prior knowledge about the effect that smoking has on the body`), whereas the **Alternative Hypothesis** ($H_1$ or $H_a$) supports the idea which is the aim of the study (`E.g. yes, smoking decreases life expectancy`)
- **Test Statistic**: the statistic of $H_0$ and $H_1$ are compared:
		$$z = \frac{(\mu_{1}-\mu_{0})}{\sigma}\cdot\sqrt{n}$$
- **$p$ evaluation**: the $p$ value obtained is the likelihood of seeing the sampling data given the $H_0$ is true, or the likelihood of a [[Type I error]], $P(Z > z)$ or $P(Z<z)$, which is the possibility of a false negative if $\mu_1$ was the parameter describing the population. The *significance* of these statistics is precisely this $p$ value: if it is very small it signifies that there is little to no error in rejecting the null hypothesis. 
- ***Conclusion***: the depending on the evaluation of the p value, conclusions about the significance of a finding can be drawn, and $H_0$ accepted or rejected. The threshold for a significant $p$ value can vary according to the study, usually it is $p<0,05$ or $p<0,01$.


