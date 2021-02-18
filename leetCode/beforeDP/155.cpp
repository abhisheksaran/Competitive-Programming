class MinStack {
public:
    /** initialize your data structure here. */
    long minEle;
    stack<long>s;
    MinStack() {    
        
    }
   //if x is lesser than minEle push 2*x-minEle on stack which would be lesser than x  
   // so next time when you pop if you see top of the stack is les than minEle that means that top of the stack would be next minEle after pop operation
    void push(int x) {
        if(s.empty()){
            s.push(x);
            minEle=x;
        }
        else if(x<minEle){
            s.push(2*((long)x)-minEle);
            minEle=x;
        }            
        else s.push(x);
    }

    void pop() {
        if(s.top()<minEle){
            minEle=2*minEle-s.top();
        }
        s.pop();
        
    }
    
    int top() {
        if(s.top()<minEle){
            return minEle;
        }
        return s.top();
        
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
