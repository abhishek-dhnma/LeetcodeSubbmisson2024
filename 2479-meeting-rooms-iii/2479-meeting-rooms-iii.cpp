class Solution {
public:
    int mostBooked(int totalRooms, vector<vector<int>>& meetings) {

        // Step 1: Sort all meetings by their start time
        sort(meetings.begin(), meetings.end());

        // roomEndTime[i] stores the time when room i becomes available
        vector<long long> roomEndTime(totalRooms, 0); 

        // roomUsageCount[i] stores the number of times room i has been used
        vector<long> roomUsageCount(totalRooms, 0);

        // Step 2: Process each meeting one by one
        for (int i = 0; i < meetings.size(); i++) {
            int currentStart = meetings[i][0];         // Meeting start time
            int currentEnd = meetings[i][1];           // Meeting end time
            int meetingDuration = currentEnd - currentStart;

            bool roomAssigned = false;                 // Flag to check if we found a free room
            long long earliestAvailableTime = LLONG_MAX;       // Track the earliest time any room becomes free
            int earliestRoomIndex = 0;                 // Track the room that becomes free earliest

            // Step 3: Try to assign the current meeting to an available room
            for (int roomIndex = 0; roomIndex < totalRooms; roomIndex++) {
                // If the room is free before or exactly at the meeting start time
                if (roomEndTime[roomIndex] <= currentStart) {
                    roomEndTime[roomIndex] = currentEnd;    // Book the room till current meeting's end
                    roomUsageCount[roomIndex]++;            // Increase usage count
                    roomAssigned = true;                    // Mark as assigned
                    break;                                  // No need to check other rooms
                }

                // Track the room that will be free the earliest (for later use)
                if (roomEndTime[roomIndex] < earliestAvailableTime) {
                    earliestAvailableTime = roomEndTime[roomIndex];
                    earliestRoomIndex = roomIndex;
                }
            }

            // Step 4: If no room was available, delay the meeting and assign it to the earliest free room
            if (!roomAssigned) {
                roomEndTime[earliestRoomIndex] += meetingDuration; // Start after current booking ends
                roomUsageCount[earliestRoomIndex]++;               // Count the usage
            }
        }

        // Step 5: Find the room that was used the most
        int mostUsedRoom = -1;
        int maxUsage = 0;

        for (int roomIndex = 0; roomIndex < totalRooms; roomIndex++) {
            if (roomUsageCount[roomIndex] > maxUsage) {
                maxUsage = roomUsageCount[roomIndex];
                mostUsedRoom = roomIndex;
            }
        }

        return mostUsedRoom;
    }
};
