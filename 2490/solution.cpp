class Solution {
public:
    bool isCircularSentence(string sentence) {
        int next, current = 0;
        int size = sentence.size();
        char first, last;
        if( size < 2 ) {
            return true;
        }

        if( sentence[0] != sentence[ size - 1 ] ) {
            return false;
        }

        while( current != string::npos ) {
            next = sentence.find(' ', current);
            if( next != string::npos ) {
                if( sentence[ next - 1 ] != sentence[ next + 1 ] ) {
                    return false;
                }
            } else {
                return true;
            }
            current = next + 1;
        }
        return true;
    }
};
