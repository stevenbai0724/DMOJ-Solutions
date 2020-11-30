import java.io.*;
import java.util.*;

public class aMinusB {
    public static void main(String[] args) {


    Scanner sc = new Scanner (System.in);
    
    int problems = sc.nextInt();
    
    for (int i = 0; i < problems; i++){
        int num1 = 0;
        int num2 = 0;
        int sum = 0;
        
        num1 = sc.nextInt();
        num2 = sc.nextInt();
        
        sum = num1 - num2;
        
        System.out.println(sum);
    }



    }
}