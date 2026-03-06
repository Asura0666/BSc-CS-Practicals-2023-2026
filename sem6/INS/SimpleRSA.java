import javax.crypto.Cipher;

import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PublicKey;
import java.security.PrivateKey;
import java.util.Base64;

public class SimpleRSA {
  public static void main(String[] args) throws Exception {
    String plainText = "This is secret message";

    KeyPairGenerator keyGen = KeyPairGenerator.getInstance("RSA");
    KeyPair keyPair = keyGen.generateKeyPair();
    PublicKey pubKey = keyPair.getPublic();
    PrivateKey priKey = keyPair.getPrivate();

    Cipher rsaCipher = Cipher.getInstance("RSA");

    rsaCipher.init(Cipher.ENCRYPT_MODE, pubKey);

    byte[] cipherTextBytes = rsaCipher.doFinal(plainText.getBytes());
    String cipherText = Base64.getEncoder().encodeToString(cipherTextBytes);

    System.out.println("Plain text: " + plainText);
    System.out.println("Encrypted text: " + cipherText);

    rsaCipher.init(Cipher.DECRYPT_MODE, priKey);

    byte[] bytesToDecrypt = Base64.getDecoder().decode(cipherText);
    byte[] decryptedBytes = rsaCipher.doFinal(bytesToDecrypt);

    System.out.println("Decrypted text: " + new String(decryptedBytes));
  }
}