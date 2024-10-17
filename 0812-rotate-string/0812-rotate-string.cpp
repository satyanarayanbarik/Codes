/* 
class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.size() != goal.size()) return false;
        queue<char> q1,q2 ;

        for(int i = 0 ; i < q1.size() ; i++){
            q1.push(s[i]);
        }
        for(int i = 0 ; i < q2.size() ; i++){
            q2.push(goal[i]);
        }

        int k = goal.size() - 1;

        while(k!=0){

            
            char ch = q2.front();
            q2.pop();
            q2.push(ch);

            if(q1 == q2) return true;

            k-- ;

        }
        return false;
    }
};
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;  // If sizes differ, they can't be rotations

        queue<char> q1, q2;

        // Initialize q1 with string s and q2 with string goal
        for(int i = 0 ; i < s.size(); i++){
            q1.push(s[i]);
        }
        for(int i = 0 ; i < goal.size(); i++){
            q2.push(goal[i]);
        }

        int k = goal.size();  // Perform goal.size() rotations

        while(k-- > 0){  // Try rotating goal.size() times
            if(q1 == q2) return true;  // Check if the queues are equal after each rotation

            char ch = q2.front();  // Rotate q2 by moving the front element to the back
            q2.pop();
            q2.push(ch);
        }

        return false;  // If no match found after all rotations
    }
};
