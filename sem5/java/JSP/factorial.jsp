<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Factorial Example</title>
</head>
<body>
    <h1>Factorial Example</h1>
    <%
        int n = 5;   // fixed number
        int fact = 1;
        for(int i=1; i<=n; i++){
            fact = fact * i;
        }
        out.print("<p>Factorial of " + n + " is " + fact + "</p>");
    %>
</body>
</html>