#include <cstdio>
#include <climits>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[50001];
        for (int i = 1; i <= n; i++) {
            scanf("%d", arr+i);
        }
        int left[50001];
        int right[50001];
        left[0] = 0;
        right[0] = 0;
        int leftMax[50001];
        int rightMax[50001];
        leftMax[0] = INT_MIN;
        rightMax[0] = INT_MIN;
        for (int i = 1; i < n; i++) {
            left[i] = left[i-1] > 0 ? left[i-1] + arr[i] : arr[i];
            right[i] = right[i-1] > 0 ? right[i-1] + arr[n-(i-1)] : arr[n-(i-1)];
            leftMax[i] = left[i] > leftMax[i-1] ? left[i] : leftMax[i-1];
            rightMax[i] = right[i] > rightMax[i-1] ? right[i] : rightMax[i-1];
        }
        // for (int i = 1; i < n; i++) {
        //     leftMax[i] = left[i] > leftMax[i-1] ? left[i] : leftMax[i-1];
        //     rightMax[i] = right[i] > rightMax[i-1] ? right[i] : rightMax[i-1];
        // }
        int max = INT_MIN;
        for (int i = 1; i < n; i++) {
            int temp = leftMax[i] + rightMax[n-i];
            if (temp > max) {
                max = temp;
            }
        }
        printf("%d\n", max);
    }

    return 0;
}