class Solution {
public:
    double PI = acos(-1.0);

    int visiblePoints(vector<vector<int>>& points, int angle,
                      vector<int>& location) {
        int ans = 0;
        vector<double> point_angles;

        for (auto p : points) {
            if (p[0] == location[0] && p[1] == location[1]) {
                ans++;
            } else {
                int dx = p[0] - location[0];
                int dy = p[1] - location[1];

                double angle = atan2(dy, dx);
                double angle1 = angle * (180) / PI;
                point_angles.push_back(angle1);
            }
        }

        sort(point_angles.begin(), point_angles.end());
        int n = point_angles.size();

        for (int i = 0; i < n; i++) {
            point_angles.push_back(point_angles[i] + 360);
        }

        int start = 0, cnt = 0;
        for (int i = 0; i < point_angles.size(); i++) {
            if (point_angles[i] - point_angles[start] > angle) {
                start++;
            }
            cnt = max(cnt, i - start + 1);
        }

        ans += cnt;

        return ans;
    }
};
