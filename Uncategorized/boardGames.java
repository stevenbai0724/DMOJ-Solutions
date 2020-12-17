import java.util.*;
import java.io.*;
public class boardGames {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        
        int[]array = new int[10000005];

        int start = readInt();
        int end = readInt();

        Queue<Integer>q = new LinkedList();
        boolean[]vis = new boolean[10000005];
        int[]dis = new int[10000005];
        int[]change = {-1, -3};
        vis[start] = true;
        q.add(start);

        while(!vis[end]){
            int cur = q.poll();
            
            for(int i = 0; i<4; i++){
                int newx = 0;
                if(i>=0 && i<=1)
                    newx = cur + change[i];
                if(i==2)
                    newx = cur*3;
                if(i==3 && cur%2==0)
                    newx = cur/2;
                
                if(newx>=0 && newx<=10000000){
                    if(!vis[newx]){
                        vis[newx]=true;
                        dis[newx] = dis[cur]+1;
                        q.add(newx);
                    }
                }                   
            }
        }

        System.out.println(dis[end]);
        
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