class Solution {
public:
    string reverseWords(string s) {
        auto word_begin = s.begin();
        while (true) {
            auto word_end = find(word_begin, s.end(), ' ');
            std::reverse(word_begin, word_end);
            if (word_end == s.end()) break;
            word_begin = word_end +1;
        }
        return s;
    }
};