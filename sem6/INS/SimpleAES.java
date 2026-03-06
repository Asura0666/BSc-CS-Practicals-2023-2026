import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class SimpleAES {
  public static void main(String[] args) throws Exception {
    String plainText = "This is a message";

    KeyGenerator keyGen = KeyGenerator.getInstance("AES");
    keyGen.init(128);
    SecretKey key = keyGen.generateKey();

    Cipher aesCipher = Cipher.getInstance("AES");

    aesCipher.init(Cipher.ENCRYPT_MODE, key);
    byte[] cipherTextBytes = aesCipher.doFinal(plainText.getBytes());
    String cipherText = Base64.getEncoder().encodeToString(cipherTextBytes);

    System.out.println("Plain text: " + plainText);
    System.out.println("Encrypted text: " + cipherText);

    aesCipher.init(Cipher.DECRYPT_MODE, key);
    byte[] bytesToDecrypt = Base64.getDecoder().decode(cipherText);
    byte[] decryptedText = aesCipher.doFinal(bytesToDecrypt);

    System.out.println("Decrypted text: " + new String(decryptedText));

  }
}
