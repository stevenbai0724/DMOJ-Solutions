import java.util.*;
import java.io.*;
public class afk {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        
        int cases = readInt();


        for(int t = 0; t<cases; t++){

            int l = readInt();
            int w = readInt();
            int start = 0;
            int end = 0 ;
            char array[][] = new char[w+1][l+1];

            for(int i = 1; i<=w; i++){
                String s = readLine();
                for(int j = 1; j<=l; j++){
                    array[i][j] = s.charAt(j-1);

                    if(array[i][j] == 'C')
                        start = i*100 + j;

                    if(array[i][j] == 'W')
                        end = i*100 + j;
                }
            }
            boolean[][]vis = new boolean[w+1][l+1];
            int[][] dis = new int[w+1][l+1];
            Queue<Integer>q = new LinkedList();
            int[] changex = {1,-1,0,0};
            int[] changey = {0,0,1,-1};

            q.add(start);
            vis[start/100][start%100] = true;

            while(!q.isEmpty()){
                int cur = q.poll();
                int x = cur/100;
                int y = cur%100;

                for(int i = 0 ; i< 4 ; i++){
                    int newx = x + changex[i];
                    int newy = y + changey[i];

                    if(newx>0 && newx <=w && newy>0 && newy <=l){
                        if(!vis[newx][newy] && array[newx][newy]!='X'){
                            vis[newx][newy] =true;
                            dis[newx][newy] = dis[x][y] + 1;
                            q.add(newx*100 + newy);
                        }
                    }
                }
            }
            if(vis[end/100][end%100] && dis[end/100][end%100]<60)
                System.out.println(dis[end/100][end%100]);
            
            else
                System.out.println("#notworth");
            
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