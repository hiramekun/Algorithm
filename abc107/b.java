package abc107;

import java.util.Scanner;

class b {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        
        boolean[] is_remove_h = new boolean[W];
        boolean[] is_remove_w = new boolean[H];
        String[] as = new String[H];
        
        scanner.nextLine();
        for (int i = 0; i < H; i++) {
            as[i] = scanner.nextLine();
        }
        for (int i = 0; i < H; i++) {
            int count = 0;
            for (int j = 0; j < W; j++) {
                if (as[i].charAt(j) == '.') {
                    count++;
                }
            }
            if (count == W) is_remove_w[i] = true;
        }

        for (int i = 0; i < W; i++) {
            int count = 0;
            for (int j = 0; j < H; j++) {
                if (as[j].charAt(i) == '.') {
                    count++;
                }
            }
            if (count == H) is_remove_h[i] = true;
        }

        for (int i = 0; i < H; i++) {
            if (is_remove_w[i]) continue;
            for (int j = 0; j < W; j++) {
                if (is_remove_h[j]) continue;
                System.out.print(as[i].charAt(j));
            }
            System.out.println();
        }
    }
}
