public class ColumnarTranspositionCipher {
  public static void main(String[] args) {
    String plainText = "CRYPTOGRAPHY IS FUN";

    int key = 4;

    plainText = plainText.replace("\\s", "");

    int rows = (int) Math.ceil((double) plainText.length() / key);
    
    char[][] grid = new char[rows][key];

    int index = 0;

    for(int r = 0; r < rows; r++) {
      for(int c = 0; c < key; c++) {
        if(index < plainText.length()) {
          grid[r][c] = plainText.charAt(index++);
        } else {
          grid[r][c] = 'X';
        }
      }
    }

    String cipherText = "";

    for(int c = 0; c  < key; c++) {
      for(int r = 0; r < rows; r++) {
        cipherText += grid[r][c];
      }
    }

    System.out.println("Cipher text: " + cipherText);


  }
}
