

int LIS(int nums[], int n) {
    int dp[n];
    int maxLength = 1;
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
        }
    }
    
    return maxLength;
}

int main() {
    int nums[] = {4, 5, 1, 8, 3, 6, 9 ,2};
    int n=8;
    // printf("%d",LIS(nums,n));
    return 0;
}
