//https://dmoj.ca/problem/vpex1p1
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner (System.in);
        
        int array1[] = new int[5];
        int array2[] = new int[5];
        int smallestIndex1 = 0;
        int smallestIndex2 = 0;
        int smallest1 = 101;
        int smallest2 = 101;
        int sum1 = 0;
        int sum2 = 0;
        
        for (int i = 0; i<5; i++){
            array1[i] = sc.nextInt();
        }
        
        for (int i = 0; i<5; i++){
            array2[i] = sc.nextInt();
        }
        
        for (int i = 0; i<5; i++){
            if (array1[i] < smallest1){
                smallest1 = array1[i];
                smallestIndex1 = i;
            }
        }
        
        for (int i = 0; i<5; i++){
            if (array2[i] < smallest2){
                smallest2 = array2[i];
                smallestIndex2 = i;
            }
        }
        
        for (int i = 0; i<5; i++){
            if (i!=smallestIndex1)
                sum1 += array1[i];
            
      
        }
        
        for (int i = 0; i<5; i++){
            if (i != smallestIndex2)
                sum2 += array2[i];
            
        }
        

        if (sum1>sum2)
            System.out.println(sum1);
        
        else 
            System.out.println(sum2);
  
 
        
        
        
    }
}