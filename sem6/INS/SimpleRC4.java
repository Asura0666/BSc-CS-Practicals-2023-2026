import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;;

public class SimpleRC4 {
  public static void main(String[] args) throws Exception {
    String plainText = "this is a secret message";

    KeyGenerator keyGen = KeyGenerator.getInstance("RC4");
    keyGen.init(128);
    SecretKey key = keyGen.generateKey();

    Cipher rc4Cipher = Cipher.getInstance("RC4");

    rc4Cipher.init(Cipher.ENCRYPT_MODE, key);
    byte[] cipherTextBytes = rc4Cipher.doFinal(plainText.getBytes());

    System.out.println("Encrypted text: " + byteToHex(cipherTextBytes));

    rc4Cipher.init(Cipher.DECRYPT_MODE, key);
    byte[] decryptBytes = rc4Cipher.doFinal(cipherTextBytes);

    System.out.println("Decrypted text: " + new String(decryptBytes));

  }

  private static String byteToHex(byte[] bytes) {
    StringBuilder hexString = new StringBuilder();
    for (byte b : bytes) {
      String hex = String.format("%02x", b);
      hexString.append(hex);
    }

    return hexString.toString();
  }
}
