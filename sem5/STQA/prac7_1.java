package TYCS;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

public class prac7_1 {

	public static WebDriver driver;

	public static void main(String[] args) {
		System.setProperty("webdriver.chrome.driver",
				"C:\\Users\\ASUS\\Downloads\\chromedriver-win64 (1)\\chromedriver-win64\\chromedriver.exe");
		driver = new ChromeDriver();
		driver.get("http://myntra.com/");

		try {
			java.util.List<WebElement> links = driver.findElements(By.tagName("a"));
			System.out.println("Total links are" + links.size());
			for (int i = 0; i < links.size(); i = i + 1) {
				System.out.println("Link" + i + "Link Name" + links.get(i).getText());
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		driver.close();
	}

}
