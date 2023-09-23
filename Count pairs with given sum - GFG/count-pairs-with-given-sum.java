//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

public class GFG {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            inputLine = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int k = Integer.parseInt(inputLine[1]);
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            int ans = new Solution().getPairsCount(arr, n, k);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    int getPairsCount(int[] arr, int n, int k) {
      Map<Integer,Integer>mp=new HashMap<Integer,Integer>();
      int count=0;
      for(int i=0;i<n;i++)
      {
           if (mp.containsKey(k - arr[i])) {
                count += mp.get(k - arr[i]);
            }
        int currentValue = mp.getOrDefault(arr[i], 0);

        // Increment the value by one
        int newValue = currentValue + 1;

        // Put the updated value back into the map
        mp.put(arr[i], newValue);

      }
      return count;
    }
}
