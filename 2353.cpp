class FoodRatings {
public:
    static constexpr auto func  = [](const std::pair<string,int>& p1, const std::pair<string,int>& p2){
        //if(p1.second<p2.second)return true; else return false;
        
        if(p1.second<p2.second){
            return true;
        }
        else if(p1.second == p2.second && p1.first>p2.first){
           return true; 
        }
        else 
        return false;
    };
    std::unordered_map<string,std::set<pair<string,int>,decltype(func)>>cmp ; //cuisine, food, rating
    std::unordered_map<string,string>foodCu;//food,cuisine
    std::unordered_map<string,int>foodRa;//food, current rating

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i=0;i<n;i++){
            if(foodCu.contains(foods[i])){
                changeRating(foods[i],ratings[i]);
            }
            else{
                
            foodCu[foods[i]] = cuisines[i];
            foodRa[foods[i]] = ratings[i];
            cmp[cuisines[i]].insert({foods[i],ratings[i]});
            }
            
        }    
    }
    
    void changeRating(string food, int newRating) {
        string curCu = foodCu[food];
        int curRa = foodRa[food];
        auto it = cmp[curCu].find({food,curRa});    
        cmp[curCu].erase(it);
        cmp[curCu].insert({food,newRating});
        foodRa[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto& st = cmp[cuisine];
        return prev(st.end())->first;
        
    }
    
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
