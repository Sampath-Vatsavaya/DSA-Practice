from collections import deque
class Queue:

    def __init__(self) -> None:
        self.buffer=deque()

    def enqueue(self,x:int):
        self.buffer.appendleft(x)
    
    def dequeue(self):
        self.buffer.pop()

    def is_empty(self):
        return len(self.buffer)==0
    
    def size(self):
        return len(self.buffer)
    
if __name__=="__main__":
    q= Queue()
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    print(q.buffer)
    q.dequeue()
    print(q.buffer)