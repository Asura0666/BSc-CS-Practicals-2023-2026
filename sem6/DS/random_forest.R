# ===============================
# PRACTICAL: RANDOM FOREST
# ===============================

# 1. Install & Load Libraries
install.packages("randomForest")
install.packages("caret")
install.packages("ggplot2")

library(randomForest)
library(caret)
library(ggplot2)
library(dplyr)

survey_data <- read.csv("C:\\Users\\ASUS\\Downloads\\DS_Dataset.csv")


# ===============================
# 2. Data Preparation
# ===============================

# Convert Gender to factor
survey_data$Gender <- as.factor(survey_data$Gender)

# Create binary target variable (High / Low)
median_value <- median(survey_data$Washroom_Cleanliness)

survey_data$Washroom_Level <- ifelse(
  survey_data$Washroom_Cleanliness > median_value,
  "High",
  "Low"
)

survey_data$Washroom_Level <- as.factor(survey_data$Washroom_Level)

# ===============================
# 3. Train-Test Split (80-20)
# ===============================

set.seed(120)

trainIndex <- createDataPartition(
  survey_data$Washroom_Level,
  p = 0.8,
  list = FALSE
)

trainData <- survey_data[trainIndex, ]
testData  <- survey_data[-trainIndex, ]

# ===============================
# 4. Build Random Forest Model
# ===============================

rf_model <- randomForest(
  Washroom_Level ~ Gender + Classroom_Cleanliness,
  data = trainData,
  ntree = 100,
  importance = TRUE
)

print(rf_model)

# ===============================
# 5. Prediction & Evaluation
# ===============================

predictions <- predict(rf_model, testData)

conf_matrix <- confusionMatrix(predictions, testData$Washroom_Level)
print(conf_matrix)

# ===============================
# 6. Tune Model (More Trees)
# ===============================

rf_tuned <- randomForest(
  Washroom_Level ~ Gender + Classroom_Cleanliness,
  data = trainData,
  ntree = 500,
  mtry = 2,
  importance = TRUE
)

print(rf_tuned)

# ===============================
# 7. Variable Importance
# ===============================

importance_values <- importance(rf_model)
print(importance_values)

varImpPlot(rf_model)

# ===============================
# 8. Clean Importance Plot (ggplot)
# ===============================

importance_df <- as.data.frame(importance(rf_model))
importance_df$Variable <- rownames(importance_df)

ggplot(importance_df,
       aes(x = reorder(Variable, MeanDecreaseGini),
           y = MeanDecreaseGini)) +
  geom_col(fill = "steelblue") +
  coord_flip() +
  labs(title = "Variable Importance (Random Forest)",
       x = "Predictor",
       y = "Mean Decrease Gini") +
  theme_minimal()

# ===============================
# END OF PRACTICAL
# ===============================

library(randomForest)
library(caret)

data(iris)
head(iris)
set.seed(120)

trainIndex <- sample(1:nrow(iris), 0.8 * nrow(iris))
trainData <- iris[trainIndex, ]
testData <- iris[-trainIndex, ]

rf_model <- randomForest(Species ~ ., data = trainData)
print(rf_model)

predictions <- predict(rf_model, testData)
confusionMatrix(predictions, testData$Species)

rf_tuned <- randomForest(Species ~ ., data = trainData, ntree = 500, mtry = 2)
print(rf_tuned)

importance(rf_model)
varImpPlot(rf_model)
