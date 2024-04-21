# Probability Density Function (PDF)
# The Probability Density Function (PDF) is a statistical measure used to evaluate 
# the probability distribution of a continuous random variable. 
# The PDF describes the likelihood of the variable taking on a particular value. 
# In the context of data analysis, it helps us understand the distribution of data 
# points across different values. The area under the PDF curve within a specific range 
# represents the probability of the variable falling within that range. 
# Mathematically, the total area under the PDF curve is equal to 1, 
# indicating the cumulative probability of all possible outcomes is 100%.
# 
# Cumulative Density Function (CDF)
# The Cumulative Density Function (CDF) represents the cumulative probability that 
# a continuous random variable takes on a value less than or equal to a particular value. 
# It provides a way to quantify the probability of observing certain outcomes 
# within a given range. 
# The CDF is a non-decreasing function that starts at 0 and asymptotically approaches 1 
# as the variable value increases. 
# In practical terms, the CDF allows us to determine the probability that the observed 
# data falls below a specific threshold, offering insights into the distribution's 
# overall shape and spread.
# 
# Complementary Cumulative Density Function (CCDF)
# The Complementary Cumulative Density Function (CCDF) is related to the CDF and represents 
# the probability that a continuous random variable takes on a value greater than a specific value.
# It is defined as 1 minus the CDF for a given value. 
# The CCDF is useful for analyzing the tail behavior of the distribution, 
# indicating the likelihood of observing extreme values. 
# In applications, the CCDF helps in understanding the risk of outliers and the 
# distribution of values in the upper range of the dataset.


# Load required libraries
library(ggplot2)  # For creating visualizations
library(reshape2) # For reshaping data

# Probability Density Function (PDF)
ggplot(data.frame(x = iris$Sepal.Length), aes(x = x)) +
  stat_function(fun = dnorm, args = list(mean = mean(iris$Sepal.Length), sd = sd(iris$Sepal.Length)), color = "blue") +
  labs(title = "PDF", x = "Sepal Length", y = "Density")

# Cumulative Density Function (CDF)
ggplot(data.frame(x = iris$Sepal.Length), aes(x = x)) +
  stat_function(fun = pnorm, args = list(mean = mean(iris$Sepal.Length), sd = sd(iris$Sepal.Length)), color = "red") +
  labs(title = "CDF", x = "Sepal Length", y = "Probability")

# Complementary Cumulative Density Function (CCDF)
ggplot(data.frame(x = iris$Sepal.Length), aes(x = x)) +
  stat_function(fun = function(x) 1 - pnorm(x, mean = mean(iris$Sepal.Length), sd = sd(iris$Sepal.Length)), color = "green") +
  labs(title = "CCDF", x = "Sepal Length", y = "Probability")

# Box plot
boxplot(iris$Sepal.Length, main = "Box Plot")

# QQ plot
qqnorm(iris$Sepal.Length)
qqline(iris$Sepal.Length)

# Heatmap
matrix_data <- cor(iris[, 1:4])  # Calculate correlation matrix
heatmap(matrix_data, col = cm.colors(256))




