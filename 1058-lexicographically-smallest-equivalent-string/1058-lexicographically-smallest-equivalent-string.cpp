class DSU {
public:
    std::map<char, char> parent;
    std::map<char, int> rank; // Optional: for optimization (union by rank)

    // Constructor: Initializes a DSU for a set of characters
    DSU(const std::set<char>& chars) {
        for (char c : chars) {
            parent[c] = c; // Each character is initially its own parent
            rank[c] = 0;
        }
    }

    // Find operation with path compression
    char find(char i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Union operation by rank
    void unite(char i, char j) {
        char root_i = find(i);
        char root_j = find(j);

        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
        }
    }
};
class Solution {
public:
std::map<char, char> buildSmallestEquivalentMap(const std::string& s1, const std::string& s2) {
        std::set<char> all_chars;
        for (char c : s1) all_chars.insert(c);
        for (char c : s2) all_chars.insert(c);
        // Also add characters from 'a' to 'z' to handle potential baseStr characters not in s1/s2
        // Although the problem statement implies baseStr characters are covered,
        // it's safer for a general solution if not all chars are in s1/s2
        for (char c = 'a'; c <= 'z'; ++c) {
            all_chars.insert(c);
        }

        DSU dsu(all_chars);

        for (size_t i = 0; i < s1.length(); ++i) {
            dsu.unite(s1[i], s2[i]);
        }

        // Group into equivalence classes first (using representatives as keys)
        std::map<char, std::set<char>> equivalence_classes_by_root;
        for (char c : all_chars) {
            char representative = dsu.find(c);
            equivalence_classes_by_root[representative].insert(c);
        }

        // Now, create the final map: char -> smallest char in its class
        std::map<char, char> smallest_equivalent_char_map;
        for (char c : all_chars) {
            char representative = dsu.find(c);
            const std::set<char>& eq_set = equivalence_classes_by_root[representative];
            smallest_equivalent_char_map[c] = findSmallestChar(eq_set);
        }

        return smallest_equivalent_char_map;
    }
char findSmallestChar(const std::set<char>& charSet) {
    char smallest = std::numeric_limits<char>::max(); 

    for (char c : charSet) {
        if (c < smallest) {
            smallest = c;
        }
    }
    return smallest;
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        std::map<char, char> smallest_eq_map = buildSmallestEquivalentMap(s1, s2);

        std::string ans = "";
        for (char c : baseStr) {
            
            ans += smallest_eq_map[c];
        }
        return ans;
    }
};