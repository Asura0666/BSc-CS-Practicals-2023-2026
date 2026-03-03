install.packages("factoextra")
install.packages("cluster")

library(factoextra)
library(cluster)

data <- read.csv("C:\\Users\\ASUS\\Downloads\\DS_Dataset.csv")
str(data)
head(data)

numeric_data <- data[, 7:ncol(data)]
str(numeric_data)
head(numeric_data)

scaled_data <- scale(numeric_data)
head(scaled_data)

fviz_nbclust(scaled_data, kmeans, method = "wss")

set.seed(120)

kmeans.re <- kmeans(scaled_data, centers = 2, nstart = 20)
kmeans.re

cluster_table <- data.frame(
  Name = data$Name,
  Cluster = kmeans.re$cluster
)

cluster_table

table(data$Gender, kmeans.re$cluster)

fviz_cluster(kmeans.re, data = scaled_data, main = "K-mean clusters on cleanliness Data")
