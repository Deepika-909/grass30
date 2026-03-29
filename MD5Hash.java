import java.security.MessageDigest;
import java.util.Scanner;
public class MD5Hash {
    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter text to hash using MD5: ");
            String input = scanner.nextLine();
            scanner.close();

            MessageDigest md = MessageDigest.getInstance("MD5");

            md.update(input.getBytes());
            byte[] digest = md.digest();

            String hash = bytesToHex(digest);

            System.out.println("MD5 hash of \"" + input + "\" is:");
            System.out.println(hash);

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
    public static String bytesToHex(byte[] bytes) {
        StringBuilder hexString = new StringBuilder();
        for (byte b : bytes) {
            hexString.append(String.format("%02X", b));
        }
        return hexString.toString();
    }
}