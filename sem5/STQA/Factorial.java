package TYCS;

public class Factorial {

	public int fact(int n) {
		if (n < 0) {
			throw new IllegalArgumentException("factorial is not defined for negative numbers");
		}

		int fact = 1;
		for (int i = 2; i <= n; i++) {
			fact *= i;
		}

		return fact;

	}

}
