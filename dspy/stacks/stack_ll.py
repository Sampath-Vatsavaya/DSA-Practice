class LinkedListNode:

    def __init__(self,data:None) -> None:
        self.data=data
        self.next=None
    
class Stack:
    
    def __init__(self) -> None:
        self.head= LinkedListNode(None)

    
    def push(self,x:int):
        node= LinkedListNode(x)
        if self.head is None:
            self.head=node
        else:
            node.next=self.head
            self.head=node
    
    def pop(self):

        if self.head is None:
            print("The Stack is Empty")
        else:
            self.temp=self.head
            self.head=self.head.next
            self.temp.next=None
    
    def top(self)->int:
        return self.head.data
    
    
if __name__=="__main__":
    s= Stack()
    s.push(30)
    s.push(20)
    s.push(10)
    print(s.top())
    s.pop()
    print(s.top())
    s.pop()
    print(s.top())

    



    