class BSTNode:
    def __init__(self,data) :
        self.data=data
        self.left=None
        self.right=None
    def add_child(self,data):
        if self.data==data:
            return
        if self.data>data:
            if self.left:
                self.left.add_child(data)
            else:
                self.left=BSTNode(data)
        else:
            if self.right:
                self.right.add_child(data)
            else:
                self.right=BSTNode(data)
    
    # Deleting a node(using the minimum of right subtree)
    def delete_node(self,val):
        if val<self.data:
            if self.left:
                self.left=self.left.delete_node(val)
        elif val>self.data:
            if self.right:
                self.right=self.right.delete_node(val)
        else:
            if self.left is None and self.right is None:
                return None
            elif self.left is None:
                return self.right
            elif self.right is None:
                return self.left
            min_val=self.right.find_min()
            self.data=min_val
            self.right=self.right.delete_node(min_val)
        return self
    def find_min(self):
        if self.left is None:
            return self.data
        return self.left.find_min()
    
    def inorder_traversal(self):
        elements=[]
        if self.left:
            elements+= self.left.inorder_traversal()
        
        elements.append(self.data)

        if self.right:
            elements+= self.right.inorder_traversal()

        return elements
    

def build_tree(elements):
    print("Building tree with these elements:",elements)
    root = BSTNode(elements[0])

    for i in range(1,len(elements)):
        root.add_child(elements[i])

    return root

if __name__ == '__main__':
    numbers_tree = build_tree([17, 4, 1, 20, 9, 23, 18, 34])
    numbers_tree.delete_node(20)
    print("After deleting 20\n ",numbers_tree.inorder_traversal()) # this should print [1, 4, 9, 17, 18, 23, 34]

    numbers_tree = build_tree([17, 4, 1, 20, 9, 23, 18, 34])
    numbers_tree.delete_node(9)
    print("After deleting 9 \n",numbers_tree.inorder_traversal())  # this should print [1, 4, 17, 18, 20, 23, 34]

    numbers_tree = build_tree([17, 4, 1, 20, 9, 23, 18, 34])
    numbers_tree.delete_node(17)
    print("After deleting 17\n ",numbers_tree.inorder_traversal())  # this should print [1, 4, 9, 18, 20, 23, 34]