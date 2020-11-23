//https://dmoj.ca/problem/dmopc14c2p4
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner (System.in);

        int n = sc.nextInt();
        
        int[]array = new int[n];
        int[]psa = new int[n];
        int sum = 0;
        
        for (int i = 0; i<n; i++){
            array[i] = sc.nextInt();
            
        }
        
        for (int i = 0; i<n; i++){
            sum += array[i];
            psa[i] =sum;
        }
  
        int q = sc.nextInt();
        
        for (int i = 0; i<q; i++){
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            
            if (n1  == 0)
            System.out.println(psa[n2]);
            
            else
            System.out.println(psa[n2]-psa[n1-1]);
            
        }
        
    }
}