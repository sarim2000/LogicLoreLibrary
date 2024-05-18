// https://leetcode.com/problems/meeting-rooms-iii/

#include <bits/stdc++.h>
using namespace std;

int mostBooked(int n, vector<vector<int>> &meetings)
{
    vector<long long> room_availability_time(n, 0);
    vector<int> meeting_count(n, 0);
    sort(meetings.begin(), meetings.end());

    for (int i = 0; i < meetings.size(); i++)
    {
        int start = meetings[i][0], end = meetings[i][1];
        long long earlier_available_time = LLONG_MAX;
        int earlier_available_room = -1;
        bool room_found = false;

        for (int j = 0; j < n; j++)
        {
            if (room_availability_time[j] == 0 || start >= room_availability_time[j])
            {
                room_found = true;
                room_availability_time[j] = end;
                meeting_count[j]++;
                break;
            }
            else
            {
                long long might_free_by = room_availability_time[j] + end - start;
                if (might_free_by < earlier_available_time)
                {
                    earlier_available_time = might_free_by;
                    earlier_available_room = j;
                }
            }
        }

        if (!room_found)
        {
            cout << earlier_available_room << endl;
            room_availability_time[earlier_available_room] = earlier_available_time;
            meeting_count[earlier_available_room]++;
        }
    }

    int max_cnt = 0, room_ind = 0;

    for (int i = 0; i < n; i++)
    {
        if (meeting_count[i] > max_cnt)
        {
            max_cnt = meeting_count[i];
            room_ind = i;
        }
    }
    return room_ind;
}