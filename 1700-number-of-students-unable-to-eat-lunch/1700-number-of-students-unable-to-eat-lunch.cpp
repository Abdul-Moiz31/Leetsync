class Solution {
public:
    int countStudents(vector<int>& Stu, vector<int>& Sw) {
        queue<int> StuQ;
        stack<int> sandS;

        for (int s : Stu) {
            StuQ.push(s);
        }
        for (int i = Sw.size() - 1; i >= 0; i--) {
            sandS.push(Sw[i]);
        }

        int cnt = 0;
        int n = Stu.size();
        while (!StuQ.empty() && !sandS.empty()) {
            if (StuQ.front() == sandS.top()) {
                StuQ.pop();
                sandS.pop();
                cnt = 0;
            } else {
                StuQ.push(StuQ.front());
                StuQ.pop();
                cnt++;
            }
            if (cnt == n){ 
            break; 
          }
        }
        return StuQ.size();
    }
};