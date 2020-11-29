//https://dmoj.ca/problem/a4b1
import java.io.*;
import java.util.*;

public class sorting {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner (System.in);
        int x = sc.nextInt();
        
        int[]array = new int[x];
        for (int i = 0; i<x; i++){
            array[i] = sc.nextInt();
        }
        
        while (true){
    
        boolean yes = true;

        for (int i =0; i<x-1;i++){
            if (array[i] > array[i+1]){
                yes = false;
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        if(yes){
            break;
        }
    }

    for(int i = 0; i<x; i++){
        System.out.println(array[i]);
    }

    }


}