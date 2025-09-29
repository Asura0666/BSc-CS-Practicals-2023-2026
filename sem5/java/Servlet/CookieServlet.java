// SetCookieServlet.java
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/setcookie")
public class SetCookieServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        // Hardcoded username
        String username = "JohnDoe";

        // Create cookie
        Cookie userCookie = new Cookie("username", username);
        userCookie.setMaxAge(60 * 60 * 24 * 7); // 7 days
        response.addCookie(userCookie);

        response.setContentType("text/html");
        response.getWriter().println("<html><body>");
        response.getWriter().println("<h2>Cookie has been set for user: " + username + " for 7 days.</h2>");
        response.getWriter().println("<a href='readcookie'>Read Cookie</a>");
        response.getWriter().println("</body></html>");
    }
}


// ReadCookieServlet.java
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;

@WebServlet("/readcookie")
public class ReadCookieServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        response.setContentType("text/html");
        response.getWriter().println("<html><body>");
        response.getWriter().println("<h2>Reading Cookies</h2>");

        Cookie[] cookies = request.getCookies();
        boolean found = false;

        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if ("username".equals(cookie.getName())) {
                    response.getWriter().println("<p>Username: " + cookie.getValue() + "</p>");
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            response.getWriter().println("<p>No username cookie found.</p>");
        }

        response.getWriter().println("</body></html>");
    }
}
