//https://dmoj.ca/problem/dmopc18c1p0
import java.io.*;
import java.util.*;

public class dmopc18c1p0 {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner (System.in);

        boolean yes = true;
        
        int[]array = new int[3];
        
        for (int i = 0; i<3; i++){
            array[i] = sc.nextInt();
            
        }
        
        for (int i = 0; i< 2; i++){
            if (array[i]>array[i+1]){
                yes = false;
            }
        }
        
        if (yes)
            System.out.println("Good job!");
            
        else
            System.out.println("Try again!");

    }


}