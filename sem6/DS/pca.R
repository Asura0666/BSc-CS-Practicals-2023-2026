install.packages("FactoMineR")
install.packages("factoextra")
install.packages("ggcorrplot")

library(FactoMineR)
library(factoextra)
library(ggcorrplot)

data <- read.csv("C:\\Users\\ASUS\\Downloads\\DS_Dataset.csv")
str(data)

head(data)

numeric_data <- data[, 7:ncol(data)]
str(numeric_data)
head(numeric_data)

colSums(is.na(numeric_data))

scaled_data <- scale(numeric_data)
head(scaled_data)

pca_result <- princomp(scaled_data)
summary(pca_result)

pca_result$loadings[,1:2]

fviz_eig(pca_result, addlabels = TRUE)

fviz_pca_var(pca_result, col.var = "black")

fviz_cos2(pca_result, choice = "var", axes= 1:2)
