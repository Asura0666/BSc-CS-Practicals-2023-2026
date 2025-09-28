<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Prime Numbers Example</title>
</head>
<body>
    <h1>Prime Numbers</h1>

    <%
        // Fixed numbers (no user input)
        int m = 1;   // starting number
        int n = 10;   // ending number

        if (m > n) {
            out.println("<h2 style='color:red;'>Error: First number should be smaller than second number.</h2>");
        } else {
            out.println("<h3>Prime numbers between " + m + " and " + n + ":</h3>");
            for (int i = m; i <= n; i++) {
                int flag = 0;
                for (int j = 2; j < i; j++) {
                    if (i % j == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (i > 1 && flag == 0) {
                    out.print(i + " ");
                }
            }
        }
    %>
</body>
</html>