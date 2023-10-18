class BSTNode:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None
    
    def add_child(self,data):
        if self.data==data:
            return
        if data<self.data:
            if self.left:
                self.left.add_child(data)
            else:
                self.left= BSTNode(data)
        else:
            if self.right:
                self.right.add_child(data)
            else:
                self.right=BSTNode(data)
    
    def search(self,data) -> bool:
        if self.data==data:
            return True
        
        if self.data<data:
            if self.left:
                return self.left.search(data)
            else:
                return False
        else:
            if self.right:
                return self.right.search(data)
            else:
                return False
            



    def preorder_traversal(self):
        elements=[]
        elements.append(self.data)
        if self.left:
            elements+= self.left.preorder_traversal()
        
        

        if self.right:
            elements+= self.right.preorder_traversal()
        
        return elements
    
    def inorder_traversal(self):
        elements=[]
        if self.left:
            elements+= self.left.inorder_traversal()
        
        elements.append(self.data)

        if self.right:
            elements+= self.right.inorder_traversal()

        return elements
    def postorder_traversal(self):
        elements=[]
        if self.left:
            elements+= self.left.postorder_traversal()
        
        

        if self.right:
            elements+= self.right.postorder_traversal()
        elements.append(self.data)
        return elements
    
    #sum
    def calculate_sum(self):
        sum_=0
        if self.left:
            sum_+= self.left.calculate_sum()
        
        sum_+=self.data

        if self.right:
            sum_+= self.right.calculate_sum()

        return sum_
    #maximum
    def find_max(self):
        if self.right is None:
            return self.data
        return self.right.find_max()
    
    def find_min(self):
        if self.left is None:
            return self.data
        return self.left.find_min()
    














def tree_builder(elements):
    root= BSTNode(elements[0])
    for i in range(1,len(elements)):
        root.add_child(elements[i])
    return root


if __name__ == '__main__':
    numbers_tree = tree_builder([17, 4, 1, 20, 9, 23, 18, 34])
    
    print(numbers_tree.inorder_traversal())
    print(numbers_tree.preorder_traversal())
    print(numbers_tree.postorder_traversal())
    print(numbers_tree.calculate_sum())
    print(numbers_tree.find_min())
    print(numbers_tree.find_max())