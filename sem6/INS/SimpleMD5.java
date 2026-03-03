import java.security.MessageDigest;

public class SimpleMD5 {
	public static void main(String args[]) throws Exception {
		String plaintext = "hello world";

		MessageDigest md = MessageDigest.getInstance("MD5");

		byte[] hashBytes = md.digest(plaintext.getBytes());

		System.out.println("Input: " + plaintext);
		System.out.println("MD5 encrypted text: " + bytesToHex(hashBytes));
	}

	private static String bytesToHex(byte[] bytes) {
		StringBuilder hexString = new StringBuilder();

		for (byte b : bytes) {
			String hex = String.format("%02x", b);
			hexString.append(hex);
		}

		return hexString.toString();
	}
}