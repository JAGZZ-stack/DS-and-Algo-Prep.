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

// If want to simply count the total number of groups
import java.util.*;

public class Main {
    static ArrayList<ArrayList<Integer>> adjacency = new ArrayList<>();
    static int[] vis;
    static int componentNumber = 0; // This is our final answer

    static void dfs(int node) {
        vis[node] = 1; // Just put a generic "Checked" mark (1)
        
        // Follow the chain of hands to mark everyone in this group
        for (int friend : adjacency.get(node)) {
            if (vis[friend] == 0) { 
                dfs(friend);
            }
        }
    }

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt(); 
        int m = sc.nextInt(); 

        for (int i = 0; i <= n; i++) {
            adjacency.add(new ArrayList<>());
        }
        vis = new int[n + 1];

        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            adjacency.get(a).add(b);
            adjacency.get(b).add(a);
        }

        // THE TEACHER'S WALK-AROUND
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                // Every time we find someone without a sticker, 
                // it means we found exactly ONE new group.
                componentNumber++; 
                dfs(i); // Mark all their friends so we don't count them again
            }
        }

        // JUST PRINT THE TOTAL
        System.out.println(componentNumber);
    }

    public static void main(String[] args) {
        solve();
    }
}

// Number of components in each node
static int dfs(int node) {
    vis[node] = 1;      // Mark this kid as "counted"
    int totalNodesFound = 1; // Start with 1 (counting the current kid)

    for (int friend : adjacency.get(node)) {
        if (vis[friend] == 0) {
            // Ask the friend to go count their group and report back
            int nodesInFriendBranch = dfs(friend);
            
            // Add that friend's group count to our current total
            totalNodesFound = totalNodesFound + nodesInFriendBranch;
        }
    }
    
    return totalNodesFound; // Tell the person who called us the final total
}

public static void solve() {
    Scanner sc = new Scanner(System.in);
    
    // 1. Get input
    if (!sc.hasNextInt()) return;
    int n = sc.nextInt(); 
    int m = sc.nextInt(); 

    // 2. Setup (The "Cupboards")
    for (int i = 0; i <= n; i++) {
        adjacency.add(new ArrayList<>());
    }
    vis = new int[n + 1];

    // 3. Build the graph (The "Hand-holding")
    for (int i = 0; i < m; i++) {
        int a = sc.nextInt();
        int b = sc.nextInt();
        adjacency.get(a).add(b);
        adjacency.get(b).add(a);
    }

    // --- THE TEACHER'S WALK-AROUND ---
    ArrayList<Integer> allGroupSizes = new ArrayList<>();

    for (int i = 1; i <= n; i++) {
        // If we find a kid with no sticker (unvisited)...
        if (vis[i] == 0) {
            
            // WE START THE COUNT HERE:
            // The DFS goes into the crowd and returns the total count for THIS group.
            int sizeOfThisGroup = dfs(i);
            
            // Save that number in our list
            allGroupSizes.add(sizeOfThisGroup);
        }
    }

    // --- FINAL REPORT ---
    System.out.println("Total number of groups: " + allGroupSizes.size());
    for (int i = 0; i < allGroupSizes.size(); i++) {
        System.out.println("Group " + (i + 1) + " has " + allGroupSizes.get(i) + " kids.");
    }
}

// Check if x and y belong to the same group
import java.util.*;

public class Main {
    // 1. Storage
    static ArrayList<ArrayList<Integer>> adjacency = new ArrayList<>();
    static int[] groupSticker; // Instead of just "vis", we store the Group ID here
    static int componentCount = 0;

    // --- THE LABELING PROCESS ---
    static void labelGroup(int node, int id) {
        groupSticker[node] = id; // Give this kid the current group's ID sticker
        
        for (int friend : adjacency.get(node)) {
            // If the friend doesn't have a group sticker yet
            if (groupSticker[friend] == 0) {
                labelGroup(friend, id);
            }
        }
    }

    public static void solve() {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter number of kids (N) and connections (M):");
        if (!sc.hasNextInt()) return;
        int n = sc.nextInt(); 
        int m = sc.nextInt(); 

        // Initialize shelves
        for (int i = 0; i <= n; i++) {
            adjacency.add(new ArrayList<>());
        }
        groupSticker = new int[n + 1];

        // Build the map
        System.out.println("Enter the M connections (a b):");
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            adjacency.get(a).add(b);
            adjacency.get(b).add(a);
        }

        // --- PHASE 1: PRE-PROCESS THE ENTIRE GRAPH ---
        for (int i = 1; i <= n; i++) {
            if (groupSticker[i] == 0) {
                componentCount++; // Found a new group
                labelGroup(i, componentCount); // Label everyone in this group
            }
        }

        // --- PHASE 2: THE QUERY ---
        System.out.println("\nEnter two kids (X and Y) to check if they are in the same group:");
        int x = sc.nextInt();
        int y = sc.nextInt();

        if (x > n || y > n || x < 1 || y < 1) {
            System.out.println("Invalid kid IDs.");
        } else if (groupSticker[x] == groupSticker[y]) {
            System.out.println("YES! Kid " + x + " and Kid " + y + " are in the same group (Group ID: " + groupSticker[x] + ").");
        } else {
            System.out.println("NO! They belong to different groups.");
            System.out.println("Kid " + x + " is in Group " + groupSticker[x]);
            System.out.println("Kid " + y + " is in Group " + groupSticker[y]);
        }
    }

    public static void main(String[] args) {
        solve();
    }
}
