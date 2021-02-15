#include <bits/stdc++.h>
using namespace std;

bool willMeet(int startA, int speedA, int startB, int speedB)
{
    if ((startA > startB && speedA > speedB) or (startB > startA && speedB > speedA))
    {
        return false;
    }

    if (startA > startB)
    {
        return willMeet(startB, speedB, startA, speedA);
    }

    while (startA <= startB)
    {
        if (startA == startB)
        {
            return true;
        }
        startA += speedA;
        startB += speedB;
    }
    return false;
}

bool willMeetOptimized(int startA, int speedA, int startB, int speedB)
{
    if ((startA > startB && speedA > speedB) or (startB > startA && speedB > speedA))
    {
        return false;
    }
    if (startA > startB)
    {
        return willMeet(startB, speedB, startA, speedA);
    }

    int distance = startB - startA;

    int relativeSpeed = speedB - speedA;

    if (distance % relativeSpeed == 0)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    int speedA, startA, speedB, startB;
    cin >> startA >> startB >> speedA >> speedB;
    if (willMeetOptimized(startA, speedA, startB, speedB))
    {
        cout << "They will meet." << endl;
    }
    else
    {
        cout << "They will not meet." << endl;
    }
    return 0;
}