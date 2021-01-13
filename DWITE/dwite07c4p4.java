//https://dmoj.ca/problem/dwite07c4p4
import java.util.*;
import java.io.*;
public class shortestPath {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        for (int t =0; t<5; t++){

            char[][]array = new char[12][12];
            int start = 0;

            for(int i = 1; i<=10; i++){
                String s = readLine();
                for(int j = 1; j<=10; j++){
                    array[i][j] = s.charAt(j-1);
                    if(array[i][j]=='X')
                        start = i*20 + j; //store cord of start in one int variable
                }
            }

            boolean[][]vis = new boolean[12][12];
            int[][]dis = new int[12][12];
            Queue<Integer>q = new LinkedList();
            int[]changex = {-1,0,1,1,1,0,-1,-1};
            int[]changey = {-1,-1,-1,0,1,1,1,0};

            q.add(start); vis[start/20][start%20] = true;
            while(!q.isEmpty()) {
                int cur = q.poll(); 
                int x = cur/20; 
                int y = cur%20;
                for(int i = 0; i<8; i++) {
                    int newx = x+changex[i]; 
                    int newy = y+changey[i];
                    if(!vis[newx][newy] && (array[newx][newy]=='.'||array[newx][newy]=='X')) {
                        vis[newx][newy] = true;
                        dis[newx][newy] = dis[x][y] +1;
                        q.add(newx*20+newy);
                    }
                }
            }
            int ans = 0;
            for(int i = 1; i<=10; i++) {
                for(int j = 1; j<=10; j++) {
                    if(i*20+j!=start&&array[i][j]=='X') {
                        ans = dis[i][j];
                    }
                }
            }
            System.out.println(ans);
            br.readLine();

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