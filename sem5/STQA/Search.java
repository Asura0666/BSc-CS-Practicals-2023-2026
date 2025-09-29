package TYCS;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

public class Search {
	public static void main(String[] args) {
		System.out.println("Launching Chrome...");

		System.setProperty("webdriver.chrome.driver",
				"C:\\Users\\ASUS\\Downloads\\chromedriver-win64 (1)\\chromedriver-win64\\chromedriver.exe");

		WebDriver driver = new ChromeDriver();

		driver.navigate().to("http://google.co.in");

		driver.manage().window().maximize();

		try {
			WebElement element = driver.findElement(By.name("q"));

			element.sendKeys("junit");

			Thread.sleep(5000);

			element.submit();

			Thread.sleep(5000);

		} catch (Exception e) {
			e.printStackTrace();
		}

		driver.close();

	}
}
