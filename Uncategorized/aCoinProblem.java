//https://dmoj.ca/problem/acoinproblem
import java.util.*;
import java.io.*;
public class aCoinProblem {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        int n = readInt(); //coins
        int v = readInt(); //queries

        int[]coins = new int[n+1];

        for(int i = 1; i<=n; i++) {
            coins[i] = readInt();
        }

        long[]queries = new long[v];//stores the queries
        int[]ans = new int[v];//stores the answers in the order the queries were asked

        for(int i = 0; i<v; i++) {
            int c = readInt(); //cost
            int l = readInt(); //first l available coins
            queries[i] = l*(long)1e11 + c*(long)1e6 + i;
            
        }

        Arrays.sort(queries);
        int[]dp = new int[20001];
        
        for(int i = 1; i<=10000; i++) {
            dp[i] = -1;
        }
        int cur = 1;//declared outside because we don't have to reset to find the remaining querries
        for(int i = 0; i<v; i++) {


            int l = (int)(queries[i]/(long)1e11); //first l coins
            int c = (int)((queries[i]%(long)1e11)/(long)1e6); //c cost
            int index = (int)(queries[i]%(long)1e6); //index of  query 
            for(; cur<=l; cur++) {//for each coin value
                for(int j = 0; j<=10000; j++) {

                    
                    if(dp[j]>=0) {
                        if(dp[j+coins[cur]]==-1) {
                            dp[j+coins[cur]] = dp[j]+1;
                        }
                        else {
                            dp[j+coins[cur]]= Math.min(dp[j+coins[cur]], dp[j]+1);
                        }
                    }
                }
            }
            ans[index] = dp[c];
        }
        for(int i = 0; i<v; i++) {
            System.out.println(ans[i]);
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
