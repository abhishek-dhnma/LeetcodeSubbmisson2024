class Solution {
    public int totalNumbers(int[] digits) {

            int[] freq = new int[10];

        // Count frequency of each digit
        for (int d : digits) {
            freq[d]++;
        }

        List<Integer> result = new ArrayList<>();

        // Every 3-digit even number
        for (int num = 100; num <= 998; num += 2) {

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            int[] needed = new int[10];

            needed[a]++;
            needed[b]++;
            needed[c]++;

            boolean valid = true;

            for (int i = 0; i < 10; i++) {
                if (needed[i] > freq[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                result.add(num);
            }
        }

        return result.size();
        
    }
}