class TreeNode:
    def __init__(self,name,designation) -> None:
        self.name=name
        self.designation=designation
        self.children=[]
        self.parent=None
    
    def add_child(self,child):
        self.children.append(child)
        child.parent=self
    def get_level(self):
        level=0
        p=self.parent
        while p:
            level+=1
            p=p.parent
        return level
    def print_tree(self,type):
        spaces=' '*self.get_level()*3
        prefix=spaces+"|__" if self.parent else ""
        if(type=="name"):
            print(prefix+self.name)
        elif(type=="designation"):
            print(prefix+self.designation)
        else:
            print(prefix+self.name+self.designation)
        if self.children:
            for child in self.children:
                child.print_tree(type)
    

def tree_builder():
    root = TreeNode("Nilupul","CEO")
    
    cto = TreeNode("Chinmay","CTO")
    root.add_child(cto)
    ih=TreeNode("Vishwa","IH")
    cto.add_child(ih)
    ih.add_child(TreeNode("Dhaval","CM"))
    ih.add_child(TreeNode("Abhijit","AM"))

    ah=TreeNode("Aamir","AH")
    cto.add_child(ah)

    hr = TreeNode("Gels","HR Head")
    root.add_child(hr)
    hr.add_child(TreeNode("Peter","Recruitment Manager"))
    hr.add_child(TreeNode("Waqas","Policy Manager"))
  

    return root
                
if __name__=="__main__":
    root_node = tree_builder()
    root_node.print_tree("name") # prints only name hierarchy
    root_node.print_tree("designation") # prints only designation hierarchy
    root_node.print_tree("both") # prints both (name and designation) hierarchy