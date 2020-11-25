//https://dmoj.ca/problem/dmopc14c3p6
import java.util.*;
import java.io.*;
public class notEnoughTime {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        
        int n = readInt();
        int t = readInt();
        int[][]dp = new int[2][t+1];
        int[][] prepare = new int[n+1][4];
        int[][] value = new int[n+1][4];

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=3; j++){
                prepare[i][j] = readInt();
                value[i][j] = readInt();
            }
        }
        for(int i = 1; i<=n; i++){
            for(int l = 1; l<=3; l++){
                for(int j = 1; j<=t; j++){
                    dp[1][j] = Math.max(Math.max(dp[0][j], dp[1][j-1]), dp[1][j]); 
                    if(j>=prepare[i][l]) 
                        dp[1][j] = Math.max(dp[1][j], value[i][l]+ dp[0][j-prepare[i][l]]);
                }

            }
            for(int j = 1; j<=t; j++){
                dp[0][j] = dp[1][j];
            }
        }

        System.out.println(dp[0][t]);    
        
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