// DFS Implementation :

import java.util.*;

public class Main {
    // 1. The Empty Cupboards (Declarations)
    // The "Hand-Holding" Cupboard: Stores the map of who is touching whom
    static ArrayList<ArrayList<Integer>> adjacency = new ArrayList<>();
    
    // The "Group Roster" Cupboard: Stores the final lists of each friendship group
    static ArrayList<TreeSet<Integer>> components = new ArrayList<>();
    
    // The Sticker Sheet: Tracks which group number is stuck to each kid
    static int[] vis;
    
    // The Sticker Counter: The number we write on the next set of stickers
    static int componentNumber = 0;

    // --- THE CHAIN REACTION (DFS) ---
    static void dfs(int node) {
        // Put the sticker on the current kid
        vis[node] = componentNumber; 
        
        // Put this kid's name (clothes) onto the correct Group Roster shelf
        components.get(componentNumber).add(node); 

        // Look at this kid's shelf in the Hand-Holding Cupboard to find friends
        for (int friend : adjacency.get(node)) {
            // If the friend doesn't have a sticker yet...
            if (vis[friend] == 0) { 
                // ...go to that friend and repeat the process
                dfs(friend);
            }
        }
    }

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt(); // Total kids
        int m = sc.nextInt(); // Total hand-holding pairs

        // 2. Adding the Shelves (Initialization)
        // We must build the shelves before we can put anything inside!
        for (int i = 0; i <= n; i++) {
            adjacency.add(new ArrayList<>()); // Add a shelf for kid i
            components.add(new TreeSet<>());  // Add a shelf for group i
        }
        vis = new int[n + 1]; // All kids start with sticker "0" (none)

        // 3. Putting Clothes in the Cupboard (Building the Map)
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            // Reach for shelf 'a', put 'b' on it. Reach for shelf 'b', put 'a' on it.
            adjacency.get(a).add(b);
            adjacency.get(b).add(a);
        }

        // --- THE TEACHER'S WALK-AROUND ---
        for (int i = 1; i <= n; i++) {
            // Teacher checks every kid. If no sticker is found...
            if (vis[i] == 0) {
                // ...start a new group number and start the chain reaction
                componentNumber++;
                dfs(i);
            }
        }

        // --- FINAL REPORT ---
        System.out.println("total number of components=" + componentNumber);
        for (int i = 1; i <= componentNumber; i++) {
            System.out.print("component " + i + ": ");
            // Look at each shelf in the Roster Cupboard and read the names
            for (int kidName : components.get(i)) {
                System.out.print(kidName + ", ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        solve();
    }
}
