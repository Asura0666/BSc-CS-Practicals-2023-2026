<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Even Odd Example</title>
</head>
<body>
    <h1>Even Odd Example</h1>
    <%
        int n = 10;   // fixed number
        if(n % 2 == 0){
            out.print("<p>" + n + " is even</p>");
        } else {
            out.print("<p>" + n + " is odd</p>");
        }
    %>
</body>
</html>