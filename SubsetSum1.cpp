#include <iostream>

array mainArray[] = {15,12,2,5,3};

int target = 7;

int main () {




}

void RuleOut(int subarrayarray[], int starter) {

    int maxval = getMax(subarrayarray, starter);
    int minval = getMin(subarrayarray, starter);

    for (int iii = starter, iii < (sizeof(arr)/sizeof(arr[starter])); iii++) {

        if (iii+minval) > target) //Number can't be used
        else if (iii+maxval < target) {

            for (int qqq = iii+1; qqq < (sizeof(arr)/sizeof(arr[starter])); qqq++) {

                int subArray

            }

        }

    }

}

int getMax(int arr[], starter) {

    int largest = arr[0];

    for (int iii = starter, iii < (sizeof(arr)/sizeof(arr[starter])); iii++) {

        if (arr[iii] > largest) {

            largest = arr[iii];

        }

    }

    return largest;

}

int getMin(int arr[], starter) {

    int smallest = arr[0];

    for (int iii = starter, iii < (sizeof(arr)/sizeof(arr[starter])); iii++) {

        if (arr[iii] > largest) {

            smallest = arr[iii];

        }

    }

    return smallest;

}
