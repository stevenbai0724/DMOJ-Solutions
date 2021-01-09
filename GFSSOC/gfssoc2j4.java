//https://dmoj.ca/problem/gfssoc2j4
import java.util.*;
import java.io.*;
public class Template {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[]args)throws IOException {
        int n = readInt();
        
        int q = readInt();
        
        int[]array = new int[n];
        int[]psa = new int[n];
        int sum = 0;
        
        for ( int i = 0; i<n; i++){
            
            array[i] = readInt();
        }
            
        for (int i = 0; i<n; i++){
            sum += array[i];
            psa[i] += sum;
        }     
        
        for (int i = 0; i<q; i++){
            int n1 = readInt();
            int n2 = readInt();
            
            
            if (n1  == 1)
            System.out.println(psa[n-1] - psa[n2-1]);
            
            else
            System.out.println(psa[n-1] - (psa[n2-1]-psa[n1-2] ));
            
        }
        pr.close();
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
