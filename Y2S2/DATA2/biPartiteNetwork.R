library(igraph)
# extract the bipartite network on liks or comments
setwd("~/ACSAI-Notes/Y2S2/DATA2")
load("datasets/PIXAR/likes_disneypixar.rdata")

edges <- data.frame("user" = likes$from_id, "post" = likes$post_id, stringsAsFactors = F)

g <- graph_from_data_frame(edges, directed = F)
V(g)$type <- V(g)$name %in% edges[,2 ]
table(V(g)$type)
