//https://dmoj.ca/problem/bf3
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner (System.in);

        int num = sc.nextInt();
        boolean yes = true;
        
        if (num ==1){
            System.out.println(2);
            yes = false;
        }
            
        while (yes){
            boolean notprime = false;
            
            for (int i = 2; i*i <= num; i++){
                if (num%i ==0 ){
                    notprime = true;
                }
                
            }
            if (notprime == false){
                System.out.println(num);
                yes = false;
            }
            else
                num++;
        }
    
        
    }
}