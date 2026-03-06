public class MonoAlphabeticCipher {
  public static void main(String[] args) {
    String alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    String key = "QWERTYUIOPASDFGHJKLZXCVBNM";

    String plainText = "ATTACK";

    StringBuilder cipherText = new StringBuilder();

    for (int i = 0; i < plainText.length(); i++) {
      char ch = plainText.charAt(i);

      int index = alphabets.indexOf(ch);

      if (index != -1) {
        ch = key.charAt(index);

        cipherText.append(ch);
      } else {
        cipherText.append(ch);
      }
    }

    System.out.println("Cipher text: " + cipherText);
  }
}
