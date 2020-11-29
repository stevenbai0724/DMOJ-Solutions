//https://dmoj.ca/problem/16bitswonly
import java.util.*;
import java.io.*;

class 16bitSWonly{

    public static void main (String[] args){
 
        Scanner sc = new Scanner (System.in);

        int x = sc.nextInt();
        
        for (int i = 0; i<x; i++){
            long n1 = sc.nextLong();
            long n2 = sc.nextLong();
            long ans = sc.nextLong();
            
            if (n1*n2 == ans){
                System.out.println("POSSIBLE DOUBLE SIGMA");
            }
            
            else
                System.out.println("16 BIT S/W ONLY");
            
        
}
}
}