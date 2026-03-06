
public class CaesarCipher {
  public static void main(String args[]) {
      String plainText = "HELLO WORLD";

      int shift = 3;

      StringBuilder cipherText = new StringBuilder();

      for (int i = 0; i < plainText.length(); i++) {
        char ch = plainText.charAt(i);
        if(Character.isLetter(ch)) {
          char base = Character.isLowerCase(ch) ? 'a' : 'A';
          ch = (char) ((ch - base + shift) % 26 +  base);
        }
        cipherText.append(ch);
      }

      System.out.println("Cipher Text: " + cipherText);
  }
}