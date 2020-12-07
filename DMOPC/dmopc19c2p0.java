//https://dmoj.ca/problem/dmopc19c2p0
import java.util.*;
import java.io.*;


public class rollercoaster{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int min = sc.nextInt();
        int max = sc.nextInt();
        int count = 0;

        for(int i = 1; i<=n; i++){
            int x = sc.nextInt();
            
            if(x>=min && x<=max) count++;

        }
        System.out.println(count);



    }
}