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
            
    def inorder_traversal(self):
        elements=[]
        if self.left:
            elements+= self.left.inorder_traversal()
        
        elements.append(self.data)

        if self.right:
            elements+= self.right.inorder_traversal()

        return elements
    
def tree_builder(elements):
    root= BSTNode(elements[0])
    for i in range(1,len(elements)):
        root.add_child(elements[i])
    return root


if __name__ == '__main__':
    countries = ["India","Pakistan","Germany", "USA","China","India","UK","USA"]
    country_tree = tree_builder(countries)
    print(country_tree.inorder_traversal())
    print("UK is in the list? ", country_tree.search("UK"))
    print("Sweden is in the list? ", country_tree.search("Sweden"))
    print()
    numbers_tree = tree_builder([17, 4, 1, 20, 9, 23, 18, 34])
    print(numbers_tree.inorder_traversal())
    print("In order traversal gives this sorted list:",numbers_tree.inorder_traversal())
    #print(numbers_tree.inorder_traversal())