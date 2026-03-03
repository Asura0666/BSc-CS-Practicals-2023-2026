install.packages("RMySQL")

library(RMySQL)

mysqlconn <- dbConnect(
  MySQL(),
  user = "root",
  password = "root",
  dbname = "TYCS_59",
  host = "127.0.0.1",
  port = 3306
)

dbListTables(mysqlconn)

dbWriteTable(mysqlconn, "mtcars", mtcars[1:10, ], overwrite = TRUE)

dbExecute(mysqlconn, "DROP TABLE mtcars")

dbListTables(mysqlconn)

dbExecute(
  mysqlconn,"CREATE TABLE article (
  srno INT,
  type VARCHAR(100)
  )"
)

dbExecute(mysqlconn, "INSERT INTO article VALUES (1, 'R Language')")
dbExecute(mysqlconn, "INSERT INTO article VALUES (2, 'C Language')")
dbExecute(mysqlconn, "INSERT INTO article VALUES (3, 'Rust Language')")

dbExecute(mysqlconn, "UPDATE article SET srno = 10 WHERE type = 'R Language'")

res <- dbGetQuery(mysqlconn, "SELECT * FROM article")
print(res)

dbDisconnect(mysqlconn)

