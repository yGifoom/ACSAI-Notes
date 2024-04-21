# EXERCISE 6
# Generate QQ plots for Sepal Width and Petal Width. 
# Compare them with the QQ plot for Sepal Length and discuss which variable appears 
# to be the most normally distributed based on the QQ plots.

# importing necessary libraries
library(ggplot2)
library(datasets)

# checking the imported dataset
head(iris)
summary(iris)

# how does qq plot behave? if we feed it random gaussian the line will describe the distribution
normale <- rnorm(150, mean=0, sd=0)
par(mfrow = c(1,2)) # to display two graphs one beside the other
qqnorm(iris$Sepal.Length, ylab="Sepal Length", xlab="A normal distribution")
qqline(iris$Sepal.Length, lwd=2, col="red") # this graph 

qqnorm(normale, ylab="constant distribution", xlab="A normal distribution")
qqline(normale, lwd=2, col="blue") # is comparable to this

# Now to the actual exercise
qqnorm(iris$Sepal.Width); qqline(iris$Sepal.Width, lwd=2, col="red")
qqnorm(iris$Petal.Width); qqline(iris$Petal.Width, lwd=2, col="blue")
# I think that the petal width is not totally normally distributed,
# instead it will be denser around the left tail
# to check this:

# hurray!
ggplot(data.frame(x = iris$Petal.Width), aes(x = x)) +
  stat_function(fun = dnorm, args = list(mean = mean(iris$Sepal.Length), sd = sd(iris$Sepal.Length)), color = "blue") +
  labs(title = "PDF", x = "Petal Width", y = "Density")
hist(iris$Sepal.Width, xlab= "Sepal Width", col= "red", main = "Sepal width")
hist(iris$Petal.Width, xlab= "Petal Width", col= "blue", main = "Petal width")


