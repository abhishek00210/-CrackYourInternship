class Solution {
    static constexpr int K = 10001;
    int* ranks;
    int* repr;

    inline int dsuFind(int x) {
        if (x != repr[x]) {
            repr[x] = dsuFind(repr[x]);
        }
        return repr[x];
    }
    inline int dsuUnion(int x, int y) {
        x = dsuFind(x);
        y = dsuFind(y);

        if (x == y) {
            return 0;
        }
        if (ranks[x] >= ranks[y]) {
            repr[y] = x;
        } else if (ranks[x] < ranks[y]) {
            repr[x] = y;
        }
        if (ranks[x] == ranks[y]) {
            ++ranks[x];
        }
        return 1;
    }
public:
    int removeStones(const vector<vector<int>>& stones) {
        ranks = new int[K * 2];
        repr = new int[K * 2];

        int componentCount = 0;
        vector<bool> marked(K * 2);
        for (const auto& stone : stones) {
            if (!marked[stone[0]]) {
                ++componentCount;
                marked[stone[0]] = true;
                repr[stone[0]] = stone[0];
                ranks[stone[0]] = 1;
            }
            if (!marked[stone[1] + K]) {
                ++componentCount;
                marked[stone[1] + K] = true;
                repr[stone[1] + K] = stone[1] + K;
                ranks[stone[1] + K] = 1;
            }
            componentCount -= dsuUnion(stone[0], stone[1] + K);
        }
        delete[] ranks;
        delete[] repr;
        return stones.size() - componentCount;
    }
};