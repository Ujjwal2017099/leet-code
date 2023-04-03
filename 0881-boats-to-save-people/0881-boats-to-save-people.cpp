class Solution {
public:
    int numRescueBoats(vector<int> people, int limit) {
        sort(people.begin(),people.end());
        int count_boat = 0,people_count = 0;
        int i = 0;
        int j = people.size() - 1;
        
        vector<int> remaining;
        
        while(people_count < people.size())
        {
            if(people[i] + people[j] <= limit)
            {
                count_boat++;
                people_count += 2;
                i++;
                j--;
            }
            else
            {
                remaining.push_back(j);
                j--;
            }
            if(i > j) break;
            if(i == j){remaining.push_back(i); break;}
        }
        if(remaining.size() == 0)
        {
            return count_boat;
        }
        else
        {
            count_boat += remaining.size();
            return count_boat;
        }
    }
};