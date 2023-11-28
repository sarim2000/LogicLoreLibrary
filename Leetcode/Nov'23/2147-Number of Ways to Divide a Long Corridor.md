## Question

```
Divide the corridor into non-overlapping sections, where each section has exactly two seats with any number of plants. There may be multiple ways to perform the division. Two ways are different if there is a position with a room divider installed in the first way but not in the second way.

Return the number of ways to divide the corridor. Since the answer may be very large, return it modulo 109 + 7. If there is no way, return 0.


Example 1:
Input: corridor = "SSPPSPS"
Output: 3
Explanation: There are 3 different ways to divide the corridor.
The black bars in the above image indicate the two room dividers already installed.
Note that in each of the ways, each section has exactly two seats.

SS|PPSPS
SSP|PSPS
SSPP|SPS

```

## Intuition

- there can't be odd number of seats 
- there can't be 0 seats
- we just need to find the position of seats between two pair of seats

## code

```c++
class Solution {
public:
    const int MOD = 1e9 + 7;

    int distanceBetweenSeats(const vector<int>& positions, int start) {
        return positions[start] - positions[start - 1];
    }

    int numberOfWays(string corridor) {
        vector<int> seatPositions;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                seatPositions.push_back(i);
            }
        }

        if (seatPositions.size() % 2 != 0 || seatPositions.empty()) {
            return 0; 
        }

        long long ways = 1;
        int index = 2;
        while (index < seatPositions.size()) {
            int choices = distanceBetweenSeats(seatPositions, index);
            ways = (ways * choices) % MOD;
            index += 2;
        }

        return ways;
    }
};

```