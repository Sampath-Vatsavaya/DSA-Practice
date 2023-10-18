from collections import deque

class Stack:
    def __init__(self):
        self.container=deque()
    
    def push(self,x:int):
        self.container.append(x)
    
    def pop(self):
        self.container.pop()
    
    def peek(self):
        return self.container[-1]
    
    def is_empty(self):
        return len(self.container)==0
    def size(self):
        return len(self.container)
    
if __name__=="__main__":
    s= Stack()
    s.push(30)
    s.push(20)
    s.push(10)
    print(s.peek())
    s.pop()
    print(s.peek())
    s.pop()
    print(s.peek())