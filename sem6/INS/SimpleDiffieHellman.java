import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PublicKey;
import java.security.PrivateKey;

import javax.crypto.KeyAgreement;
import javax.crypto.interfaces.DHPublicKey;
import javax.crypto.spec.DHParameterSpec;

import java.util.Base64;

public class SimpleDiffieHellman {
	public static void main (String args[]) throws Exception {

		System.out.println("Asura Generating his Keys!!");

		KeyPairGenerator asuraKeyGen = KeyPairGenerator.getInstance("DH");
		asuraKeyGen.initialize(2048);

		KeyPair asuraKeyPair = asuraKeyGen.generateKeyPair();
		PublicKey asuraPublicKey = asuraKeyPair.getPublic();
		PrivateKey asuraPrivateKey = asuraKeyPair.getPrivate();


		System.out.println("Dhiraj Receive parameters from Asura");

		DHParameterSpec dhParamFromAsura = ((DHPublicKey) asuraPublicKey).getParams();
				
		KeyPairGenerator dhirajKeyGen = KeyPairGenerator.getInstance("DH");
		dhirajKeyGen.initialize(dhParamFromAsura);

		KeyPair dhirajKeyPair = dhirajKeyGen.generateKeyPair();
		PublicKey dhirajPublicKey = dhirajKeyPair.getPublic();
		PrivateKey dhirajPrivateKey = dhirajKeyPair.getPrivate();

		System.out.println("Performing Key Agreement...!!");

		KeyAgreement asuraAgree = KeyAgreement.getInstance("DH");
		asuraAgree.init(asuraPrivateKey);
		asuraAgree.doPhase(dhirajPublicKey, true);
		byte[] asuraSharedBytes = asuraAgree.generateSecret();

		KeyAgreement dhirajAgree = KeyAgreement.getInstance("DH");
		dhirajAgree.init(dhirajPrivateKey);
		dhirajAgree.doPhase(asuraPublicKey, true);
		byte[] dhirajSharedBytes = dhirajAgree.generateSecret();	

		System.out.println("Asura shared Secret: " + bytesToString(asuraSharedBytes));
		System.out.println("Dhiraj shared Secret: " + bytesToString(dhirajSharedBytes));

		if(bytesToString(asuraSharedBytes).equals(bytesToString(dhirajSharedBytes))) {
			System.out.println("Success: Both parties share the same secret key");
		}
				
	}

	private static String bytesToString(byte[] bytes) {
		String sharedString = Base64.getEncoder().encodeToString(bytes);

		return sharedString;
	}
}

