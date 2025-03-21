class Solution {
public:
bool allAvailable(const vector<string>& ingredients, unordered_set<string>& available) {
        for (const string& ing : ingredients) {
            if (available.find(ing) == available.end()) return false;
        }
        return true;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies){
        int n = recipes.size();
        int m = supplies.size();
        map<string,vector<string>> mpp;
         unordered_map<string, int> inDegree; 
        unordered_set<string> x(supplies.begin(), supplies.end()); 
        vector<string> res;
        for(int i = 0;i<n;i++){
            mpp[recipes[i]] = ingredients[i];
            inDegree[recipes[i]] = ingredients.size();
        }
        queue<string> q;
        for(int i = 0;i<n;i++){
            if(inDegree[recipes[i]]==0 || allAvailable(ingredients[i],x)){
                q.push(recipes[i]);
                x.insert(recipes[i]);
            }
        }
        while(!q.empty()) {
            string recipe = q.front();
            q.pop();
            res.push_back(recipe);
            for(auto& [nextRecipe,ing] : mpp){
                if(x.find(nextRecipe)!=x.end())
                continue;
                if(inDegree[nextRecipe]==0 || allAvailable(ing,x)){
                q.push(nextRecipe);
                inDegree[nextRecipe]--;
                x.insert(nextRecipe);
                }
            }
        }
        return res;
    }
};