#Find index of all occurances of a number from sorted list
def binary_search(elements,key):

    start=0
    end=len(elements)-1
    mid= end +(start-end)//2
    while start<=end:
        if elements[mid]==key:
            return mid
        elif elements[mid]<key:
            start=mid+1
        else:
            end=mid-1
        mid= end+(start-end)//2
    return -1
def find_all_occurences(elements,key):
    index=binary_search(elements,key)
    indices=[index]
    #now we have one index of the occurence
    #append all indices on the left side that has the key
    i=index-1
    while i>=0:
        if elements[i]==key:
            indices.append(i)
        else:
            break
        i=i-1
    #append all indices on the right side that has the key
    i=index+1
    while i<len(elements):
        if elements[i]==key:
            indices.append(i)
        else:
            break
        i=i+1

    return sorted(indices)
if __name__=="__main__":
    numbers=[1,4,6,9,11,15,15,15,17,21,34,34,56]
    number_to_find=15
    pos=find_all_occurences(numbers,number_to_find)
    print(pos)
    
    