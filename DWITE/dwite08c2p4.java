//https://dmoj.ca/problem/dwite08c2p4
import java.util.*;
import java.io.*;
public class bigShinyTunes {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        for(int t = 0; t<5; t++){
            int s = readInt(); //space
            int n = readInt(); // albums
            int[] space = new int[n+1];//space required
            int[] utility = new int[n+1];//utility 
            int[][] dp = new int[2][s+1];

            for(int i = 1; i<=n; i++){
                space[i] = readInt();
                utility[i] = readInt();

            }

            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=s; j++){
                    dp[1][j] = Math.max(dp[0][j],dp[1][j-1] );
                    if(j>=space[i]){
                        dp[1][j] = Math.max(dp[1][j], utility[i]+dp[0][j-space[i]]);
                    }
                }

                for(int j = 1; j<=s; j++){
                    dp[0][j] = dp[1][j];
                }
            }
            System.out.println(dp[0][s]);
        }
    
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