//https://dmoj.ca/problem/dwite07c1p1
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner (System.in);

        int num = sc.nextInt();
        boolean notprime = false;
        
        if(num<=1)
            System.out.println("not");
            
        else{
            for (int i = 2; i*i <= num; i++){
                if(num % i ==0){
                    notprime = true;
                }
                
            }
            if(notprime)
                System.out.println("not");
                
            else
                System.out.println("prime");
        }
        
        
       
        
    }
}