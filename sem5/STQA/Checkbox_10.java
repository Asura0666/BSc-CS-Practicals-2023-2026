package TYCS;

import java.util.List;
import java.util.concurrent.TimeUnit;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

public class Checkbox_10 {
	public static void main(String[] args) {
		System.setProperty("webdriver.chrome.driver",
				"C:\\Users\\ASUS\\Downloads\\chromedriver-win64 (1)\\chromedriver-win64\\chromedriver.exe");

		WebDriver driver = new ChromeDriver();
		driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
		driver.get("https://www.techlistic.com/p/selenium-practice-form.html");

		try {
			List<WebElement> rdBtn_Gender = driver.findElements(By.id("sex-0"));
			boolean bValue = rdBtn_Gender.get(0).isSelected();

			if (bValue) {
				rdBtn_Gender.get(1).click();
			} else {
				rdBtn_Gender.get(0).click();
			}

			List<WebElement> chkBx_Profession = driver.findElements(By.name("profession"));
			int iSize = chkBx_Profession.size();
			System.out.println("Checkbox Size: " + iSize);

			for (int i = 0; i < iSize; i++) {
				String sValue = chkBx_Profession.get(i).getAttribute("value");
				System.out.println("Checkbox Value: " + sValue);
				if (sValue.equalsIgnoreCase("Manual Tester")) {
					chkBx_Profession.get(i).click();
					break;
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		System.out.println("Successfull");
		driver.quit();
	}
}
