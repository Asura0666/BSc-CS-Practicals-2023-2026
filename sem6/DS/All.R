
# Practical 1 -> Data Pre-Processing

library(dplyr)
library(tidyr)


my_data <- data.frame(
  Id = 1:5,
  Name = c("A", "B", "C", "D", "E"),
  Age = c(21, 23, NA, 24, 25),
  Score = c(88.7, 75.6, 96.4, 112.3, 91.5),
  City = c("AAA", "BBB", "BBB", "CCC", NA)
)

head(my_data)

str(my_data)

colSums(is.na(my_data))

mean_age <- mean(my_data$Age)
my_data_imputed <- my_data %>% 
  mutate(Age = replace_na(Age, mean_age))
print(my_data_imputed)


my_data_cleaned <- my_data_imputed %>%
  filter(!is.na(City))
print(my_data_cleaned)


Q1 <- quantile(my_data_cleaned$Score, 0.25)
Q3 <- quantile(my_data_cleaned$Score, 0.75)

IQR_val <- Q3 - Q1
upper_bound <- Q3 + 1.5 * IQR_val
lower_bound <- Q1 - 1.5 * IQR_val

my_data_capped <- my_data_cleaned %>% 
  mutate(
    Score_capped = case_when(
      Score > upper_bound ~ upper_bound,
      Score < lower_bound ~ lower_bound,
      TRUE ~ Score
    )
  )
print(my_data_capped)

bbb_data <- my_data_capped %>% 
  filter(City == "BBB")
print(bbb_data)

sorted_data <- my_data_capped %>% 
  arrange(Age, desc(Score_capped))
print(sorted_data)

grouped_data <- my_data_capped %>%
  group_by(City) %>%
  summarise(
    Avg_Score = mean(Score_capped),
    Total_count = n()
  ) %>%
  ungroup()

print(grouped_data)

transform_grouped_data <- grouped_data %>%
  mutate(
    Perfromance_Score = case_when(
      Avg_Score > 100 ~ "High",
      Avg_Score < 100 ~ "Low",
      TRUE ~ "Low"
    )
  )
print(transform_grouped_data)

# Practical -> EDA

diabet <- read.csv("C:\\Users\\ASUS\\Downloads\\diabetes.csv")

head(diabet)

str(diabet)

colSums(is.na(diabet))

newdata1 <- subset(diabet,diabet$Pregnancies == "1")
newdata1

newdata2 <- subset(diabet, diabet$Pregnancies == "1" & diabet$Outcome == "0")
newdata2

newdata3 <- subset(diabet, diabet$Pregnancies == "1" | diabet$Outcome == "0")
newdata3

newdata4 <- diabet[order(diabet$BMI),]
newdata4

newdata5 <- diabet[order(-diabet$BMI),]
newdata5

newdata6 <- aggregate(Outcome ~ BMI, data = diabet, FUN = mean)
newdata6

mean(diabet$BMI)
median(diabet$BMI)
max(diabet$BMI)
min(diabet$BMI)

hist(diabet$BMI)

boxplot(diabet$BMI)
boxplot(diabet$BloodPressure)


# Practical -> Hypothesis Testing and ANOVA

library(AICcmodavg)
library(dplyr)
library(tidyr)
library(ggplot2)

survey_data <- read.csv("C:\\Users\\ASUS\\Downloads\\59_Dhiraj_DS - Copy.csv")
head(survey_data)
str(survey_data)

colSums(is.na(survey_data))

t.test(survey_data$Classroom_Cleanliness, mu = 3)

t.test(survey_data$Washroom_Cleanlines, survey_data$Classroom_Cleanliness, paired = TRUE)

survey_data$Gender <- as.factor(survey_data$Gender)
anova_oneway <- aov(Classroom_Cleanliness ~ Gender, data = survey_data)
summary(anova_oneway)

median_value <- median(survey_data$Classroom_Cleanliness)
survey_data$Rating_level <- ifelse(survey_data$Classroom_Cleanliness <= median_value, "Low", "High") 
survey_data$Rating_level <- as.factor(survey_data$Rating_level)  

anova_twoway <- aov(Classroom_Cleanliness ~ Gender + Rating_level, data = survey_data)  
summary(anova_twoway)  

model.set = list(anova_oneway, anova_twoway)
model.names = c("One way ANOVA", "Two way ANOVA")  
aictab(model.set, modnames = model.names)  

ggplot(survey_data, aes(x = Gender, y = Washroom_Cleanliness, fill = Gender)) +
  geom_boxplot(alpha = 0.7) +
  labs(
    title = "One way ANOVA",
    subtitle = "Gender X Classroom cleanliness",
    x = "Gender",
    y = "classroom cleanliness"
  ) +
  theme_minimal()

ggplot(survey_data, aes(x = Gender, y = Washroom_Cleanliness
                        , fill = Rating_level)) +
  geom_boxplot(position = position_dodge(width = 0.7)) +
  labs(
    title = "Two way ANOVA",
    subtitle = "Interaction: Gender X classroom cleanliness",
    x = "Gender",
    y = "classroom cleanliness"
  ) +
  theme_minimal()

# Practical -> Principle Component Analysis

library(FactoMineR)
library(factoextra)
library(ggcorrplot)

survey_data <- read.csv("C:\\Users\\ASUS\\Downloads\\59_Dhiraj_DS - Copy.csv")
str(survey_data)
head(survey_data)

colSums(is.na(survey_data))

numeric_data <- survey_data[,7:ncol(survey_data)]
head(numeric_data)

scaled_data <- scale(numeric_data)
head(scaled_data)

pca_result <- princomp(scaled_data)
summary(pca_result)

pca_result$loadings[,1:2]

fviz_eig(pca_result, addlabels = TRUE)
fviz_pca_var(pca_result, col.var = "black")

fviz_cos2(pca_result, choice = "var", axes = 1:2)


# Pracical -> K mean clustering

library(dplyr)
library(factoextra)
library(cluster)

survey_data <- read.csv("C:\\Users\\ASUS\\Downloads\\59_Dhiraj_DS - Copy.csv")
str(survey_data)
head(survey_data)

colSums(is.na(survey_data))

numeric_data <- survey_data[, 7:ncol(survey_data)]
head(numeric_data)

scaled_data <- scale(numeric_data)

fviz_nbclust(scaled_data, kmeans, method = "wss")

kmeans.re <- kmeans(scaled_data, centers = 2, nstart = 20)
kmeans.re


cluster_table <- data.frame(
  Name = survey_data$Name,
  cluster = kmeans.re$cluster
)
print(cluster_table)

table(survey_data$Gender, kmeans.re$cluster)

fviz_cluster(kmeans.re, data = scaled_data, main = "K-mean cluster on cleanliness survey")


# Practical -> LOgistic Regression
library(tidyverse)
library(caret)


survey_data <- read.csv("C:\\Users\\ASUS\\Downloads\\59_Dhiraj_DS - Copy.csv")
str(survey_data)
head(survey_data)

colSums(is.na(survey_data))

median_value <- median(survey_data$Washroom_Cleanliness, na.rm = TRUE)
survey_data$Washroom_level = ifelse(survey_data$Washroom_Cleanliness > median_value, 1, 0)
survey_data$Washroom_level = as.factor(survey_data$Washroom_level)

survey_data$Gender = as.factor(survey_data$Gender)

log_model = glm(
  Washroom_level ~ Gender + Classroom_Cleanliness,
  data = survey_data,
  family = binomial
)
summary(log_model)

exp(coef(log_model))

probabilities <- predict(log_model, type = "response")
prediction_class <- ifelse(probabilities > 0.5, 1, 0)
prediction_class <- as.factor(prediction_class)

table(Prediction = prediction_class,
      Actual = survey_data$Washroom_level)

confusionMatrix(prediction_class, survey_data$Washroom_level)

# Practical -> Random Forest

library(randomForest)
library(caret)

data(iris)
head(iris)

colSums(is.na(iris))

trainIndex <- sample(1:nrow(iris), 0.8 * nrow(iris))
trainData <- iris[trainIndex,]
testData <- iris[-trainIndex,]

rf_model <- randomForest(Species ~ ., data = trainData)
print(rf_model)

prediction <- predict(rf_model, testData)
confusionMatrix(prediction, testData$Species)

importance(rf_model)
varImpPlot(rf_model)

rf_tuned = randomForest(Species ~ ., data = trainData, ntree = 500, mtry=2)
print(rf_tuned)

# Pra"iris"# Practical -> Decision Tree






















