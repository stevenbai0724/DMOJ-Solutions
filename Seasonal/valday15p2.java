//https://dmoj.ca/problem/valday15p2
import java.util.*;
import java.io.*;
public class simonAndMarcy {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        int c = readInt();
        int m = readInt();
        int[]princesses = new int[c+1];
        int[]songs = new int[c+1];
        int[][]dp = new int[2][m+1];

        for(int i = 1; i<= c; i++){
            princesses[i] = readInt();
            songs[i] = readInt();
        }

        for(int i = 1; i<=c; i++){
            for(int j = 1; j<=m; j++){
                dp[1][j] = Math.max(dp[0][j], dp[1][j-1]);
                if(j>=songs[i]){
                    dp[1][j] = Math.max(dp[1][j], princesses[i]+dp[0][j-songs[i]]);
                }
            }
            for(int j = 1; j<=m ;j++){
                dp[0][j] = dp[1][j];
            }
        }

        System.out.println(dp[0][m]);

    
    }
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readChar () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}
