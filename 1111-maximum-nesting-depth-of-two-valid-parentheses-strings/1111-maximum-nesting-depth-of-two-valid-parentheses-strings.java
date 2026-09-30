class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] answer = new int[seq.length()];
        int depth = 0;
        
        for (int i = 0; i < seq.length(); i++) {
            char c = seq.charAt(i);
            
            if (c == '(') {
                depth++; // We are going one level deeper
                // If depth is 1 (odd), answer is 1. If 2 (even), answer is 0.
                answer[i] = depth % 2; 
            } else {
                // For a closing bracket, assign it to the group that matches the current depth
                answer[i] = depth % 2; 
                depth--; // Then step back up one level
            }
        }
        
        return answer;
    }
}