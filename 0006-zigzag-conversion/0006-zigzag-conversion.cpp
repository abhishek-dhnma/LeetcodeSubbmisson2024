class Solution {
public:
    string convert(string input, int numRows) {

        if (numRows == 1 || numRows >= (int)input.length()) return input;

    string result;
    result.reserve(input.length()); // reserve capacity for efficiency

    for (int row = 0; row < numRows; row++) {
        int currentIndex = row;
        int stepDown = 2 * (numRows - 1 - row);
        int stepUp = 2 * row;
        bool movingDown = true;

        while (currentIndex < (int)input.length()) {
            result += input[currentIndex];

            if (row == 0) {
                currentIndex += stepDown;
            } else if (row == numRows - 1) {
                currentIndex += stepUp;
            } else {
                if (movingDown) {
                    currentIndex += stepDown;
                } else {
                    currentIndex += stepUp;
                }
                movingDown = !movingDown;
            }
        }
    }

    return result;
        
    }
};