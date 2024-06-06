A sample distribution is a probability distribution of the statistics of a population.

They are built by taking i.i.d. (identical and independently distributed) samples of dimension **n** from a population, the proportions of the outcomes of the samples, weighted on their frequency, are the sampling distribution.

But why is it useful? By studying the probability of the outcome of samples over many trials it will be possible to estimate the likelihood of the statistics for a given population. 

For example, 30% of a population smokes, how likely it is that by sampling 10 people we find that at least 50% of those people smoke?

$m=p=.3, s=sqrt(p(1 - p)/n) = .144$
so $P(x > .5) = 1 - P(z < 1.39) = 0.08$
very unlikely....

Through enough samples __(the empirical rule of thumb is having n > 30)__ this distribution will be described by a normal distribution, this result should be familiar if you know the [[Central limit theorem]]. 
Being a normal distribution, the SD is described by two parameters, m and s.