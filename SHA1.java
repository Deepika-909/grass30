import java.security.MessageDigest;
public class SHA1 {
    public static void main(String[] args) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-1");
            System.out.println("Message digest object info:");
            System.out.println("Algorithm = " + md.getAlgorithm());
            System.out.println("Provider  = " + md.getProvider());
            System.out.println("ToString  = " + md.toString());

            String input = "";
            md.update(input.getBytes());
            byte[] output = md.digest();
            System.out.println("\n SHA1(" +input+ ") = " + bytesToHex(output));
            System.out.println("\nSHA1(\"" + input + "\") = " + bytesToHex(output));

            input = "abc";
            md.update(input.getBytes());
            output = md.digest();
            System.out.println("\nSHA1(\"" + input + "\") = " + bytesToHex(output));

            input = "abcdefghijklmnopqrstuvwxyz";
            md.update(input.getBytes());
            output = md.digest();
            System.out.println("\nSHA1(\"" + input + "\") = " + bytesToHex(output));

        } catch (Exception e) {
            System.out.println("Exception: " + e);
        }
    }
    public static String bytesToHex(byte[] b) {
        char[] hexDigit = {
            '0','1','2','3','4','5','6','7',
            '8','9','A','B','C','D','E','F'
        };
        StringBuilder buf = new StringBuilder();
        for (int j = 0; j < b.length; j++) {
            buf.append(hexDigit[(b[j] >> 4) & 0x0F]);
            buf.append(hexDigit[b[j] & 0x0F]);
        }
        return buf.toString();
    }
}