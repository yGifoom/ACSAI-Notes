library(igraph) 
setwd("~/ACSAI-Notes/Y2S2/DATA2")
nodes <- read.csv("datasets/LEZ_16_Dataset/LEZ_16_Dataset/Dataset1-Media-Example-NODES.csv", header=T, as.is=T)
links <- read.csv("datasets/LEZ_16_Dataset/LEZ_16_Dataset/Dataset1-Media-Example-EDGES.csv", header=T, as.is=T)
net <- graph_from_data_frame(d=links, vertices=nodes, directed=T) 
edge_density(net, loops=F)

head(net)

vcol <- rep("gold", vcount(net))
vcol[4] <- "azure"

plot(net, vertex.color = vcol, edge.arrow.mode=0)

ceb <- cluster_edge_betweenness(net)
cfg <- cluster_fast_greedy(as.undirected(net))
dendPlot(ceb, mode="hclust")

modularity(ceb)
modularity(cfg)

deg <- degree(net, mode="all")
plot(ceb, net, vertex.size=deg*3)

plot(cfg, net)
ceb$membership
plot(ceb, net)

# the compare index tells you how self evident those communities are
# Rule of Thumb: memberships are somewhat reliable when they are:
# >.8 over 3 algorithms
compare(ceb, cfg, method="rand")


# sometimes you have to give up on community detection


 