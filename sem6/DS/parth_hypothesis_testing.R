# ====================================================
# Hypothesis Testing & ANOVA on Student Dataset
# ====================================================

# 1. Load the dataset
#    Assuming you have saved the file as "58_parth_ds.csv" in your working directory.
#    If not, adjust the file path accordingly.

df <- read.csv("58_parth_ds.csv")

# 2. Inspect the data
str(df)
head(df)
summary(df)

# 3. Convert categorical variables to factors
df$Gender <- as.factor(df$Gender)
df$Part_Time_Job <- as.factor(df$Part_Time_Job)
df$Health_Issues <- as.factor(df$Health_Issues)
df$Participation_in_Activities <- as.factor(df$Participation_in_Activities)
df$Year <- as.factor(df$Year)
df$Department <- as.factor(df$Department)

# 4. Independent t-tests

# 4.1 t-test: CGPA by Gender
#     Null hypothesis: mean CGPA of males equals mean CGPA of females
t_test_gender <- t.test(CGPA ~ Gender, data = df, var.equal = FALSE)  # Welch's t-test
print(t_test_gender)

# 4.2 t-test: CGPA by Part-Time Job status
t_test_job <- t.test(CGPA ~ Part_Time_Job, data = df)
print(t_test_job)

# 5. One-way ANOVA

# 5.1 ANOVA: CGPA by Year
#     Null hypothesis: mean CGPA is the same across all years
aov_year <- aov(CGPA ~ Year, data = df)
summary(aov_year)

# If significant, perform post-hoc test (Tukey HSD)
# TukeyHSD(aov_year)

# 5.2 ANOVA: CGPA by Department (CS vs IT – only two groups, equivalent to t-test)
aov_dept <- aov(CGPA ~ Department, data = df)
summary(aov_dept)

# 6. Two-way ANOVA with interaction: CGPA ~ Department * Gender
#     Tests main effects of Department and Gender, and their interaction
aov_two_way <- aov(CGPA ~ Department * Gender, data = df)
summary(aov_two_way)

# 7. Chi-square test of independence
#     Example: Association between Part-Time Job and Health Issues
#     Null hypothesis: no association between the two variables
table_job_health <- table(df$Part_Time_Job, df$Health_Issues)
print(table_job_health)
chisq_test <- chisq.test(table_job_health)
print(chisq_test)

# 8. Checking assumptions (optional, for ANOVA)

# 8.1 Normality of residuals (for one-way ANOVA by Year)
residuals_year <- residuals(aov_year)
shapiro.test(residuals_year)   # p > 0.05 indicates normality
# Q-Q plot
qqnorm(residuals_year); qqline(residuals_year, col = "red")

# 8.2 Homogeneity of variances (Levene's test)
library(car)   # if not installed: install.packages("car")
leveneTest(CGPA ~ Year, data = df)   # p > 0.05 indicates equal variances

# 9. (Optional) Non-parametric alternatives if assumptions violated
#     Kruskal-Wallis test instead of one-way ANOVA
# kruskal.test(CGPA ~ Year, data = df)
#     Wilcoxon rank-sum test instead of t-test
# wilcox.test(CGPA ~ Gender, data = df)

# ====================================================
# End of script