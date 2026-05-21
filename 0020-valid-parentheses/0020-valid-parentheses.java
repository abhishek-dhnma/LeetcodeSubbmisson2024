class Solution {
    public boolean isValid(String s) {

        // we will use Deque -> ArrayDeque -> Double Ended Queue
        // TC : O(N), SC : O(N) -> N number of characters
        Deque<Character> stack = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else {
                if (stack.isEmpty())
                    return false;

                char top = stack.peek();
                if ((ch == ')' && top == '(') ||
                        (ch == ']' && top == '[') ||
                        (ch == '}' && top == '{')) {
                    stack.pop();
                } else {
                    return false;
                }
            }

        }

        return stack.isEmpty();

    }
}