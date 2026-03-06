public class VermanCipher {
  public static void main(String[] args) {
    String plaintext = "HELLO";
    String key = "MONEY";

    StringBuilder cipherText = new StringBuilder();

    for (int i = 0; i < plaintext.length(); i++) {
      int pNum = plaintext.charAt(i) - 'A';

      int kNum = key.charAt(i) - 'A';

      int cNum = (pNum + kNum) % 26;

      char ch = (char) (cNum + 'A');

      cipherText.append(ch);
    }

    System.out.println("Cipher text: " + cipherText);
  }
}
