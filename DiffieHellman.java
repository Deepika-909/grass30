import java.util.Scanner;

public class DiffieHellman {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter prime number (p): ");
        int p = sc.nextInt();
        System.out.print("Enter primitive root (g): ");
        int g = sc.nextInt();
        System.out.print("Enter private key of Alice (a): ");
        int a = sc.nextInt();
        System.out.print("Enter private key of Bob (b): ");
        int b = sc.nextInt();

        int A = (int) Math.pow(g, a) % p;
        int B = (int) Math.pow(g, b) % p;

        System.out.println("Public key of Alice: " + A);
        System.out.println("Public key of Bob: " + B);

        int key1 = (int) Math.pow(B, a) % p;
        int key2 = (int) Math.pow(A, b) % p;

        if (key1 == key2) {
            System.out.println("Keys match! parties can communicate securely.");
            System.out.println("Shared Secret Key: " + key1);
        } else {
            System.out.println("Keys do not match!");
        }

        sc.close();
    }
}