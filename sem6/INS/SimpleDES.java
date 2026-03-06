import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class SimpleDES {
  public static void main(String[] args) throws Exception {
    String plainText = "This is a message";

    KeyGenerator keyGen = KeyGenerator.getInstance("DES");
    SecretKey key = keyGen.generateKey();

    Cipher desCipher = Cipher.getInstance("DES");
    
    desCipher.init(Cipher.ENCRYPT_MODE, key);

    byte[] cipherTextBytes = desCipher.doFinal(plainText.getBytes());
    String cipherText = Base64.getEncoder().encodeToString(cipherTextBytes);

    System.out.println("Plain text: " + plainText);
    System.out.println("Encrypted text: " + cipherText);

    desCipher.init(Cipher.DECRYPT_MODE, key);

    byte[] bytesToDecrypt = Base64.getDecoder().decode(cipherText);
    byte[] decryptedBytes = desCipher.doFinal(bytesToDecrypt);

    System.out.println("Decrypted text: " + new String(decryptedBytes));
  }
}
