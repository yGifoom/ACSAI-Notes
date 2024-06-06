library(igraph)
g1 <- graph(edges = c(1,2, 2,3, 3,1, 4,1, 10,1), n=10, directed=F)

plot(g1)

g3 <- graph( c("John", "Jim", "Jim", "Jill", "Jill", "John")) # named vertices
# When the edge list has vertex names, the number of nodes is not needed
plot(g3)

g4 <- graph( c("John", "Jim", "Jim", "Jack", "Jim", "Jack", "John", "John"), 
             isolates=c("Jesse", "Janis", "Jennifer", "Justin") )  
# In named graphs we can specify isolates by providing a list of their names.
plot(g4)

plot(g4, edge.arrow.size=.5, vertex.color="gold", vertex.size=15, 
     vertex.frame.color="gray", vertex.label.color="black", 
     vertex.label.cex=1.5, vertex.label.dist=2, edge.curved=0.2) 

# access graphj adjecency matrix
g4[] # has sparse parameter set to T
V(g4)$name # automatically generated when we created the network

# adding values to the graph
V(g4)$gender <- c("male", "male", "male", "male", "female", "female", "male")
E(g4)$type <- "email" # Edge attribute, assign "email" to all edges
E(g4)$weight <- sample(10,ecount(g4))    # Edge weight, setting all existing edges to 10

g4

# show the weights
E(g4)$weight

# SIMPLIFY
g4 <- set_vertex_attr(g4,"color",value=c("skyblue", "skyblue", "skyblue", "skyblue", 
                                         "bisque", "bisque", "skyblue"))

plot(g4, edge.arrow.size=.5, vertex.color=V(g4)$color, vertex.size=15, 
     vertex.frame.color="gray", vertex.label.color="black", 
     vertex.label.cex=1.5, vertex.label.dist=2, edge.curved=0.2) 

g4_simplified <- simplify(g4, remove.multiple = T, remove.loops = F, 
                          edge.attr.comb=list(weight="sum", type="ignore"))
#this way of simplifying doesn't keep EDGE multiplicity
g4_simplified

##################################################################################################
# replicate paper: plot clustering coefficient and diameter as a func of rewiring probability

# Creates a lattice with 'dim' dimensions of 'size' nodes each, and rewires edges 
# randomly with probability 'p'. You can allow 'loops' and 'multiple' edges.
# The neighborhood in which edges are connected is 'nei'.

er_lcc <- c()
er_avpl <- c()
set.seed(100)
for(p in seq(from = 0, to =  1, by =0.01)){
  er = sample_gnp(100,p, directed = F, loops = F)
  lcc = max(components(er)$csize)
  avpl <- average.path.length(er)
  er_lcc = c(er_lcc, lcc)
  er_avpl = c(er_avpl,avpl)
}
plot(x = seq(from = 0, to =  1, by =0.01), y = er_lcc/vcount(er), xlab = "p", ylab = "LCC")

library(dplyr)
library(ggplot2)
tibble(p = seq(from = 0, to =  1, by =0.01), avpl = er_avpl) %>%
  ggplot(aes(x = p, y = avpl)) + geom_point() + 
  labs(x = "p",y = "Av. path length") +
  theme_classic()

sw <- sample_smallworld(dim=1,size=20,nei=4,p=0.05)
plot(sw, vertex.size=6, vertex.label=NA, layout=layout_in_circle, loops = F, multiple = F)
















