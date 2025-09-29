package TYCS;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

public class LoginFacebook {

	public static void main(String[] args) {
		System.out.println("Launching Chrome...");

		System.setProperty("webdriver.chrome.driver",
				"C:\\Users\\ASUS\\Downloads\\chromedriver-win64 (1)\\chromedriver-win64\\chromedriver.exe");

		WebDriver driver = new ChromeDriver();

		driver.navigate().to("http://www.facebook.com");

		driver.manage().window().maximize();

		try {
			WebElement elementEmail = driver.findElement(By.name("email"));
			elementEmail.sendKeys("student.unity@proton.me");

			WebElement elementPass = driver.findElement(By.name("pass"));
			elementPass.sendKeys("Unity@1234");

			Thread.sleep(5000);
			
			WebElement elementSubmit = driver.findElement(By.name("submit"));
			elementSubmit.submit();

			Thread.sleep(5000);
		} catch (Exception e) {
			e.printStackTrace();
		}

		driver.close();

	}

}
