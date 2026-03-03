# Test whether the average Classroom Cleanliness rating is significantly different from neutral value (3).

# One Sample T-test

survey_data <- read.csv("C:\\Users\\ASUS\\Downloads\\DS_Dataset.csv")
head(survey_data)

t.test(survey_data$Classroom_Cleanliness, mu = 3)

# Paired Sample T-test (classroom vs washroom)

t.test(survey_data$Classroom_Cleanliness, survey_data$Washroom_Cleanliness, paired = TRUE)


install.packages("AICcmodavg")
library(AICcmodavg)
library(ggplot2)
library(dplyr)

survey_data$Gender <- as.factor(survey_data$Gender)
anova_oneway <- aov(Washroom_Cleanliness ~ Gender, data = survey_data)
summary(anova_oneway)

median_value <- median(survey_data$Classroom_Cleanliness)
survey_data$Rating_Level <- ifelse(survey_data$Classroom_Cleanliness <= median_value, "Low", "High")
survey_data$Rating_Level <- as.factor(survey_data$Rating_Level)

anova_twoway = aov(Washroom_Cleanliness ~ Gender * Rating_Level, data = survey_data)
summary(anova_twoway)

model.set <- list(anova_oneway, anova_twoway)
model.names <- c("one-way ANOVA", "two-way ANOVA") 
aictab(model.set, modnames = model.names)

ggplot(survey_data, aes(x = Gender, y = Washroom_Cleanliness, fill = Gender)) +
  geom_boxplot(alpha = 0.7) +
  labs(title = "One way Anova", 
       subtitle = "Washroom cleanliness by Gender",
       x = "Gender",
       y = "Washroom cleanliness rating") +
  theme_minimal() +
  theme(legend.position = "none")

ggplot(survey_data, aes(x = Gender, y = Washroom_Cleanliness, fill = Rating_Level)) +
  geom_boxplot(position = position_dodge(width = 0.8)) +
  labs(title = "Two way Anova",
       subtitle = "Interaction Gender X Rating Level",
       x = "Gender",
       y = "Washroom cleanliness Rating",
       fill = "Rating level") +
  theme_minimal()

