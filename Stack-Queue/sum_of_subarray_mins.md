
# 🚀 Sum of Subarray Minimums — Monotonic Stack (C++ Solution)

This solution efficiently computes the sum of the minimum element of every subarray of the array using **monotonic stacks** in `O(n)` time.

## 🔍 Problem Recap

Given an array `arr[]`, find the sum of the minimum value of every subarray, modulo `1e9 + 7`.

## 💡 Key Observations

For every index `i` where `arr[i]` is the minimum in a subarray:
- Count the number of subarrays for which `arr[i]` is the **minimum**.
- Calculate contribution: 
  ```
  arr[i] * (# subarrays extending left) * (# subarrays extending right)
  ```

## 🧠 Approach: Next and Previous Smaller Indices

We compute:

1. **NSI (Next Smaller index)**: First element to the right that is strictly smaller than `arr[i]`
2. **PSI (Previous Smaller index)**: Last element to the left that is smaller or equal to `arr[i]`

These bounds help us determine how many subarrays have `arr[i]` as the minimum.

---

## 🧑‍💻 C++ Code

```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans = 0;
        vector<int> nsi(arr.size(), arr.size());  // Next Smaller Index
        vector<int> psi(arr.size(), -1);          // Previous Smaller Index
        stack<int> st;

        // Find Next Smaller Index (strictly smaller)
        for(int i = arr.size() - 1; i >= 0; i--) {
            while(st.size() && arr[st.top()] > arr[i]) st.pop();
            if(st.size()) nsi[i] = st.top();
            st.push(i);
        }

        // Clear the stack
        while(st.size()) st.pop();

        // Find Previous Smaller Index (smaller or equal)
        for(int i = 0; i < arr.size(); i++) {
            while(st.size() && arr[st.top()] >= arr[i]) st.pop();
            if(st.size()) psi[i] = st.top();
            st.push(i);
        }

        // Compute answer
        const int mod = 1e9 + 7;
        for(int i = 0; i < arr.size(); i++) {
            // #choices to the left = i - psi[i]
            // #choices to the right = nsi[i] - i
            ans = (ans + 1LL * arr[i] * (i - psi[i]) * (nsi[i] - i)) % mod;
        }

        return ans;
    }
};
```

---

## 🧾 Explanation Summary

- We use two monotonic stacks to compute nearest smaller values in linear time.
- `NSI` tells us how far right we can go before we see a smaller element.
- `PSI` tells us how far left we can go while `arr[i]` is the smallest.
- Finally, each element `arr[i]` contributes:
  ```
  arr[i] * (i - PSI[i]) * (NSI[i] - i)
  ```
- Modular arithmetic is used to keep the result within bounds.

---

Feel free to tweak variable names or add custom test cases for deeper understanding!
