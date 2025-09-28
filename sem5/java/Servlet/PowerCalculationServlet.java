import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/powerdirect"})
public class PowerCalculationServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<h1>Power Calculation</h1>");

        int m = 2;   // base input directly in code
        int n = 5;   // exponent input directly in code
        int power = 1;
        
        for(int i = 1; i <= n; i++)
            power *= m;
            
        out.println("<p>" + m + " raised to the power of " + n + " is " + power + "</p>");
    }
}