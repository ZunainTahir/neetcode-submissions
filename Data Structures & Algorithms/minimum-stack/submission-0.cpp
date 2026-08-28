class MinStack {
private:
    stack<int> mainstack;
    stack<int> minstack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        mainstack.push(val);
        if(minstack.empty()){
            minstack.push(val);
        }
        else{
            minstack.push(min(minstack.top(), val));
        }
    }
    
    void pop() {
        minstack.pop();
        mainstack.pop();
    }
    
    int top() {
        return mainstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
