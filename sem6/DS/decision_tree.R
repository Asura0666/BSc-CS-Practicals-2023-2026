library(rpart)
library(rpart.plot)
library(caret)
library(dplyr)

survey_data <- read.csv("C:\\Users\\ASUS\\Downloads\\DS_Dataset.csv")

survey_data$Gender = as.factor(survey_data$Gender)

median_value <- median(survey_data$Washroom_Cleanliness)

survey_data$Washroom_Level <- ifelse(survey_data$Washroom_Cleanliness > median_value, "High", "Low")

survey_data$Washroom_Level <- as.factor(survey_data$Washroom_Level)

str(survey_data)

set.seed(120)

train_index <- createDataPartition(survey_data$Washroom_Level, p = 0.8, list = FALSE)

train_data <- survey_data[train_index,]
test_data <- survey_data[-train_index,]

tree_model <- rpart(
  Washroom_Level ~ Gender + Classroom_Cleanliness,
  data = survey_data,
  method = "class",
  control = rpart.control(minsplit = 10, cp = 0.01)
)

summary(tree_model)

rpart.plot(tree_model, box.palette = "auto", nn = TRUE, main = "Decision Tree - Washroom Level")

prediction <- predict(tree_model, test_data, type = "class")
confusionMatrix(prediction, test_data$Washroom_Level)

printcp(tree_model)

optimal_cp <- tree_model$cptable[
  which.min(tree_model$cptable[, "xerror"]),
  "CP"
]

pruned_tree <- prune(tree_model, cp = optimal_cp)

rpart.plot(pruned_tree, 
           box.palette = "auto",
           nn = TRUE,
           main = "Pruned Decision Tree")

control <- trainControl(method = "cv", number = 10)
tuned_tree <- train(
  Washroom_Level ~ Gender + Classroom_Cleanliness,
  data = survey_data,
  method = "rpart",
  trControl = control,
  tuneGrid = expand.grid(cp = seq(0.001, 0.05, 0.005))
)
print(tuned_tree)
