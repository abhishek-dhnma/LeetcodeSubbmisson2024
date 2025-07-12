class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {

        int totalPlayers = n;

        // Normalize player positions
        int posA = firstPlayer;
        int posB = secondPlayer;

        // If players face each other directly (symmetrically from ends)
        if (posA == totalPlayers - posB + 1) {
            return {1, 1}; // Meet in the first round
        }

        // Normalize to always keep posA < mirrored posB
        // Normalize positions to ensure posA is always less than posB
        if (posA > totalPlayers - posB + 1) {
            int mirroredB = totalPlayers - posA + 1;
            posA = totalPlayers - posB + 1;
            posB = mirroredB;
        }

        int earliestRound = totalPlayers; // initialize with max possible round
        int latestRound = 1;              // initialize with min possible round
        int playersNextRound = (totalPlayers + 1) / 2; // number of players after one round (after pairing)

        if (posB <= playersNextRound) {
            // ===== CASE 1: Both players are on the same side of the bracket =====

            int playersBeforeA = posA - 1;               // players to the left of posA
            int playersBetween = posB - posA - 1;        // players between posA and posB

            // Try all combinations of surviving players before A and between A & B
            for (int survivorsBeforeA = 0; survivorsBeforeA <= playersBeforeA; survivorsBeforeA++) {
                for (int survivorsBetween = 0; survivorsBetween <= playersBetween; survivorsBetween++) {

                    // Calculate new positions in the next round
                    int nextPosA = survivorsBeforeA + 1;
                    int nextPosB = nextPosA + survivorsBetween + 1;

                    // Recursive call to check the rounds from this configuration
                    vector<int> result =
                        earliestAndLatest(playersNextRound, nextPosA, nextPosB);

                    // Update earliest and latest round seen so far
                    earliestRound = min(result[0] + 1, earliestRound);
                    latestRound = max(result[1] + 1, latestRound);
                }
            }
        } else {
            // ===== CASE 2: Players are on opposite sides of the bracket =====

            int opponentsFromRight = totalPlayers - posB + 1;         // number of match-ups on right side
            int playersBeforeA = posA - 1;                             // players before player A
            int playersBetweenAandMirrorB = opponentsFromRight - posA - 1; // players between A and mirrored B
            int playersBetweenMirrorBandB = posB - opponentsFromRight - 1; // players between mirrored B and B

            // Try all possible survivors before A and between A and mirrored B
            for (int survivorsBeforeA = 0; survivorsBeforeA <= playersBeforeA; survivorsBeforeA++) {
                for (int survivorsBetween = 0; survivorsBetween <= playersBetweenAandMirrorB; survivorsBetween++) {

                    // Calculate new positions for next round
                    int nextPosA = survivorsBeforeA + 1;
                    int nextPosB = nextPosA + survivorsBetween + (playersBetweenMirrorBandB + 1) / 2 + 1;

                    // Recursive call
                    vector<int> result =
                        earliestAndLatest(playersNextRound, nextPosA, nextPosB);

                    // Update round values
                    earliestRound = min(result[0] + 1, earliestRound);
                    latestRound = max(result[1] + 1, latestRound);
                }
            }
        }

        // Return the earliest and latest round in which A and B can meet
        return {earliestRound, latestRound};
    }
};