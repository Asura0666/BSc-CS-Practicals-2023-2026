install.packages("readxl")
install.packages("jsonlite")

library(readxl)
library(jsonlite)

library(dplyr)
library(tidyr)

data_csv <- read.csv("C:\\Users\\ASUS\\Downloads\\diabetes.csv")

data_excel <- read_excel("C:\\Users\\ASUS\\Downloads\\diabetes.xlsx", sheet = 1)

data_json <- fromJSON("C:\\Users\\ASUS\\Downloads\\pokemon.json")

my_data <- data.frame(
  ID = 1:5,
  Name = c("A", "B", "C", "D", "E"),
  Age = c(21,NA,25,22,20),
  City = c("AAA", "BBB", "CCC", "BBB", NA),
  Score = c(85.6, 92.8, 75.2, 56.1, 165.5)
)

head(my_data)

str(my_data)

colSums(is.na(my_data))

mean_age <- mean(my_data$Age, na.rm = TRUE)
my_data_imputed <- my_data %>% 
  mutate(Age = replace_na(Age, mean_age))

my_data_cleaned <- my_data_imputed %>%
  filter(!is.na(City))

Q1 <- quantile(my_data_cleaned$Score, 0.25)
Q3 <- quantile(my_data_cleaned$Score, 0.75)

IQR_val <- Q3 - Q1
upper_bound <- Q3 + 1.5 * IQR_val
lower_bound <- Q1 - 1.5 * IQR_val

my_data_capped <- my_data_cleaned %>% 
  mutate(Score_capped = case_when(
    Score > upper_bound ~ upper_bound,
    Score < lower_bound ~ lower_bound,
    TRUE ~ Score
  )
)

ccc_data <- my_data_capped %>%
  filter(City == "CCC")
print(ccc_data)

sorted_data <- my_data_capped %>% 
  arrange(Age, desc(Score_capped))
print(sorted_data)

grouped_data <- my_data_capped %>% 
  group_by(City) %>%
  summarise(
    Avg_Score = mean(Score_capped),
    Total_Count = n()
  ) %>%
  ungroup()
print(grouped_data)

grouped_data_transform <- grouped_data %>%
  mutate(
    Performance_Category = case_when(
      Avg_Score > 80 ~ "High",
      Avg_Score >= 70 ~ "Medium",
      TRUE ~ "LOW"
    )
  )
print(grouped_data_transform)

