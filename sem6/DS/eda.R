

diabet <- read.csv("C:\\Users\\ASUS\\Downloads\\diabetes.csv")

head(diabet)

str(diabet)

summary(diabet)

diabet[1:10,]

diabet[1:10,1:2]

newdata1 <- subset(diabet, diabet$Outcome == "1")
newdata1

newdata2 <- subset(diabet, diabet$Pregnancies=="1" & diabet$Outcome == "0")
newdata2

newdata3 <- subset(diabet, diabet$Pregnancies == "1" | diabet$Outcome == "0", select = c(1,2))
newdata3

newdata4 <- diabet[order(diabet$BMI),]
newdata4

newdata5 <- diabet[order(-diabet$BMI),]
newdata5

newdata6 <- aggregate(BMI ~ Outcome, data = diabet, FUN = mean)
newdata6

colSums(is.na(diabet))

mean(diabet$BMI)
median(diabet$BMI)
max(diabet$BMI)
min(diabet$BMI)

hist(diabet$BMI)

boxplot(diabet$BMI)

boxplot(diabet$BloodPressure)

