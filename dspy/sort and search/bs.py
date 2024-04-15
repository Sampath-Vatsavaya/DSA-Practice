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
def binary_search_recursive(elements,start,end,key):
    mid= end+(start-end)//2
    if elements[mid]==key:
        return mid
    elif elements[mid]<key:
        return binary_search_recursive(elements,mid+1,end,key)
    else:
        return binary_search_recursive(elements,start,mid-1,key)
    return -1

if __name__=="__main__":
    ele=[1,4,3,2,6,7,8,9,10,5]
    ele.sort()
    pos=binary_search(ele,5)
    print(pos+1)
    posr=binary_search_recursive(ele,0,len(ele)-1,10)
    print(posr+1)
    