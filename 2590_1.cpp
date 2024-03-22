
class TodoList {
    class Task{
    public:
        int dueDate;
        set<string>tags;
        string taskDescription;
    };
    int curTaskId = 0;
    unordered_map<int,Task>mp;
    unordered_map<int,set<int>>userTasks;
public:
    TodoList() {
        
    }
    
    int addTask(int userId, string taskDescription, int dueDate, vector<string> tags) {
        curTaskId++;
        Task t;
        t.dueDate = dueDate;
        for (auto i:tags)
            t.tags.insert(i);
        t.taskDescription = taskDescription;
        mp[curTaskId] =  t;
        userTasks[userId].insert(curTaskId);
        return curTaskId;
    }
    
    vector<string> getAllTasks(int userId) {
        vector<pair<int,string>>v;
        for (auto idx:userTasks[userId]){
            v.push_back({mp[idx].dueDate,mp[idx].taskDescription});
        }
        sort(v.begin(),v.end());
        vector<string>ret_vec;
        for (auto i:v)
            ret_vec.push_back(i.second);
        return ret_vec; 

    }
   

   
    
    vector<string> getTasksForTag(int userId, string tag) {

        vector<pair<int,string>>v;
        for (auto idx:userTasks[userId]){
            if(mp[idx].tags.contains(tag))
            v.push_back({mp[idx].dueDate,mp[idx].taskDescription});
        }
        sort(v.begin(),v.end());
        vector<string>ret_vec;
        for (auto i:v)
            ret_vec.push_back(i.second);
        return ret_vec; 
        
    }
    
    void completeTask(int userId, int taskId) {
        if(userTasks.contains(userId )&& userTasks[userId].contains(taskId)){
            userTasks[userId].erase(taskId);
            mp.erase(taskId); 
        }
            
        

    }
};

/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList* obj = new TodoList();
 * int param_1 = obj->addTask(userId,taskDescription,dueDate,tags);
 * vector<string> param_2 = obj->getAllTasks(userId);
 * vector<string> param_3 = obj->getTasksForTag(userId,tag);
 * obj->completeTask(userId,taskId);
 */
