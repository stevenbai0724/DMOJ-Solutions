//https://dmoj.ca/problem/dmopc13c3p3
import java.util.*;
import java.io.*;
public class crossingField {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        
        int n = readInt();
        int min = readInt();
        int start = 2001;

        int[][]array = new int[n+1][n+1];

        for(int i =1; i<= n; i++){
            for(int j = 1; j<= n; j++){
                array[i][j] = readInt();
            }
        }

        Queue<Integer>q = new LinkedList();
        boolean[][]vis = new boolean[n+1][n+1];
        int[]changex = {0,1,0,-1};
        int[]changey = {-1,0,1,0};
        q.add(start);
        vis[start/2000][start%2000] = true;

        while(!q.isEmpty()){
            int cur = q.poll();
            int x = cur/2000;
            int y = cur%2000;

            for(int i = 0 ; i< 4; i++){
                int newx = x + changex[i];
                int newy = y + changey[i];

                if(newx>0 && newx<=n && newy>0 && newy<=n){
                    if(!vis[newx][newy] && Math.abs(array[newx][newy] - array[x][y])<=min){
                        vis[newx][newy] = true;
                        q.add(newx*2000 + newy);
                    }
                }
            }
        }

        if(vis[n][n] == true){
            System.out.println("yes");
        }
        else
            System.out.println("no");
        
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
