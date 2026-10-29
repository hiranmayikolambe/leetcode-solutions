class Solution {
public:
    int compress(vector<char>& chars) {
        const int n = chars.size();
        int write = 0, read = 0;

        while (read < n) {
            const char c = chars[read];
            int start = read;
            while (read < n && chars[read] == c) ++read;

            chars[write++] = c;
            const int count = read - start;
            if (count > 1) {
                for (char d : to_string(count))
                    chars[write++] = d;
            }
        }
        return write;
    }
};