/*
LeetCode 735 — Asteroid Collision
https://leetcode.com/problems/asteroid-collision/

Approach:
- Use a stack to simulate collisions.
- Only collide when stack.top() > 0 and current asteroid < 0.
- Resolve collisions using size comparison.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool alive = true;

            // Collision only when stack top moves right and current moves left
            while (!st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop();  // stack top explodes, keep checking
                }
                else if (abs(st.top()) == abs(a)) {
                    st.pop();  // both explode
                    alive = false;
                    break;
                }
                else {
                    // stack top is bigger, current asteroid explodes
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push(a);
            }
        }

        // Convert stack to vector (reverse order)
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> asteroids = {5, 10, -5};
    vector<int> result = sol.asteroidCollision(asteroids);

    cout << "Final Note: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity: O(n)
- Each asteroid is pushed and popped at most once.

Space Complexity: O(n)
- Stack can hold all asteroids in worst case.
*/
