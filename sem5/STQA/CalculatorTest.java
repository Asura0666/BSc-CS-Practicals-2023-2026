package TYCS;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class CalculatorTest {

	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testAdd() {
		int a = 10;
		int b = 10;

		int expected = 20;

		Calculator c = new Calculator();

		int actual = c.add(a, b);

		assertEquals(expected, actual);
	}

	@Test
	public void testSub() {
		int a = 10;
		int b = 5;

		int expected = 5;

		Calculator c = new Calculator();

		int actual = c.sub(a, b);

		assertEquals(expected, actual);
	}

	@Test
	public void testMul() {
		int a = 10;
		int b = 5;

		int expected = 50;

		Calculator c = new Calculator();

		int actual = c.mul(a, b);

		assertEquals(expected, actual);
	}

	@Test
	public void testDiv() {
		int a = 10;
		int b = 5;

		int expected = 2;

		Calculator c = new Calculator();

		int actual = c.div(a, b);

		assertEquals(expected, actual);
	}

}
