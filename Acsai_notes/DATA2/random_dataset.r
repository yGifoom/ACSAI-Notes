library(datasets)
class(iris)
set.seed(123123)
# create your own dataset
height <- rnorm(10, mean= 170, sd= 20)
weight <- rnorm(10, mean= 150, sd= 20)
head(height)

height <- round(height, 2)
weight <- round(weight, 2)

hw <- data.frame(h = height, w= weight)
print(head(hw))

# accessing each column wh $
hw$h # can index columns with hw[1], hw[2] ....

newguy <- c(140, 100) #a dataframe object
hw <- rbind(hw, newguy) # appending at the end of the dataframe the datapoint

age <- rnorm(11,25,2)
hw$age <- age # or equivalently cbind(hw, age)

# to remove a column hw <- subset(hw,select = -age)

#######################################################################
#defining functions
weird_squares <- function(n=4){
  return(n**2)
}

weird_squares(2)
#######################################################################
histo <- hist(iris$Sepal.Length)

# correlation between sepal lenght and width
a <- lm(iris$Sepal.Length~iris$Sepal.Width) # interpolation of data:
# fitting a linear function (Beta0 + Beta1X1+ Beta2X2+.... the spread of these 
# Betas cannot be wider than the standard dev, otherwise what the fuck are you fitting)
#to datapoints  in our dataset the result is a theoretical linear relation between two variables
str(a)
summary(a) #residual is the amount of data that we are not able to fit
plot(a)

# q-q residuals: relation betwen theorized residua of quantiles and observed residuals



############################################################################
# NO LOOPS OR QUATTROCIOCCHI KILLS YOU, use functions
letters <- c("q", "w", "r", "t", "y", "p", "s", "d")
vowels <- c("a", "e", "i", "o", "u")

lapply(hw, mean) # applies function, returning list

apply(hw, FUN=mean, MARGIN=2) # margin 1 is for rows and 2 for columns








