/*
=========================================================
Course Schedule (LeetCode 207)
Algorithm: DFS + Recursion Stack (Cycle Detection)

Goal:
Return true if all courses can be completed.
Return false if there is a cycle.

Time Complexity : O(V + E)
Space Complexity: O(V)
=========================================================
*/

class Solution {

    /*
     * dfs(u)
     *
     * Returns:
     * true  -> A cycle is found.
     * false -> No cycle from this node.
     */
    public boolean dfs(int u, List<List<Integer>> adj,
                       boolean[] onstack,
                       boolean[] visited) {

        // Mark node as visited.
        visited[u] = true;

        // Put node into current DFS recursion path.
        onstack[u] = true;

        // Visit every neighbour of u.
        for (int v : adj.get(u)) {

            /*
             * If neighbour is already in the current recursion stack,
             * we found a back edge.
             *
             * Back edge => Cycle exists.
             */
            if (onstack[v]) {
                return true;
            }

            /*
             * If neighbour has never been visited,
             * explore it.
             */
            if (!visited[v]) {

                /*
                 * If child finds a cycle,
                 * propagate the answer upward.
                 */
                if (dfs(v, adj, onstack, visited)) {
                    return true;
                }
            }
        }

        /*
         * Finished exploring this node.
         * Remove it from current recursion stack.
         */
        onstack[u] = false;

        // No cycle found.
        return false;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {

        /*
         * Build adjacency list.
         *
         * Edge:
         * prerequisite -> course
         *
         * Example:
         * [1,0]
         *
         * Means:
         * 0 must be completed before 1
         *
         * Graph:
         * 0 -> 1
         */

        List<List<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];

            adj.get(prerequisite).add(course);
        }

        /*
         * visited[i]
         * ----------------
         * Node has already been processed once.
         *
         * Prevents repeated DFS.
         */
        boolean[] visited = new boolean[numCourses];

        /*
         * onstack[i]
         * ----------------
         * Node is currently inside the recursion path.
         *
         * Used ONLY for cycle detection.
         */
        boolean[] onstack = new boolean[numCourses];

        /*
         * Graph may be disconnected.
         * Therefore run DFS from every unvisited node.
         */
        for (int i = 0; i < numCourses; i++) {

            if (!visited[i]) {

                /*
                 * dfs() returns true when cycle exists.
                 */
                if (dfs(i, adj, onstack, visited)) {
                    return false;
                }
            }
        }

        // Entire graph has no cycle.
        return true;
    }
}