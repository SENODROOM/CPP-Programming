#include <iostream>
using namespace std;

//---------------------------------
// Extensive top-level commentary
//---------------------------------
// Program overview: This program schedules meetings into rooms and finds which room hosts the most meetings.
// We want to handle any number of meetings and rooms (within predefined MAX limits).
// It demonstrates array manipulation, simple sorting, room assignment logic, and maximum-finding.
// The code avoids STL containers like vector, queue, or algorithm library functions deliberately.
// Instead, it relies on simple arrays and loops, making it suitable for teaching basic C++ constructs.
// Step-by-step, this program shows input, processing, and output, emphasizing logic clarity.
// It also shows handling scheduling conflicts: meetings may overlap, and rooms may need delay.
// The program finally reports which room is the busiest, useful for facility management.
// This file includes extremely detailed comments to explain each line, variable, and design choice.
// The goal is to create a teaching-grade, self-explanatory program for beginners or for exam preparation.

//---------------------------------
// Constants and maximum sizes
//---------------------------------
#define MAX_MEETINGS 1000 // Maximum meetings the program can handle
#define MAX_ROOMS 100     // Maximum rooms the program can handle

//---------------------------------
// Main function: program entry
//---------------------------------
int main()
{
    //---------------------------------
    // Input section: number of rooms and meetings
    //---------------------------------
    int n, m;
    cout << "Enter number of rooms: ";
    cin >> n;
    cout << "Enter number of meetings: ";
    cin >> m;

    //---------------------------------
    // Arrays to hold start/end times
    //---------------------------------
    long long start[MAX_MEETINGS]; // Start times for each meeting
    long long end[MAX_MEETINGS];   // End times for each meeting
    long long tempStart, tempEnd;  // Temporary variables for reading input


    //---------------------------------
    // Read meeting times from user with validation
    //---------------------------------
    for (int i = 0; i < m; i++)
    {
        //---------------------------------
        // Temporary variables to hold user input
        //---------------------------------
        long long tempStart, tempEnd;

        //---------------------------------
        // Loop until valid meeting times are entered
        //---------------------------------
        while (true)
        {
            // Prompt user for start time of meeting i+1
            cout << "Enter the start time of meeting " << i + 1 << ": ";
            cin >> tempStart;

            // Prompt user for end time of meeting i+1
            cout << "Enter the end time of meeting " << i + 1 << ": ";
            cin >> tempEnd;

            //---------------------------------
            // Validate that end time is not smaller than start time
            //---------------------------------
            if (tempEnd >= tempStart)
            {
                // Valid input; break out of the loop
                break;
            }
            else
            {
                // Invalid input; prompt the user again
                cout << "Error: End time must be greater than or equal to start time. Please re-enter." << endl;
            }
        }

        //---------------------------------
        // Store valid times into arrays
        //---------------------------------
        start[i] = tempStart; // Save start time in the start array
        end[i] = tempEnd;     // Save end time in the end array

        //---------------------------------
        // Explanation:
        // - start[i] and end[i] together represent the i-th meeting.
        // - Using parallel arrays ensures that each meeting's times stay aligned.
        // - This design is simple, avoids advanced constructs, and is easy for teaching.
        //---------------------------------
    }

    //---------------------------------
    // Sort meetings by start time (Bubble sort for clarity)
    //---------------------------------
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < m - i - 1; j++)
        {
            // Compare consecutive meeting start times
            if (start[j] > start[j + 1])
            {
                // Swap start times if out of order
                long long t1 = start[j];
                start[j] = start[j + 1];
                start[j + 1] = t1;

                // Swap corresponding end times to maintain meeting pairs
                long long t2 = end[j];
                end[j] = end[j + 1];
                end[j + 1] = t2;
            }
        }
    }
    // Bubble sort is O(m^2) time complexity; simple, understandable for teaching
    // In production, faster sorting algorithms like quicksort or mergesort could be used

    //---------------------------------
    // Initialize room tracking arrays
    //---------------------------------
    long long roomEnd[MAX_ROOMS]; // When each room becomes free
    int roomCount[MAX_ROOMS];     // How many meetings each room has hosted
    for (int i = 0; i < n; i++)
    {
        roomEnd[i] = 0;   // Initially, all rooms are free at time 0
        roomCount[i] = 0; // Initially, no meetings have occurred
    }

    //---------------------------------
    // Scheduling section: assign meetings to rooms
    //---------------------------------
    for (int i = 0; i < m; i++)
    {
        long long meetingStart = start[i];              // Current meeting start
        long long meetingEnd = end[i];                  // Current meeting end
        long long duration = meetingEnd - meetingStart; // Meeting duration

        int assignedRoom = -1;               // -1 means no room assigned yet
        long long earliestFree = 1000000000; // Sentinel for earliest available room

        //---------------------------------
        // Scan for first free room at meeting start
        //---------------------------------
        for (int j = 0; j < n; j++)
        {
            if (roomEnd[j] <= meetingStart)
            {
                // Room j is free; assign meeting here
                assignedRoom = j;
                break; // Stop at first free room
            }
        }

        //---------------------------------
        // If no room free, delay to earliest-free room
        //---------------------------------
        if (assignedRoom == -1)
        {
            for (int j = 0; j < n; j++)
            {
                if (roomEnd[j] < earliestFree)
                {
                    earliestFree = roomEnd[j]; // Track earliest room release
                    assignedRoom = j;
                }
            }
            // Adjust meeting start/end based on room availability
            meetingStart = roomEnd[assignedRoom];
            meetingEnd = meetingStart + duration;
        }

        //---------------------------------
        // Update room info with assigned meeting
        //---------------------------------
        roomEnd[assignedRoom] = meetingEnd; // Room occupied until this time
        roomCount[assignedRoom]++;          // Increment meeting count
    }

    //---------------------------------
    // Find the room with the most meetings
    //---------------------------------
    int maxMeetings = -1; // Track maximum number of meetings
    int resultRoom = -1;  // Track room index with maximum meetings
    for (int i = 0; i < n; i++)
    {
        if (roomCount[i] > maxMeetings)
        {
            maxMeetings = roomCount[i]; // Update maximum
            resultRoom = i;             // Update room index
        }
    }

    //---------------------------------
    // Output section
    //---------------------------------
    cout << "Room with most meetings: " << resultRoom << endl;
    cout << "Number of meetings: " << maxMeetings << endl;

    //---------------------------------
    // Optional: print per-room meeting counts
    //---------------------------------
    for (int i = 0; i < n; i++)
    {
        cout << "Room " << i << ": " << roomCount[i] << " meetings" << endl;
    }

    return 0;
}

//---------------------------------
// Deep explanation summary
//---------------------------------
// 1. Input handling uses simple arrays to store times.
// 2. Bubble sort is used to keep meeting ordering consistent.
// 3. Each room tracks its next available time (roomEnd array).
// 4. Meeting counts are tracked in roomCount array.
// 5. Scheduling logic:
//    a. Try to assign to a free room at meeting start.
//    b. If none free, pick the earliest available room.
// 6. Output includes both the busiest room and detailed counts for all rooms.
// 7. Program emphasizes array manipulation, loops, and conditional logic.
// 8. Avoids STL, classes, and advanced constructs to focus on algorithm basics.
// 9. Bubble sort shows explicit swapping, reinforcing array element manipulation.
// 10. Edge cases: meetings with same start times, overlapping meetings, zero-duration meetings.
// 11. This code is suitable for educational purposes and small-scale scheduling problems.
// 12. Future improvements could include dynamic memory, STL containers, or more efficient sorting.
// 13. All variables are carefully named to match their role, improving readability and maintainability.
// 14. Sentinel values like 1000000000 demonstrate use of "large number" placeholders in logic.
// 15. The code structure separates input, processing, and output clearly, which is a good programming practice.
// 16. Each step includes comments explaining logic, which aids debugging and learning.

//---------------------------------
// TEST CASES:
//---------------------------------

// Example 1:

// Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
// Output: 0
// Explanation:
// - At time 0, both rooms are not being used. The first meeting starts in room 0.
// - At time 1, only room 1 is not being used. The second meeting starts in room 1.
// - At time 2, both rooms are being used. The third meeting is delayed.
// - At time 3, both rooms are being used. The fourth meeting is delayed.
// - At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
// - At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
// Both rooms 0 and 1 held 2 meetings, so we return 0.
// Example 2:

// Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
// Output: 1
// Explanation:
// - At time 1, all three rooms are not being used. The first meeting starts in room 0.
// - At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
// - At time 3, only room 2 is not being used. The third meeting starts in room 2.
// - At time 4, all three rooms are being used. The fourth meeting is delayed.
// - At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
// - At time 6, all three rooms are being used. The fifth meeting is delayed.
// - At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
// Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1.