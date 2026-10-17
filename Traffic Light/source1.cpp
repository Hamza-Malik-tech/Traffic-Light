#include <iostream>

using namespace std;

int main() 
{
    string roads[4] = { "North Road", "South Road", "East Road", "West Road" };
    int time, num1;
    for (time = 1;time <= 4;time++)
    {
        for (int round = 0; round < 4; round++) {
            cout << "--- Round " << (round + 1) << " Start ---" << endl;

            string vehicleTypes[4];

            for (int i = 0; i < 3; i++)
            {
                cout << "Enter vehicle on " << roads[i] << " (e.g., SchoolVan, Ambulance, Car, None): ";
                cin >> vehicleTypes[i];
            }

            vehicleTypes[3] = "None";

            bool priorityFound = false;
            int priorityRoadIndex = -1;

            for (int i = 0; i < 3; i++)
            {
                if ((vehicleTypes[i] == "SchoolVan" || vehicleTypes[i] == "Ambulance") || (vehicleTypes[i] == "schoolvan" || vehicleTypes[i] == "ambulance"))
                {
                    priorityFound = true;
                    priorityRoadIndex = i;
                    break;
                }
            }


            if (priorityFound)
            {
                cout << "Priority vehicle detected on " << roads[priorityRoadIndex] << "!" << endl;
                cout << "Action: Allowing " << roads[priorityRoadIndex] << " to go." << endl;
                cout << "Action: STOP signal given to all other roads:" << endl;
                for (int i = 0; i < 4; i++)
                {
                    if (i != priorityRoadIndex)
                    {
                        cout << " - " << roads[i] << " is STOPPED." << endl;
                    }
                }
            }
            else
            {
                {
                    string roads[4] = { "East", "West", "North", "South" };
                    int traffic[4], num, total;
                    bool completed[4] = { false, false, false, false };
                    for (num = 1;num <= 4;num++)
                    {
                        for (int i = 0; i < 4; i++)
                        {
                            cout << "Enter vehicles on " << roads[i] << ": ";
                            cin >> traffic[i];

                            if (traffic[i] < 0)
                            {
                                cout << "Invalid traffic count!";
                                return 0;
                            }
                        }

                        cout << "\n=== Traffic Light System ===\n";


                        for (int turn = 0; turn < 4; turn++)
                        {
                            int maxIndex = -1;


                            for (int i = 0; i < 4; i++)
                            {
                                if (!completed[i])
                                {
                                    if (maxIndex == -1 ||
                                        traffic[i] > traffic[maxIndex])
                                    {
                                        maxIndex = i;
                                    }
                                }
                            }

                            cout << "\nTurn " << turn + 1 << endl;


                            if (traffic[maxIndex] > 10)
                                cout << "High traffic detected.\n";
                            else if (traffic[maxIndex] >= 5)
                                cout << "Medium traffic detected.\n";
                            else if (traffic[maxIndex] >= 3)
                                cout << "Low traffic detected.\n";
                            else
                                cout << "Very low traffic detected.\n";


                            for (int i = 0; i < 4; i++)
                            {
                                if (i == maxIndex)
                                    cout << roads[i] << ": GO\n";
                                else
                                    cout << roads[i] << ": STOP\n";
                            }


                            completed[maxIndex] = true;
                        }

                    }
                    return 0;
                }
            }

            cout << endl;
        }
    }
    return 0;
}