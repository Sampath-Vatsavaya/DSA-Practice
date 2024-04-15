class Queue:

    def __init__(self) -> None:
        self.max=100
        self.arr=[None]*self.max
        self.front=0
        self.rear=-1
    
    def enqueue(self,x:int):
        if(self.rear== self.max-1):
            print("Queue is full")
        else:
            self.rear+=1
            self.arr[self.rear]=x
    
    def dequeue(self):
        self.front+=1
        if self.front>self.rear:
            self.front =0
            self.rear=-1
    
    def printer(self):
        temp=self.front
        while(temp<=self.rear):
            print(self.arr[temp])
            temp+=1

if __name__=="__main__":
    q= Queue()
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.printer()
    q.dequeue()
    q.printer()
