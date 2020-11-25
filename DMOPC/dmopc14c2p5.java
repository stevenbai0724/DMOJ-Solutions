//https://dmoj.ca/problem/dmopc14c2p5
import java.util.*;
import java.io.*;
public class sawmill {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        
        int n = readInt();
        int m = readInt();
        ArrayList<Integer>adj[] = new ArrayList[n+1];
       
        double[] dp = new double[n+1];

        for(int i = 1; i<= n; i++){
            adj[i] = new ArrayList(); 

        }

        for(int i = 1; i<=m; i++){
            int x = readInt();
            int y = readInt();

            adj[x].add(y);
            
        }

        dp[1] = 1;
        
        for(int i = 1; i<=n; i++){
            for(int j = 0; j< adj[i].size(); j++){
                dp[adj[i].get(j)] += dp[i] * 1/adj[i].size();
            }
            
        }

        for(int i = 1; i<=n; i++){

            if(adj[i].size()==0){
                System.out.println(dp[i]);
            }
            
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