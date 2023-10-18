class Stack:
    
    def __init__(self) -> None:
        self.top=-1
        self.max_size=100
        self.arr=[0]*self.max_size
    
    def push(self,x:int):
        self.top+=1
        self.arr[self.top]=x
    
    def pop(self) ->int:
        x=self.arr[self.top]
        self.top-=1
        return x
    
    def Top(self)->int:
        return self.arr[self.top]

    def size(self)->int:
        return self.top+1
    
    def printer(self):
        self.itr=self.top
        while self.itr>=0:
            print(self.arr[self.itr])
            self.itr-=1
        

if __name__=="__main__":
    s= Stack()
    s.push(500)
    s.push(400)
    s.push(300)
    s.push(200)
    s.push(100)

    s.printer()