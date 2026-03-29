import java.math.BigInteger;
import java.util.Random;
import java.util.Scanner;
public class RSA {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.print("Enter a prime number: ");
        BigInteger p = sc.nextBigInteger(); 
        System.out.print("Enter another prime number: ");
        BigInteger q = sc.nextBigInteger();
        BigInteger n = p.multiply(q);
        BigInteger phi = (p.subtract(BigInteger.ONE)).multiply(q.subtract(BigInteger.ONE));
        BigInteger e = generateE(phi);
        BigInteger d = e.modInverse(phi);

        System.out.println("Public Key (e, n): (" + e + ", " + n + ")");
        System.out.println("Private Key (d, n): (" + d + ", " + n + ")");
    }
    public static BigInteger generateE(BigInteger phi) {
        Random rand = new Random();
        BigInteger e;
        do {
            e = new BigInteger(phi.bitLength(), rand);
        } while (e.compareTo(BigInteger.ONE) <= 0
                || e.compareTo(phi) >= 0
                || !phi.gcd(e).equals(BigInteger.ONE));
        return e;
    }
}