install.packages("tidyverse")

library(tidyverse)

survey_data <- survey_data <- read.csv("C:\\Users\\ASUS\\Downloads\\59_Dhiraj_DS - Copy.csv")
head(survey_data)
str(survey_data)

colSums(is.na(survey_data))

median_value <- median(survey_data$Washroom_Cleanliness, na.rm = TRUE)
survey_data$Washroom_level <- ifelse(survey_data$Washroom_Cleanliness > median_value, 1, 0)
survey_data$Washroom_level <- as.factor(survey_data$Washroom_level)

survey_data$Gender <- as.factor(survey_data$Gender)

log_model <- glm(
  Washroom_level ~ Gender + Classroom_Cleanliness, 
  data = survey_data, 
  family = binomial
)
summary(log_model)

exp(coef(log_model))

probabilities <- predict(log_model, type = "response")
predicted_class <- ifelse(probabilities > 0.5, 1, 0)
predicted_class <- as.factor(predicted_class)

table(predicted = predicted_class,
      actual = survey_data$Washroom_level)


