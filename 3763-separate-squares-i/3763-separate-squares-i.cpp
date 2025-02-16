class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
       vector<int> y_vals;
        vector<tuple<long long int, long long int, long long int>> square_data;
        for (auto& square : squares) {
            int x = square[0];
            int y = square[1];
            int len = square[2];
            y_vals.push_back(y);
            y_vals.push_back(y + len);
            square_data.push_back({x, y, len});
        }
        sort(y_vals.begin(), y_vals.end());
        y_vals.erase(unique(y_vals.begin(), y_vals.end()), y_vals.end());
        long double total_area = 0;
        for (auto& [x, y, len] : square_data) {
            total_area += len * len;
        }
        double left = y_vals[0], right = y_vals.back();
        while (right - left > 1e-5) {
            double mid = (left + right) / 2.0;
            double above = 0, below = 0;
            for (auto& [x, y, len] : square_data) {
                double top = y + len;
                if (top <= mid) {
                    below += len * len;
                } else if (y >= mid) {
                    above += len * len;
                } else {
                    double above_part = (top - mid) * len;
                    double below_part = (mid - y) * len;
                    above += above_part;
                    below += below_part;
                }
            }

            if (above > below) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return left;
    }
};