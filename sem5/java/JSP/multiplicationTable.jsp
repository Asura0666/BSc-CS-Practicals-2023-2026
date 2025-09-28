<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Multiplication Table</title>
</head>
<body>
    <h1>Multiplication Table</h1>
    <%
        int n = 5;   // fixed number
        for(int i=1; i<=10; i++){
            out.print("<p>" + n + " * " + i + " = " + (n * i) + "</p>");
        }
    %>
</body>
</html>