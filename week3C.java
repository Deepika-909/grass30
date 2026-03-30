import java.util.Scanner;
public class week3C {
    static int[][] messageVector = new int[3][1];
    static int[][] keyMatrix = new int[3][3];
    static int[][] inverseMatrix = new int[3][3];
    static int[][] cipherMatrix = new int[3][1];
    static int[][] resultMatrix = new int[3][1];
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        getKeyMessage();
        multiplyMatrix(keyMatrix, messageVector, cipherMatrix);
        System.out.print("\nEncrypted string is: ");
        for (int i = 0; i < 3; i++) {
            System.out.print((char) ((cipherMatrix[i][0] % 26) + 65));
        }
        inverse();
        multiplyMatrix(inverseMatrix, cipherMatrix, resultMatrix);
        System.out.print("\nDecrypted string is: ");
        for (int i = 0; i < 3; i++) {
            System.out.print((char) ((resultMatrix[i][0] % 26) + 65));
        }
        System.out.println();
    }
    public static void getKeyMessage() {
        System.out.println("Enter 3x3 matrix for key (invertible mod 26):");
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                keyMatrix[i][j] = sc.nextInt();

        System.out.print("\nEnter a 3-letter string: ");
        String msg = sc.next().toUpperCase();

        for (int i = 0; i < 3; i++)
            messageVector[i][0] = msg.charAt(i) - 65;
    }
    public static void multiplyMatrix(int[][] A, int[][] B, int[][] result) {
        for (int i = 0; i < 3; i++) {
            result[i][0] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][0] += A[i][k] * B[k][0];
            }
            result[i][0] = ((result[i][0] % 26) + 26) % 26;
        }
    }
    public static void inverse() {
        int det = determinant(keyMatrix);
        int detInverse = modInverse(det, 26);

        if (detInverse == -1) {
            System.out.println("\nMatrix is not invertible in mod 26!");
            System.exit(0);
        }
        int[][] adj = adjoint(keyMatrix);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                inverseMatrix[i][j] = ((adj[i][j] * detInverse) % 26 + 26) % 26;

        System.out.println("\nInverse matrix is:");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                System.out.print(inverseMatrix[i][j] + " ");
            System.out.println();
        }
    }
    public static int determinant(int[][] m) {
        int det =
                m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) -
                m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
                m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);

        return ((det % 26) + 26) % 26;
    }
    public static int modInverse(int det, int mod) {
        det = (det % mod + mod) % mod;
        for (int x = 1; x < mod; x++) {
            if ((det * x) % mod == 1)
                return x;
        }
        return -1;
    }
    public static int[][] adjoint(int[][] m) {
        int[][] adj = new int[3][3];

        adj[0][0] =  (m[1][1]*m[2][2] - m[1][2]*m[2][1]);
        adj[0][1] = -(m[1][0]*m[2][2] - m[1][2]*m[2][0]);
        adj[0][2] =  (m[1][0]*m[2][1] - m[1][1]*m[2][0]);

        adj[1][0] = -(m[0][1]*m[2][2] - m[0][2]*m[2][1]);
        adj[1][1] =  (m[0][0]*m[2][2] - m[0][2]*m[2][0]);
        adj[1][2] = -(m[0][0]*m[2][1] - m[0][1]*m[2][0]);

        adj[2][0] =  (m[0][1]*m[1][2] - m[0][2]*m[1][1]);
        adj[2][1] = -(m[0][0]*m[1][2] - m[0][2]*m[1][0]);
        adj[2][2] =  (m[0][0]*m[1][1] - m[0][1]*m[1][0]);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                adj[i][j] = ((adj[i][j] % 26) + 26) % 26
        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++) {
                int temp = adj[i][j];
                adj[i][j] = adj[j][i];
                adj[j][i] = temp;
            }
        return adj;
    }
}
        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++) {
                int temp = adj[i][j];
                adj[i][j] = adj[j][i];
                adj[j][i] = temp;
            }
        return adj;
    }
}
