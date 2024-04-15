class LinkedListNode:
    def __init__(self,data) -> None:
        self.data=data
        self.next=None

class Queue:
    def __init__(self) -> None:
        self.head=LinkedListNode(None)

    
    def enqueue(self,x:int):
        node= LinkedListNode(x)
        if(self.head is None):
            self.head=node
        else:
            temp=self.head
            while(temp.next):
                temp=temp.next
            temp.next=node
        
    
    def dequeue(self):
        self.temp=self.head
        self.head=self.head.next
        self.temp.next=None

    
    def printer(self):
        temp=self.head
        while(temp):
            print(temp.data)
            temp=temp.next
        
if __name__=="__main__":
    q= Queue()
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.printer()
    q.dequeue()
    q.printer()

        
