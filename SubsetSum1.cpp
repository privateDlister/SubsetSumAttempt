
#include <iostream>
#include <cstring>


const int arraysize = 5;

int passingarray[arraysize] = {9,12,4,2,1};

int target = 19;

int starter=0;

using namespace std;

void displayDepth (int depth) {

    for (int iii=0; iii < depth; iii++) {

    cout << " = = = > " ;

    }

}

int getMax(int arr[], int starter) {

    int largest = arr[arraysize-1];

    for (int iii = starter; iii < arraysize; iii++) {

        if (arr[iii] > largest) {

            largest = arr[iii];

        }

    }

    return largest;

}

int getMin(int arr[], int starter) {

    int smallest = arr[0];

    for (int iii = starter; iii < arraysize; iii++) {

        if (arr[iii] < smallest) {

            smallest = arr[iii];

        }

    }

    return smallest;


}



bool RuleOut(int passedarray[], int starter, int depth) {

    int subarray[arraysize];

    memcpy(subarray, passedarray, sizeof(subarray));

    for (int iii = starter; iii<arraysize; iii++) {

        int maxval = getMax(subarray, starter+1); // so that we get a different max/min

        int minval = getMin(subarray, starter+1);

        starter++;

        cout << endl << endl;

        displayDepth(depth);
        cout << "depth: " << depth << ", pass: " << iii << endl;
        displayDepth(depth);
        cout <<"subarray value here: " << subarray[iii] <<  ", starter: " << starter << ", maxval: " << maxval<< ", minval: " << minval << endl;
        displayDepth(depth);
        cout << "subarray[" << iii << "]+minval = " << subarray[iii]+minval << endl;
        displayDepth(depth);
        cout << "subarray[" << iii << "]+maxval = " << subarray[iii]+maxval << endl;
        displayDepth(depth);
        cout << "target: " << target << endl;

        if ((subarray[iii]+minval == target) || (subarray[iii]+maxval == target) || (subarray[iii] == target)) {

        displayDepth(depth);
        cout << "!*!*!*!*!*!*!*!*!*!*!*There is a solution!" << endl;

        displayDepth(depth);
        cout << "depth: " << depth << ", values - iii: " << subarray[iii] << ", min: " << minval << ",max: " << maxval << endl;
        return true;

        } else if ((subarray[iii]+minval) < target) {
            displayDepth(depth);
            cout << "iii+minval not greater than target, number could be used with more to reach sum" << endl;

            if (subarray[iii]+maxval < target) {
                displayDepth(depth);
                cout << "iii+maxval not greater than target, can only be used with more numbers to reach target " << endl;

                for (int qqq = iii+1; qqq < arraysize; qqq++) {

                    subarray[qqq] = subarray[iii] + subarray[qqq];
                    displayDepth(depth);
                    cout << "Calling RuleOut where subarray[qqq] = " << subarray[qqq] << endl;
                    bool childFoundSolution = RuleOut(subarray, qqq, depth+1);

                    if (childFoundSolution == true) {

                        displayDepth(depth);
                        cout << "parent returning true" << endl;
                        return true;

                    }

                }

            } else {

                displayDepth(depth);
                cout << "iii + maxval were higher than target, so it's possible a combination with this many numbers works" << endl;

                for (int qqq = iii+1; qqq < arraysize; qqq++) {

                    displayDepth(depth);
                    cout << "adding subaray[iii]: " << subarray[iii] <<" and subarray[qqq]: " << subarray[qqq] << endl;

                   if (subarray[iii] + subarray[qqq] == target) {

                   displayDepth(depth);
                   cout << "!*!*!*!*!*!*!*!*!*!*!*There is a solution!" << endl;
                   displayDepth(depth);
                   cout << "depth: " << depth << ", values - iii: " << subarray[iii] << ", qqq: " << subarray[qqq] << endl;

                   return true;

                   }

                }

                displayDepth(depth);
                cout << "can't make total with this many numbers, will use more" << endl;
                for (int qqq = iii+1; qqq < arraysize; qqq++) {

                    int * nextLevelArray;

                    nextLevelArray = new int [arraysize];

                    memcpy(nextLevelArray, subarray, sizeof(subarray));

                    displayDepth(depth); cout << "Nextarrayiii: " << nextLevelArray[iii] << ", nextarrayqqq: " << nextLevelArray[qqq] << endl;
                    displayDepth(depth); cout << "changing qqq to qqq+iii" << endl;
                    nextLevelArray[qqq] = nextLevelArray[iii] + nextLevelArray[qqq];
                    displayDepth(depth); cout << "Nextarrayiii: " << nextLevelArray[iii] << ", nextarrayqqq: " << nextLevelArray[qqq] << endl;
                    displayDepth(depth);
                    cout << "Calling RuleOut where nextarray = " << nextLevelArray[qqq] << endl;

                    bool resultPresent = RuleOut(nextLevelArray, qqq, depth+1);

                    if (resultPresent) {

                    displayDepth(depth);
                   cout << "!*!*!*!*!*!*!*!*!*!*!*There is a solution!" << endl;
                   displayDepth(depth); cout << "depth: " << depth << ", value: " << nextLevelArray[qqq] << endl;

                   return true;

                    }

                }

            }

        } else {displayDepth(depth);cout << "Number here is too large to sum with any other in list" << endl;}

        }

        displayDepth(depth);cout << "returning false" << endl;
        return false;

}

int main () {

        bool resultFound = RuleOut(passingarray, 0, 0);


        if (resultFound) {
            cout << "There is a subset sum!" << endl;
        } else {
            cout << "No subset sum found" << endl;
        }
}
