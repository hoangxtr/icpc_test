#include <iostream>
#include <math.h>
# include <string.h>
using namespace std;

// int main() {
//     int temp = 0;
//     int n = 3;
//     int s1 = 0, s2 = 0;
//     int arr[n] = {12, 5, 3};
//     for (int i = 0; i < n; i ++) {
//         if (s1 > s2) temp = floor(arr[i] / 2.0);
//         else temp = ceil(arr[i] / 2.0);

//         s1 += temp;
//         s2 += (arr[i] - temp);
//     }
//     cout << s1 << "\t" << s2;
// }

int foo(int move_zone1[2][2], int n1, int move_zone2[1][2], int n2, int pos1, int pos2, int count) {
    bool check = false;
    int ret;
    for (int i = 0; i < n1; i ++) 
        for (int j = 0; j < n2; j ++) {
            check = false;
            if (move_zone1[i][0] == pos1) {
                pos1 = move_zone1[i][1];
                check = true;
            }
            if (move_zone2[j][0] == pos2) {
                pos2 = move_zone2[j][1];
                check = true;
            }
            if (check == false) continue;
            ret = foo(move_zone1, n1, move_zone2, n2, pos1, pos2, count + 1);
            if (ret %2 == 0) return ret;
            
        }
    return count;

}
int main() {
    int n1 = 2, n2 = 1;
    int init_pos1 = 2, init_pos2 = 1;
    int move_zone1[2][2] = {
        {1,2}, {2,3}
    };
    int move_zone2[1][2] = {
        {3,2}
    };
    int ret = foo(move_zone1, n1, move_zone2, n2, init_pos1, init_pos2, 0);
    if (ret != 0 && ret%2 == 0) cout << "first\n";
    else cout << "second";

}