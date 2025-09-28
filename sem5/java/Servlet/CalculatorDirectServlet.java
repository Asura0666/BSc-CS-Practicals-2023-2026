import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/calcdirect"})
public class CalculatorDirectServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<h1>Calculator</h1>");

        double num1 = 15.5;   // first input directly in code
        double num2 = 4.5;    // second input directly in code
        String operation = "add";  // operation directly in code
        
        double result = 0;
        String operatorSymbol = "";
        
        switch(operation) {
            case "add":
                result = num1 + num2;
                operatorSymbol = "+";
                break;
            case "subtract":
                result = num1 - num2;
                operatorSymbol = "-";
                break;
            case "multiply":
                result = num1 * num2;
                operatorSymbol = "*";
                break;
            case "divide":
                if(num2 != 0) {
                    result = num1 / num2;
                    operatorSymbol = "/";
                } else {
                    out.println("<p>Error: Cannot divide by zero!</p>");
                    return;
                }
                break;
            default:
                out.println("<p>Error: Invalid operation!</p>");
                return;
        }
            
        out.println("<p>" + num1 + " " + operatorSymbol + " " + num2 + " = " + result + "</p>");
    }
}