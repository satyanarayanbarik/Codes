/*class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i=0;i < n;i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    int calculateTotalHours(vector<int>& piles, int hourly){
        int totalHours = 0;
        int n = piles.size();
        for(int i = 0; i<n ; i++){
            //totalHours += ceil((double)piles[i]/(double)hourly);
            //totalHours += (piles[i] + hourly - 1) / hourly;
            totalHours += (piles[i] + hourly - 1) / hourly;

        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low  = 1,high = findMax(piles);

        while(low<=high){
            int mid = low + (high - low )/2;
            int totalHours = calculateTotalHours(piles,mid);
            if(totalHours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
}; */
class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int>& piles, int hourly) { // Change return type to long long
        long long totalHours = 0; // Change to long long
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            totalHours += (piles[i] + hourly - 1) / hourly;  // This should now safely add up without overflow
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while (low <= high) {
            long long mid = low + (high - low) / 2; // Keep mid as long long
            long long totalHours = calculateTotalHours(piles, mid); // Ensure totalHours is long long
            if (totalHours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
