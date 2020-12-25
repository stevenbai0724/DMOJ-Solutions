//https://dmoj.ca/problem/wac4p2
import java.util.*;
import java.io.*;
public class squirrelElection {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        
        //dp[i][j] is the min voters to win j points in i provinces
        //j will be the sum of all the possible points to be won
        
        int n = readInt(); 
        int[] voters = new int[n+1];
        int[] points = new int[n+1];
        int s = 0;
        long ans = (long)(1e18);
        for(int i = 1; i<=n; i++){
            voters[i] = readInt();
            points[i] = readInt();

            s += points[i];
        }
        long[][]dp = new long[2][s+1];

        for(int i = 1; i<=s; i++){
            dp[0][i] = (long)(1e18);
        }
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=s; j++){
                dp[1][j] = dp[0][j];
                if(j>= (points[i]))
                    dp[1][j] = Math.min(dp[1][j], (voters[i])/2 + 1 + dp[0][j-points[i]]);

                if(j >= s/2 + 1)
                    ans = Math.min(ans, dp[1][j]);
            }
            for(int j = 1; j<= s; j++){
                dp[0][j] = dp[1][j];
            }
        }
        System.out.println(ans);
        
        
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